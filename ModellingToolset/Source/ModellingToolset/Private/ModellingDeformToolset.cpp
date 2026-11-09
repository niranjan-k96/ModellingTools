// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingDeformToolset.h"

#include "ModellingToolsetUtils.h"

#include "DynamicMesh/DynamicMesh3.h"
#include "GeometryScript/MeshDeformFunctions.h"
#include "GeometryScript/MeshSubdivideFunctions.h"
#include "Math/RotationMatrix.h"
#include "UDynamicMesh.h"

using namespace ModellingToolset;
using Deform = UGeometryScriptLibrary_MeshDeformFunctions;

namespace
{
	constexpr int64 MaxResultTriangles = 2000000;

	/**
	 * Frame whose Z axis is the given axis and whose X axis is as close as possible to Direction, positioned at Origin.
	 * An explicit X axis matters: with only a Z axis, Unreal picks X arbitrarily, so warps would bend or widen in a surprising direction.
	 */
	FTransform MakeAxisFrame(const FVector& Axis, const FVector& Origin, FVector Direction = FVector(1, 0, 0))
	{
		const FVector Z = Axis.GetSafeNormal();
		Direction = (Direction - Z * FVector::DotProduct(Direction, Z));
		if (Direction.IsNearlyZero())
		{
			// Direction was parallel to the axis: pick any perpendicular.
			Direction = FMath::Abs(Z.Z) < 0.9 ? FVector::CrossProduct(Z, FVector(0, 0, 1)) : FVector::CrossProduct(Z, FVector(1, 0, 0));
		}
		return FTransform(FRotationMatrix::MakeFromZX(Z, Direction.GetSafeNormal()).ToQuat(), Origin);
	}

	bool CheckAxis(const FVector& Axis)
	{
		if (Axis.IsNearlyZero())
		{
			Fail(TEXT("Axis must not be zero."));
			return false;
		}
		return true;
	}
}

FString UModellingDeformToolset::Bend(const FString& Name, float AngleDegrees, float Extent, const FVector& Axis, const FVector& Origin, const FVector& BendDirection)
{
	if (!CheckAxis(Axis))
	{
		return FString();
	}
	if (Extent <= 0.f)
	{
		Fail(TEXT("Extent must be greater than 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Bend"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptBendWarpOptions Options;
	Options.bSymmetricExtents = true;
	Options.bBidirectional = true;
	// Geometry Script bends toward the frame's +Y axis. We want the caller's BendDirection, so build the frame with
	// X = BendDirection x Axis (then frame Y = Axis x X = BendDirection). Verified by the ModellingToolset.Directions test.
	FVector FrameX = FVector::CrossProduct(BendDirection, Axis.GetSafeNormal());
	if (FrameX.IsNearlyZero())
	{
		FrameX = FVector(1, 0, 0); // BendDirection was parallel to the axis; MakeAxisFrame picks a valid perpendicular
	}
	Deform::ApplyBendWarpToMesh(Scope.Mesh, Options, MakeAxisFrame(Axis, Origin, FrameX), AngleDegrees, Extent);
	return Scope.Result();
}

FString UModellingDeformToolset::Twist(const FString& Name, float AngleDegrees, float Extent, const FVector& Axis, const FVector& Origin)
{
	if (!CheckAxis(Axis))
	{
		return FString();
	}
	if (Extent <= 0.f)
	{
		Fail(TEXT("Extent must be greater than 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Twist"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptTwistWarpOptions Options;
	Options.bSymmetricExtents = true;
	Options.bBidirectional = true;
	Deform::ApplyTwistWarpToMesh(Scope.Mesh, Options, MakeAxisFrame(Axis, Origin), AngleDegrees, Extent);
	return Scope.Result();
}

FString UModellingDeformToolset::Flare(const FString& Name, float FlareX, float FlareY, float Extent, const FVector& Axis, const FVector& Origin)
{
	if (!CheckAxis(Axis))
	{
		return FString();
	}
	if (Extent <= 0.f)
	{
		Fail(TEXT("Extent must be greater than 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Flare"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptFlareWarpOptions Options;
	Options.bSymmetricExtents = true;
	Deform::ApplyFlareWarpToMesh(Scope.Mesh, Options, MakeAxisFrame(Axis, Origin), FlareX, FlareY, Extent);
	return Scope.Result();
}

FString UModellingDeformToolset::Noise(const FString& Name, float Magnitude, float Frequency, int32 Seed, const FModellingSelection& Selection)
{
	if (Magnitude <= 0.f || Frequency <= 0.f)
	{
		Fail(TEXT("Magnitude and Frequency must be greater than 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Noise"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}

	FGeometryScriptPerlinNoiseOptions Options;
	Options.BaseLayer.Magnitude = Magnitude;
	Options.BaseLayer.Frequency = Frequency;
	Options.BaseLayer.RandomSeed = Seed;
	Options.bApplyAlongNormal = true;
	Deform::ApplyPerlinNoiseToMesh2(Scope.Mesh, Selected, Options);
	return Scope.Result();
}

FString UModellingDeformToolset::Smooth(const FString& Name, int32 Iterations, float Alpha, const FModellingSelection& Selection)
{
	FEditScope Scope(Name, TEXT("Smooth"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}

	FGeometryScriptIterativeMeshSmoothingOptions Options;
	Options.NumIterations = FMath::Clamp(Iterations, 1, 100);
	Options.Alpha = FMath::Clamp(Alpha, 0.f, 1.f);
	Deform::ApplyIterativeSmoothingToMesh(Scope.Mesh, Selected, Options);
	return Scope.Result();
}

FString UModellingDeformToolset::Subdivide(const FString& Name, int32 Level)
{
	Level = FMath::Clamp(Level, 1, 6);
	FEditScope Scope(Name, TEXT("Subdivide"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	int32 Triangles = 0;
	Scope.Mesh->ProcessMesh([&Triangles](const UE::Geometry::FDynamicMesh3& M) { Triangles = M.TriangleCount(); });
	const int64 Result = static_cast<int64>(Triangles) * (Level + 1) * (Level + 1);
	if (Result > MaxResultTriangles)
	{
		Fail(FString::Printf(TEXT("That would create about %lld triangles (limit %lld). Use a lower Level."), Result, MaxResultTriangles));
		return FString();
	}

	UGeometryScriptLibrary_MeshSubdivideFunctions::ApplyUniformTessellation(Scope.Mesh, Level);
	return Scope.Result();
}
