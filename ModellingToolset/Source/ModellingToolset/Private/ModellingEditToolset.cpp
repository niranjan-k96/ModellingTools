// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingEditToolset.h"

#include "ModellingToolsetUtils.h"

#include "DynamicMesh/DynamicMesh3.h"
#include "DynamicMeshActor.h"
#include "GeometryScript/MeshBasicEditFunctions.h"
#include "GeometryScript/MeshBooleanFunctions.h"
#include "GeometryScript/MeshModelingFunctions.h"
#include "GeometryScript/MeshTransformFunctions.h"
#include "Math/RotationMatrix.h"
#include "Serialization/JsonSerializer.h"
#include "UDynamicMesh.h"
#include "UObject/StrongObjectPtr.h"

using namespace ModellingToolset;
using Modeling = UGeometryScriptLibrary_MeshModelingFunctions;
using Boolean = UGeometryScriptLibrary_MeshBooleanFunctions;
using BasicEdit = UGeometryScriptLibrary_MeshBasicEditFunctions;
using Xform = UGeometryScriptLibrary_MeshTransformFunctions;

namespace
{
	constexpr int64 MaxResultTriangles = 2000000;

	/** Frame whose Z axis is the plane normal, positioned at the plane origin. */
	FTransform MakePlaneFrame(const FVector& Origin, const FVector& Normal)
	{
		return FTransform(FRotationMatrix::MakeFromZ(Normal.GetSafeNormal()).ToQuat(), Origin);
	}

	int32 TriangleCountOf(UDynamicMesh* Mesh)
	{
		int32 Count = 0;
		Mesh->ProcessMesh([&Count](const UE::Geometry::FDynamicMesh3& M) { Count = M.TriangleCount(); });
		return Count;
	}
}

FString UModellingEditToolset::GetPolygroups(const FString& Name)
{
	ADynamicMeshActor* Actor = FindMeshActor(Name);
	UDynamicMesh* Mesh = GetDynamicMesh(Actor);
	if (!Mesh)
	{
		Fail(FString::Printf(TEXT("No mesh actor named '%s'."), *Name));
		return FString();
	}

	struct FGroupInfo
	{
		int32 Triangles = 0;
		FBox Bounds = FBox(ForceInit);
		FVector NormalSum = FVector::ZeroVector;
	};
	TMap<int32, FGroupInfo> Groups;

	Mesh->ProcessMesh([&Groups](const UE::Geometry::FDynamicMesh3& M)
	{
		if (!M.HasTriangleGroups())
		{
			return;
		}
		for (const int32 Tid : M.TriangleIndicesItr())
		{
			FGroupInfo& Info = Groups.FindOrAdd(M.GetTriangleGroup(Tid));
			++Info.Triangles;
			const UE::Geometry::FAxisAlignedBox3d B = M.GetTriBounds(Tid);
			Info.Bounds += FVector(B.Min);
			Info.Bounds += FVector(B.Max);
			Info.NormalSum += FVector(M.GetTriNormal(Tid));
		}
	});

	TArray<int32> Ids;
	Groups.GetKeys(Ids);
	Ids.Sort();

	auto VecJson = [](const FVector& V)
	{
		TSharedRef<FJsonObject> O = MakeShared<FJsonObject>();
		O->SetNumberField(TEXT("x"), V.X);
		O->SetNumberField(TEXT("y"), V.Y);
		O->SetNumberField(TEXT("z"), V.Z);
		return O;
	};

	TArray<TSharedPtr<FJsonValue>> Items;
	for (const int32 Id : Ids)
	{
		if (Items.Num() >= 200)
		{
			break;
		}
		const FGroupInfo& Info = Groups[Id];
		TSharedRef<FJsonObject> Item = MakeShared<FJsonObject>();
		Item->SetNumberField(TEXT("id"), Id);
		Item->SetNumberField(TEXT("triangles"), Info.Triangles);
		Item->SetObjectField(TEXT("center_local_cm"), VecJson(Info.Bounds.GetCenter()));
		Item->SetObjectField(TEXT("size_cm"), VecJson(Info.Bounds.GetSize()));
		Item->SetObjectField(TEXT("average_normal"), VecJson(Info.NormalSum.GetSafeNormal()));
		Items.Add(MakeShared<FJsonValueObject>(Item));
	}
	return ToJsonString(Items);
}

