// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingPrimitivesToolset.h"

#include "ModellingToolsetUtils.h"

#include "Algo/Reverse.h"
#include "GeometryScript/MeshBasicEditFunctions.h"
#include "GeometryScript/MeshPrimitiveFunctions.h"
#include "Math/RotationMatrix.h"
#include "UDynamicMesh.h"

using namespace ModellingToolset;
using Prim = UGeometryScriptLibrary_MeshPrimitiveFunctions;

namespace
{
	// Centred origin is easier for an AI to reason about than the Geometry Script default (base).
	constexpr EGeometryScriptPrimitiveOriginMode CentredOrigin = EGeometryScriptPrimitiveOriginMode::Center;

	FGeometryScriptPrimitiveOptions MakeOptions()
	{
		FGeometryScriptPrimitiveOptions Options;
		Options.PolygroupMode = EGeometryScriptPrimitivePolygroupMode::PerFace;
		return Options;
	}

	bool CheckPositive(const TCHAR* ParamName, float Value)
	{
		if (Value <= 0.f)
		{
			Fail(FString::Printf(TEXT("%s must be greater than 0 (got %g)."), ParamName, Value));
			return false;
		}
		return true;
	}

	bool CheckNotNegative(const TCHAR* ParamName, float Value)
	{
		if (Value < 0.f)
		{
			Fail(FString::Printf(TEXT("%s must be 0 or greater (got %g)."), ParamName, Value));
			return false;
		}
		return true;
	}
}

namespace
{
	/** Counter-clockwise points, as the polygon primitives expect. Either input direction is accepted. */
	TArray<FVector2D> MakeCounterClockwise(TArray<FVector2D> Points)
	{
		double Area = 0.0;
		for (int32 i = 0; i < Points.Num(); ++i)
		{
			const FVector2D& A = Points[i];
			const FVector2D& B = Points[(i + 1) % Points.Num()];
			Area += A.X * B.Y - B.X * A.Y;
		}
		if (Area < 0.0)
		{
			Algo::Reverse(Points);
		}
		return Points;
	}

	/**
	 * Builds a shape into a scratch mesh, makes sure its faces point outward (shapes built from outlines can come out inside
	 * out depending on the outline direction), then appends it to the part with the given placement.
	 */
	template <typename BuildFn>
	void AppendOutward(UDynamicMesh* Target, const FTransform& Placement, BuildFn Build)
	{
		TStrongObjectPtr<UDynamicMesh> Scratch(NewObject<UDynamicMesh>(GetTransientPackage()));
		Build(Scratch.Get());
		EnsureFacesPointOutward(Scratch.Get());
		UGeometryScriptLibrary_MeshBasicEditFunctions::AppendMesh(Target, Scratch.Get(), Placement, /*bDeferChangeNotifications=*/false, FGeometryScriptAppendMeshOptions());
	}

	bool CheckPolygon(const TCHAR* Label, const TArray<FVector2D>& Points)
	{
		if (Points.Num() < 3)
		{
			Fail(FString::Printf(TEXT("%s needs at least 3 points."), Label));
			return false;
		}
		if (Points.Num() > 512)
		{
			Fail(FString::Printf(TEXT("%s has too many points (max 512)."), Label));
			return false;
		}
		return true;
	}
}

