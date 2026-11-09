// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingTopologyToolset.h"

#include "ModellingToolsetUtils.h"

#include "GeometryScript/MeshBooleanFunctions.h"
#include "GeometryScript/MeshNormalsFunctions.h"
#include "GeometryScript/MeshRemeshFunctions.h"
#include "GeometryScript/MeshRepairFunctions.h"
#include "GeometryScript/MeshSimplifyFunctions.h"
#include "UDynamicMesh.h"

using namespace ModellingToolset;
using Repair = UGeometryScriptLibrary_MeshRepairFunctions;

FString UModellingTopologyToolset::UniformRemesh(const FString& Name, int32 TargetTriangleCount)
{
	if (TargetTriangleCount < 100 || TargetTriangleCount > 500000)
	{
		Fail(TEXT("TargetTriangleCount must be between 100 and 500000."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Uniform Remesh"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptRemeshOptions Remesh;
	FGeometryScriptUniformRemeshOptions Uniform;
	Uniform.TargetType = EGeometryScriptUniformRemeshTargetType::TriangleCount;
	Uniform.TargetTriangleCount = TargetTriangleCount;
	UGeometryScriptLibrary_RemeshingFunctions::ApplyUniformRemesh(Scope.Mesh, Remesh, Uniform);
	return Scope.Result();
}

FString UModellingTopologyToolset::Simplify(const FString& Name, int32 TargetTriangleCount)
{
	if (TargetTriangleCount < 4)
	{
		Fail(TEXT("TargetTriangleCount must be at least 4."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Simplify"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	UGeometryScriptLibrary_MeshSimplifyFunctions::ApplySimplifyToTriangleCount(Scope.Mesh, TargetTriangleCount, FGeometryScriptSimplifyMeshOptions());
	return Scope.Result();
}

FString UModellingTopologyToolset::FillHoles(const FString& Name)
{
	FEditScope Scope(Name, TEXT("Fill Holes"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	int32 Filled = 0;
	int32 Failed = 0;
	Repair::FillAllMeshHoles(Scope.Mesh, FGeometryScriptFillHolesOptions(), Filled, Failed);

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetNumberField(TEXT("holes_filled"), Filled);
	Out->SetNumberField(TEXT("holes_failed"), Failed);
	return ToJsonString(Out);
}

FString UModellingTopologyToolset::RemoveSmallParts(const FString& Name, int32 MinTriangleCount)
{
	FEditScope Scope(Name, TEXT("Remove Small Parts"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptRemoveSmallComponentOptions Options;
	Options.MinTriangleCount = FMath::Max(MinTriangleCount, 1);
	Options.MinArea = 0.f;
	Options.MinVolume = 0.f;
	Repair::RemoveSmallComponents(Scope.Mesh, Options);
	return Scope.Result();
}

FString UModellingTopologyToolset::WeldEdges(const FString& Name, float Tolerance)
{
	if (Tolerance <= 0.f)
	{
		Fail(TEXT("Tolerance must be greater than 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Weld Edges"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptWeldEdgesOptions Options;
	Options.Tolerance = Tolerance;
	Repair::WeldMeshEdges(Scope.Mesh, Options);
	return Scope.Result();
}

FString UModellingTopologyToolset::RemoveHiddenFaces(const FString& Name)
{
	FEditScope Scope(Name, TEXT("Remove Hidden Faces"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	Repair::RemoveHiddenTriangles(Scope.Mesh, FGeometryScriptRemoveHiddenTrianglesOptions());
	return Scope.Result();
}

FString UModellingTopologyToolset::MergeOverlaps(const FString& Name)
{
	FEditScope Scope(Name, TEXT("Merge Overlaps"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	UGeometryScriptLibrary_MeshBooleanFunctions::ApplyMeshSelfUnion(Scope.Mesh, FGeometryScriptMeshSelfUnionOptions());
	return Scope.Result();
}

FString UModellingTopologyToolset::RecomputeNormals(const FString& Name)
{
	FEditScope Scope(Name, TEXT("Recompute Normals"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	UGeometryScriptLibrary_MeshNormalsFunctions::RecomputeNormals(Scope.Mesh, FGeometryScriptCalculateNormalsOptions(), /*bDeferChangeNotifications=*/false);
	return Scope.Result();
}

FString UModellingTopologyToolset::FlipNormals(const FString& Name)
{
	FEditScope Scope(Name, TEXT("Flip Normals"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	UGeometryScriptLibrary_MeshNormalsFunctions::FlipNormals(Scope.Mesh);
	return Scope.Result();
}

FString UModellingTopologyToolset::RepairDegenerate(const FString& Name)
{
	FEditScope Scope(Name, TEXT("Repair Degenerate"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	Repair::RepairMeshDegenerateGeometry(Scope.Mesh, FGeometryScriptDegenerateTriangleOptions());
	return Scope.Result();
}

FString UModellingTopologyToolset::CompactMesh(const FString& Name)
{
	FEditScope Scope(Name, TEXT("Compact Mesh"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	Repair::CompactMesh(Scope.Mesh);
	return Scope.Result();
}