FString UModellingEditToolset::ExtrudeFaces(const FString& Name, float Distance, const FModellingSelection& Selection, const FVector& Direction)
{
	if (FMath::IsNearlyZero(Distance))
	{
		Fail(TEXT("Distance must not be 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Extrude Faces"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}

	FGeometryScriptMeshLinearExtrudeOptions Options;
	Options.Distance = Distance;
	if (Direction.IsNearlyZero())
	{
		Options.DirectionMode = EGeometryScriptLinearExtrudeDirection::AverageFaceNormal;
	}
	else
	{
		Options.DirectionMode = EGeometryScriptLinearExtrudeDirection::FixedDirection;
		Options.Direction = Direction.GetSafeNormal();
	}
	Modeling::ApplyMeshLinearExtrudeFaces(Scope.Mesh, Options, Selected);
	return Scope.Result();
}

FString UModellingEditToolset::InsetFaces(const FString& Name, float Distance, const FModellingSelection& Selection)
{
	if (Distance <= 0.f)
	{
		Fail(TEXT("Distance must be greater than 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Inset Faces"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}

	FGeometryScriptMeshInsetOutsetFacesOptions Options;
	Options.Distance = Distance;
	Modeling::ApplyMeshInsetOutsetFaces(Scope.Mesh, Options, Selected);
	return Scope.Result();
}

FString UModellingEditToolset::OffsetFaces(const FString& Name, float Distance, const FModellingSelection& Selection)
{
	if (FMath::IsNearlyZero(Distance))
	{
		Fail(TEXT("Distance must not be 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Offset Faces"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}

	FGeometryScriptMeshOffsetFacesOptions Options;
	Options.Distance = Distance;
	Options.OffsetType = EGeometryScriptOffsetFacesType::ParallelFaceOffset;
	Modeling::ApplyMeshOffsetFaces(Scope.Mesh, Options, Selected);
	return Scope.Result();
}

FString UModellingEditToolset::BevelEdges(const FString& Name, float Distance, int32 Subdivisions)
{
	if (Distance <= 0.f)
	{
		Fail(TEXT("Distance must be greater than 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Bevel Edges"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptMeshBevelOptions Options;
	Options.BevelDistance = Distance;
	Options.Subdivisions = FMath::Clamp(Subdivisions, 0, 8);
	Modeling::ApplyMeshPolygroupBevel(Scope.Mesh, Options);
	return Scope.Result();
}

FString UModellingEditToolset::DeleteFaces(const FString& Name, const FModellingSelection& Selection)
{
	FEditScope Scope(Name, TEXT("Delete Faces"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}

	int32 NumDeleted = 0;
	BasicEdit::DeleteSelectedTrianglesFromMesh(Scope.Mesh, Selected, NumDeleted, /*bDeferChangeNotifications=*/false);
	return Scope.Result();
}

FString UModellingEditToolset::MirrorMesh(const FString& Name, const FVector& PlaneOrigin, const FVector& PlaneNormal, bool bCutAtPlane, bool bWeldSeam)
{
	if (PlaneNormal.IsNearlyZero())
	{
		Fail(TEXT("PlaneNormal must not be zero."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Mirror Mesh"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptMeshMirrorOptions Options;
	Options.bApplyPlaneCut = bCutAtPlane;
	Options.bWeldAlongPlane = bWeldSeam;
	// Geometry Script keeps the side OPPOSITE the frame normal. Our rule is "the normal points at the side you built",
	// so the frame is flipped here. (Verified by the ModellingToolset.Directions test.)
	Boolean::ApplyMeshMirror(Scope.Mesh, MakePlaneFrame(PlaneOrigin, -PlaneNormal), Options);
	return Scope.Result();
}

FString UModellingEditToolset::ArrayCopies(const FString& Name, int32 Copies, const FVector& Offset, const FRotator& Rotation, const FVector& Scale)
{
	Copies = FMath::Clamp(Copies, 1, 200);
	if (Scale.GetMin() <= 0.0)
	{
		Fail(TEXT("Scale components must be greater than 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Array Copies"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	const int32 BaseTriangles = TriangleCountOf(Scope.Mesh);
	if (BaseTriangles == 0)
	{
		Fail(TEXT("The actor has no geometry to copy."));
		return FString();
	}
	if (static_cast<int64>(BaseTriangles) * (Copies + 1) > MaxResultTriangles)
	{
		Fail(FString::Printf(TEXT("That would create more than %lld triangles. Reduce Copies or simplify first."), MaxResultTriangles));
		return FString();
	}

	// Snapshot the current geometry, then append transformed repeats of it onto the original.
	TStrongObjectPtr<UDynamicMesh> Source(NewObject<UDynamicMesh>(GetTransientPackage()));
	Scope.Mesh->ProcessMesh([&Source](const UE::Geometry::FDynamicMesh3& M) { Source->SetMesh(M); });

	BasicEdit::AppendMeshRepeated(Scope.Mesh, Source.Get(), FTransform(Rotation, Offset, Scale), Copies,
		/*bApplyTransformToFirstInstance=*/true, /*bDeferChangeNotifications=*/false, FGeometryScriptAppendMeshOptions());
	return Scope.Result();
}

FString UModellingEditToolset::BooleanOp(const FString& Name, const FString& ToolName, const FString& Operation, bool bDeleteTool)
{
	const FString Op = Operation.ToLower();
	EGeometryScriptBooleanOperation GsOp;
	if (Op == TEXT("union")) { GsOp = EGeometryScriptBooleanOperation::Union; }
	else if (Op == TEXT("subtract") || Op == TEXT("difference")) { GsOp = EGeometryScriptBooleanOperation::Subtract; }
	else if (Op == TEXT("intersect") || Op == TEXT("intersection")) { GsOp = EGeometryScriptBooleanOperation::Intersection; }
	else
	{
		Fail(TEXT("Operation must be 'union', 'subtract' or 'intersect'."));
		return FString();
	}
	if (Name == ToolName)
	{
		Fail(TEXT("Name and ToolName must be different actors."));
		return FString();
	}

	FEditScope Scope(Name, TEXT("Boolean"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	ADynamicMeshActor* ToolActor = FindModelActor(ToolName);
	if (!ToolActor || !GetDynamicMesh(ToolActor))
	{
		return FString();
	}

	// A copy of the tool whose material numbers fit the target's slots, so cut faces keep a proper colour.
	TStrongObjectPtr<UDynamicMesh> ToolCopy = CopyMeshForMerge(Scope.Actor, ToolActor);
	FGeometryScriptMeshBooleanOptions Options;
	Boolean::ApplyMeshBoolean(Scope.Mesh, Scope.Actor->GetActorTransform(), ToolCopy.Get(), ToolActor->GetActorTransform(), GsOp, Options);

	if (bDeleteTool)
	{
		ToolActor->GetWorld()->EditorDestroyActor(ToolActor, /*bShouldModifyLevel=*/true);
	}
	return Scope.Result();
}

FString UModellingEditToolset::CutWithPlane(const FString& Name, const FVector& PlaneOrigin, const FVector& PlaneNormal, bool bFlipSide, bool bFillHole)
{
	if (PlaneNormal.IsNearlyZero())
	{
		Fail(TEXT("PlaneNormal must not be zero."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Cut With Plane"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FGeometryScriptMeshPlaneCutOptions Options;
	// Geometry Script keeps the side opposite the normal by default; ours keeps the side the normal points to.
	Options.bFlipCutSide = !bFlipSide;
	Options.bFillHoles = bFillHole;
	Options.bFillSpans = bFillHole;
	Boolean::ApplyMeshPlaneCut(Scope.Mesh, MakePlaneFrame(PlaneOrigin, PlaneNormal), Options);
	return Scope.Result();
}

FString UModellingEditToolset::CombineActors(const FString& Name, const FString& SourceNames, bool bDeleteSources)
{
	TArray<FString> Names;
	SourceNames.ParseIntoArray(Names, TEXT(","), /*CullEmpty=*/true);
	if (Names.IsEmpty())
	{
		Fail(TEXT("SourceNames must list at least one actor."));
		return FString();
	}

	FEditScope Scope(Name, TEXT("Combine Actors"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	// Resolve everything first so a bad name leaves the target untouched.
	TArray<ADynamicMeshActor*> Sources;
	for (FString& N : Names)
	{
		N.TrimStartAndEndInline();
		if (N == Name)
		{
			Fail(TEXT("An actor cannot be combined into itself."));
			return FString();
		}
		ADynamicMeshActor* Source = FindModelActor(N);
		if (!Source || !GetDynamicMesh(Source))
		{
			return FString();
		}
		Sources.Add(Source);
	}

	const FTransform TargetInverse = Scope.Actor->GetActorTransform().Inverse();
	for (ADynamicMeshActor* Source : Sources)
	{
		const FTransform SourceToTarget = Source->GetActorTransform() * TargetInverse;
		// Each source keeps its own colours: its slots are added to the target and its faces renumbered.
		TStrongObjectPtr<UDynamicMesh> SourceCopy = CopyMeshForMerge(Scope.Actor, Source);
		BasicEdit::AppendMesh(Scope.Mesh, SourceCopy.Get(), SourceToTarget, /*bDeferChangeNotifications=*/false, FGeometryScriptAppendMeshOptions());
	}

	if (bDeleteSources)
	{
		for (ADynamicMeshActor* Source : Sources)
		{
			Source->GetWorld()->EditorDestroyActor(Source, /*bShouldModifyLevel=*/true);
		}
	}
	return Scope.Result();
}

FString UModellingEditToolset::TransformGeometry(const FString& Name, const FVector& Translation, const FRotator& Rotation, const FVector& Scale)
{
	if (Scale.GetAbsMin() <= UE_KINDA_SMALL_NUMBER)
	{
		Fail(TEXT("Scale components must not be 0."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Transform Geometry"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	Xform::TransformMesh(Scope.Mesh, FTransform(Rotation, Translation, Scale), /*bFixOrientationForNegativeScale=*/true);
	return Scope.Result();
}

FString UModellingEditToolset::SetPivot(const FString& Name, const FString& Pivot)
{
	const FString Mode = Pivot.ToLower();
	if (Mode != TEXT("center") && Mode != TEXT("base") && Mode != TEXT("top"))
	{
		Fail(TEXT("Pivot must be 'center', 'base' or 'top'."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Set Pivot"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	FBox Bounds(ForceInit);
	Scope.Mesh->ProcessMesh([&Bounds](const UE::Geometry::FDynamicMesh3& M)
	{
		if (M.TriangleCount() > 0)
		{
			const UE::Geometry::FAxisAlignedBox3d B = M.GetBounds();
			Bounds = FBox(FVector(B.Min), FVector(B.Max));
		}
	});
	if (!Bounds.IsValid)
	{
		Fail(TEXT("The actor has no geometry."));
		return FString();
	}

	FVector Point = Bounds.GetCenter();
	if (Mode == TEXT("base")) { Point.Z = Bounds.Min.Z; }
	else if (Mode == TEXT("top")) { Point.Z = Bounds.Max.Z; }

	// Shift the geometry by -Point and the actor by the same amount in world space, so nothing moves visually.
	const FVector NewActorLocation = Scope.Actor->GetActorTransform().TransformPosition(Point);
	Xform::TranslateMesh(Scope.Mesh, -Point);
	Scope.Actor->SetActorLocation(NewActorLocation);
	return Scope.Result();
}