FString UModellingPrimitivesToolset::AddBox(const FString& Name, const FVector& Size, const FVector& Location, const FRotator& Rotation, bool bCreateIfMissing)
{
	if (!CheckPositive(TEXT("Size.X"), Size.X) || !CheckPositive(TEXT("Size.Y"), Size.Y) || !CheckPositive(TEXT("Size.Z"), Size.Z))
	{
		return FString();
	}
	FEditScope Scope(Name, TEXT("Add Box"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	Prim::AppendBox(Scope.Mesh, MakeOptions(), FTransform(Rotation, Location), Size.X, Size.Y, Size.Z, 0, 0, 0, CentredOrigin);
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddSphere(const FString& Name, float Radius, const FVector& Location, const FRotator& Rotation, int32 Segments, bool bCreateIfMissing)
{
	if (!CheckPositive(TEXT("Radius"), Radius))
	{
		return FString();
	}
	Segments = FMath::Clamp(Segments, 3, 128);
	FEditScope Scope(Name, TEXT("Add Sphere"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	Prim::AppendSphereLatLong(Scope.Mesh, MakeOptions(), FTransform(Rotation, Location), Radius, FMath::Max(Segments / 2, 2), Segments, CentredOrigin);
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddCylinder(const FString& Name, float Radius, float Height, const FVector& Location, const FRotator& Rotation, int32 Segments, bool bCapped, bool bCreateIfMissing)
{
	if (!CheckPositive(TEXT("Radius"), Radius) || !CheckPositive(TEXT("Height"), Height))
	{
		return FString();
	}
	FEditScope Scope(Name, TEXT("Add Cylinder"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	Prim::AppendCylinder(Scope.Mesh, MakeOptions(), FTransform(Rotation, Location), Radius, Height, FMath::Clamp(Segments, 3, 128), 0, bCapped, CentredOrigin);
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddCone(const FString& Name, float BaseRadius, float TopRadius, float Height, const FVector& Location, const FRotator& Rotation, int32 Segments, bool bCreateIfMissing)
{
	if (!CheckPositive(TEXT("BaseRadius"), BaseRadius) || !CheckNotNegative(TEXT("TopRadius"), TopRadius) || !CheckPositive(TEXT("Height"), Height))
	{
		return FString();
	}
	FEditScope Scope(Name, TEXT("Add Cone"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	Prim::AppendCone(Scope.Mesh, MakeOptions(), FTransform(Rotation, Location), BaseRadius, TopRadius, Height, FMath::Clamp(Segments, 3, 128), 1, true, CentredOrigin);
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddCapsule(const FString& Name, float Radius, float LineLength, const FVector& Location, const FRotator& Rotation, bool bCreateIfMissing)
{
	if (!CheckPositive(TEXT("Radius"), Radius) || !CheckNotNegative(TEXT("LineLength"), LineLength))
	{
		return FString();
	}
	FEditScope Scope(Name, TEXT("Add Capsule"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	Prim::AppendCapsule(Scope.Mesh, MakeOptions(), FTransform(Rotation, Location), Radius, LineLength, 5, 12, 0, CentredOrigin);
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddTorus(const FString& Name, float MajorRadius, float MinorRadius, const FVector& Location, const FRotator& Rotation, int32 MajorSteps, int32 MinorSteps, bool bCreateIfMissing)
{
	if (!CheckPositive(TEXT("MajorRadius"), MajorRadius) || !CheckPositive(TEXT("MinorRadius"), MinorRadius))
	{
		return FString();
	}
	FEditScope Scope(Name, TEXT("Add Torus"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	const FGeometryScriptRevolveOptions Revolve;
	Prim::AppendTorus(Scope.Mesh, MakeOptions(), FTransform(Rotation, Location), Revolve, MajorRadius, MinorRadius,
		FMath::Clamp(MajorSteps, 3, 128), FMath::Clamp(MinorSteps, 3, 64), CentredOrigin);
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddRevolve(const FString& Name, const TArray<FVector2D>& Profile, const FVector& Location, const FRotator& Rotation, float Degrees, int32 Steps, bool bCapped, bool bCreateIfMissing)
{
	if (Profile.Num() < 2)
	{
		Fail(TEXT("Profile needs at least 2 points (radius, height)."));
		return FString();
	}
	if (Profile.Num() > 512)
	{
		Fail(TEXT("Profile has too many points (max 512)."));
		return FString();
	}
	bool bAnyRadius = false;
	for (const FVector2D& P : Profile)
	{
		if (P.X < 0.0)
		{
			Fail(TEXT("Profile radius (X) must be 0 or more."));
			return FString();
		}
		bAnyRadius |= P.X > 0.0;
	}
	if (!bAnyRadius)
	{
		Fail(TEXT("Profile needs at least one point with a radius above 0."));
		return FString();
	}
	if (Degrees <= 0.f || Degrees > 360.f)
	{
		Fail(TEXT("Degrees must be above 0 and at most 360."));
		return FString();
	}

	FEditScope Scope(Name, TEXT("Add Revolve"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	FGeometryScriptRevolveOptions Revolve;
	Revolve.RevolveDegrees = Degrees;
	AppendOutward(Scope.Mesh, FTransform(Rotation, Location), [&](UDynamicMesh* Scratch)
	{
		Prim::AppendRevolvePath(Scratch, MakeOptions(), FTransform::Identity, Profile, Revolve, FMath::Clamp(Steps, 3, 128), bCapped);
	});
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddExtrudedPolygon(const FString& Name, const TArray<FVector2D>& Outline, float Height, const FVector& Location, const FRotator& Rotation, bool bCreateIfMissing)
{
	if (!CheckPolygon(TEXT("Outline"), Outline) || !CheckPositive(TEXT("Height"), Height))
	{
		return FString();
	}
	FEditScope Scope(Name, TEXT("Add Extruded Polygon"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	AppendOutward(Scope.Mesh, FTransform(Rotation, Location), [&](UDynamicMesh* Scratch)
	{
		Prim::AppendSimpleExtrudePolygon(Scratch, MakeOptions(), FTransform::Identity, MakeCounterClockwise(Outline), Height, 0, true, CentredOrigin);
	});
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddStairs(const FString& Name, int32 NumSteps, float StepWidth, float StepHeight, float StepDepth, const FVector& Location, const FRotator& Rotation, bool bFloating, bool bCreateIfMissing)
{
	if (NumSteps < 1 || NumSteps > 100)
	{
		Fail(TEXT("NumSteps must be between 1 and 100."));
		return FString();
	}
	if (!CheckPositive(TEXT("StepWidth"), StepWidth) || !CheckPositive(TEXT("StepHeight"), StepHeight) || !CheckPositive(TEXT("StepDepth"), StepDepth))
	{
		return FString();
	}
	FEditScope Scope(Name, TEXT("Add Stairs"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	Prim::AppendLinearStairs(Scope.Mesh, MakeOptions(), FTransform(Rotation, Location), StepWidth, StepHeight, StepDepth, NumSteps, bFloating);
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddCurvedStairs(const FString& Name, int32 NumSteps, float StepWidth, float StepHeight, float InnerRadius, float CurveAngle, const FVector& Location, const FRotator& Rotation, bool bFloating, bool bCreateIfMissing)
{
	if (NumSteps < 1 || NumSteps > 100)
	{
		Fail(TEXT("NumSteps must be between 1 and 100."));
		return FString();
	}
	if (!CheckPositive(TEXT("StepWidth"), StepWidth) || !CheckPositive(TEXT("StepHeight"), StepHeight) || !CheckPositive(TEXT("InnerRadius"), InnerRadius))
	{
		return FString();
	}
	if (FMath::Abs(CurveAngle) < 1.f || FMath::Abs(CurveAngle) > 720.f)
	{
		Fail(TEXT("CurveAngle must be between 1 and 720 degrees."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Add Curved Stairs"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	Prim::AppendCurvedStairs(Scope.Mesh, MakeOptions(), FTransform(Rotation, Location), StepWidth, StepHeight, InnerRadius, CurveAngle, NumSteps, bFloating);
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddArch(const FString& Name, float OuterWidth, float TotalHeight, float Depth, float BandWidth, const FVector& Location, const FRotator& Rotation, int32 Segments, bool bCreateIfMissing)
{
	if (!CheckPositive(TEXT("OuterWidth"), OuterWidth) || !CheckPositive(TEXT("TotalHeight"), TotalHeight) || !CheckPositive(TEXT("Depth"), Depth) || !CheckPositive(TEXT("BandWidth"), BandWidth))
	{
		return FString();
	}
	const double Ro = OuterWidth * 0.5;
	const double Ri = Ro - BandWidth;
	const double LegHeight = TotalHeight - Ro; // straight part before the curve starts
	if (Ri <= 0.0)
	{
		Fail(TEXT("BandWidth must be less than half of OuterWidth."));
		return FString();
	}
	if (LegHeight < 0.0)
	{
		Fail(TEXT("TotalHeight must be at least half of OuterWidth, so the curve fits."));
		return FString();
	}

	// One outline: left leg bottom, up the inside, over the inner curve, down the right leg, up the outside, over the outer curve.
	const int32 N = FMath::Clamp(Segments, 4, 64);
	const double Shift = -TotalHeight * 0.5; // centre the arch's bounding box on Location
	TArray<FVector2D> Outline;
	Outline.Add(FVector2D(-Ro, Shift));
	Outline.Add(FVector2D(-Ri, Shift));
	for (int32 i = 0; i <= N; ++i)
	{
		const double A = PI * (1.0 - static_cast<double>(i) / N); // 180 deg to 0 deg across the top
		Outline.Add(FVector2D(Ri * FMath::Cos(A), LegHeight + Ri * FMath::Sin(A) + Shift));
	}
	Outline.Add(FVector2D(Ri, Shift));
	Outline.Add(FVector2D(Ro, Shift));
	for (int32 i = 0; i <= N; ++i)
	{
		const double A = PI * static_cast<double>(i) / N; // 0 deg to 180 deg
		Outline.Add(FVector2D(Ro * FMath::Cos(A), LegHeight + Ro * FMath::Sin(A) + Shift));
	}

	FEditScope Scope(Name, TEXT("Add Arch"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	// The outline is built in XY and extruded along Z. Unreal rolls with the opposite sign to the right-hand rule, so -90 turns the outline's +Y up to world +Z.
	const FTransform StandUp(FRotator(0.0, 0.0, -90.0));
	AppendOutward(Scope.Mesh, StandUp * FTransform(Rotation, Location), [&](UDynamicMesh* Scratch)
	{
		Prim::AppendSimpleExtrudePolygon(Scratch, MakeOptions(), FTransform::Identity, MakeCounterClockwise(Outline), Depth, 0, true, CentredOrigin);
	});
	return Scope.Result();
}

FString UModellingPrimitivesToolset::AddSweep(const FString& Name, const TArray<FVector2D>& Profile, const TArray<FVector>& Path, bool bLoop, bool bCapped, bool bCreateIfMissing)
{
	if (!CheckPolygon(TEXT("Profile"), Profile))
	{
		return FString();
	}
	if (Path.Num() < 2 || Path.Num() > 512)
	{
		Fail(TEXT("Path needs between 2 and 512 points."));
		return FString();
	}

	// One frame per path point, with its Z axis along the direction of travel.
	TArray<FTransform> Frames;
	for (int32 i = 0; i < Path.Num(); ++i)
	{
		const FVector Prev = Path[FMath::Max(i - 1, 0)];
		const FVector Next = Path[FMath::Min(i + 1, Path.Num() - 1)];
		const FVector Tangent = (Next - Prev).GetSafeNormal();
		if (Tangent.IsNearlyZero())
		{
			Fail(TEXT("Path has two identical neighbouring points."));
			return FString();
		}
		const FVector Up = FMath::Abs(Tangent.Z) > 0.95 ? FVector(1, 0, 0) : FVector(0, 0, 1);
		Frames.Add(FTransform(FRotationMatrix::MakeFromZX(Tangent, Up).ToQuat(), Path[i]));
	}

	FEditScope Scope(Name, TEXT("Add Sweep"), bCreateIfMissing);
	if (!Scope.IsValid())
	{
		return FString();
	}
	AppendOutward(Scope.Mesh, FTransform::Identity, [&](UDynamicMesh* Scratch)
	{
		Prim::AppendSweepPolygon(Scratch, MakeOptions(), FTransform::Identity, MakeCounterClockwise(Profile), Frames, bLoop, bCapped);
	});
	return Scope.Result();
}


