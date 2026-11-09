// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingMeasureToolset.h"

#include "ModellingToolsetUtils.h"

#include "DynamicMesh/DynamicMesh3.h"
#include "DynamicMeshActor.h"
#include "EngineUtils.h"
#include "Spatial/MeshAABBTree3.h"
#include "Distance/DistPoint3Triangle3.h"
#include "Intersection/IntrRay3Triangle3.h"
#include "Math/Ray.h"
#include "Serialization/JsonSerializer.h"
#include "UDynamicMesh.h"

using namespace ModellingToolset;
using namespace UE::Geometry;

namespace
{
	TSharedRef<FJsonObject> VecJson(const FVector& V)
	{
		TSharedRef<FJsonObject> O = MakeShared<FJsonObject>();
		O->SetNumberField(TEXT("x"), FMath::RoundToDouble(V.X * 100.0) / 100.0);
		O->SetNumberField(TEXT("y"), FMath::RoundToDouble(V.Y * 100.0) / 100.0);
		O->SetNumberField(TEXT("z"), FMath::RoundToDouble(V.Z * 100.0) / 100.0);
		return O;
	}

	/** Resolves a comma separated list of actors, or every model actor when empty. Raises a tool error for unknown names. */
	bool ResolveActors(const FString& ActorNames, TArray<ADynamicMeshActor*>& Out)
	{
		UWorld* World = GetEditorWorld();
		if (!World)
		{
			Fail(TEXT("No editor world is available."));
			return false;
		}
		if (ActorNames.TrimStartAndEnd().IsEmpty())
		{
			for (TActorIterator<ADynamicMeshActor> It(World); It; ++It)
			{
				if (It->Tags.Contains(ActorTag)) { Out.Add(*It); }
			}
		}
		else
		{
			TArray<FString> Names;
			ActorNames.ParseIntoArray(Names, TEXT(","), true);
			for (FString& N : Names)
			{
				N.TrimStartAndEndInline();
				ADynamicMeshActor* A = FindMeshActor(N);
				if (!A)
				{
					Fail(FString::Printf(TEXT("No mesh actor named '%s'."), *N));
					return false;
				}
				Out.Add(A);
			}
		}
		if (Out.IsEmpty())
		{
			Fail(TEXT("There are no model parts to measure yet."));
			return false;
		}
		return true;
	}

	/** Copy of an actor's mesh, with an AABB tree for fast queries. Built once per query. */
	struct FQueryMesh
	{
		FDynamicMesh3 Mesh;
		TUniquePtr<FDynamicMeshAABBTree3> Tree;
		FTransform ToWorld;

		bool Init(ADynamicMeshActor* Actor)
		{
			UDynamicMesh* Source = GetDynamicMesh(Actor);
			if (!Source) { return false; }
			Source->ProcessMesh([this](const FDynamicMesh3& M) { Mesh = M; });
			if (Mesh.TriangleCount() == 0) { return false; }
			Tree = MakeUnique<FDynamicMeshAABBTree3>(&Mesh, true);
			ToWorld = Actor->GetActorTransform();
			return true;
		}
	};
}

FString UModellingMeasureToolset::MeasureModel(const FString& ActorNames)
{
	TArray<ADynamicMeshActor*> Actors;
	if (!ResolveActors(ActorNames, Actors))
	{
		return FString();
	}

	FBox Bounds(ForceInit);
	int32 Triangles = 0;
	TArray<TSharedPtr<FJsonValue>> Parts;
	for (ADynamicMeshActor* Actor : Actors)
	{
		const FBox B = Actor->GetComponentsBoundingBox(/*bNonColliding=*/true);
		if (B.IsValid) { Bounds += B; }
		if (UDynamicMesh* Mesh = GetDynamicMesh(Actor))
		{
			Mesh->ProcessMesh([&Triangles](const FDynamicMesh3& M) { Triangles += M.TriangleCount(); });
		}
		Parts.Add(MakeShared<FJsonValueString>(Actor->GetActorLabel()));
	}
	if (!Bounds.IsValid)
	{
		Fail(TEXT("The parts have no geometry yet."));
		return FString();
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetArrayField(TEXT("parts"), Parts);
	Out->SetObjectField(TEXT("size_cm"), VecJson(Bounds.GetSize()));
	Out->SetNumberField(TEXT("width_x_cm"), FMath::RoundToDouble(Bounds.GetSize().X * 10.0) / 10.0);
	Out->SetNumberField(TEXT("depth_y_cm"), FMath::RoundToDouble(Bounds.GetSize().Y * 10.0) / 10.0);
	Out->SetNumberField(TEXT("height_z_cm"), FMath::RoundToDouble(Bounds.GetSize().Z * 10.0) / 10.0);
	Out->SetObjectField(TEXT("lowest_point"), VecJson(FVector(Bounds.GetCenter().X, Bounds.GetCenter().Y, Bounds.Min.Z)));
	Out->SetObjectField(TEXT("highest_point"), VecJson(FVector(Bounds.GetCenter().X, Bounds.GetCenter().Y, Bounds.Max.Z)));
	Out->SetObjectField(TEXT("center"), VecJson(Bounds.GetCenter()));
	Out->SetObjectField(TEXT("min_corner"), VecJson(Bounds.Min));
	Out->SetObjectField(TEXT("max_corner"), VecJson(Bounds.Max));
	Out->SetNumberField(TEXT("triangles"), Triangles);
	return ToJsonString(Out);
}

FString UModellingMeasureToolset::MeasureDistance(const FString& NameA, const FString& NameB)
{
	ADynamicMeshActor* ActorA = FindMeshActor(NameA);
	ADynamicMeshActor* ActorB = FindMeshActor(NameB);
	if (!ActorA || !ActorB)
	{
		Fail(FString::Printf(TEXT("No mesh actor named '%s'."), !ActorA ? *NameA : *NameB));
		return FString();
	}
	if (ActorA == ActorB)
	{
		Fail(TEXT("Pick two different parts."));
		return FString();
	}

	FQueryMesh A, B;
	if (!A.Init(ActorA) || !B.Init(ActorB))
	{
		Fail(TEXT("Both parts need geometry."));
		return FString();
	}

	// Shortest surface gap: every vertex of A (sampled if large) against B's surface, and every vertex of B against A's surface.
	// This finds the true minimum for typical shapes because the closest pair always involves a vertex of one of the two meshes.
	double BestSq = TNumericLimits<double>::Max();
	FVector PointA = FVector::ZeroVector, PointB = FVector::ZeroVector;
	auto Probe = [&BestSq, &PointA, &PointB](FQueryMesh& From, FQueryMesh& To, bool bFromIsA)
	{
		const int32 Stride = FMath::Max(1, From.Mesh.VertexCount() / 4000);
		int32 Counter = 0;
		for (const int32 Vid : From.Mesh.VertexIndicesItr())
		{
			if ((Counter++ % Stride) != 0) { continue; }
			const FVector World = From.ToWorld.TransformPosition(FVector(From.Mesh.GetVertex(Vid)));
			const FVector Local = To.ToWorld.InverseTransformPosition(World);
			double DistSq = 0.0;
			const int32 Tid = To.Tree->FindNearestTriangle(FVector3d(Local), DistSq);
			if (Tid == IndexConstants::InvalidID) { continue; }
			const FDistPoint3Triangle3d Dist = TMeshQueries<FDynamicMesh3>::TriangleDistance(To.Mesh, Tid, FVector3d(Local));
			const FVector Closest = To.ToWorld.TransformPosition(FVector(Dist.ClosestTrianglePoint));
			const double WorldSq = FVector::DistSquared(World, Closest);
			if (WorldSq < BestSq)
			{
				BestSq = WorldSq;
				PointA = bFromIsA ? World : Closest;
				PointB = bFromIsA ? Closest : World;
			}
		}
	};
	Probe(A, B, true);
	Probe(B, A, false);

	const FBox BoxA = ActorA->GetComponentsBoundingBox(true);
	const FBox BoxB = ActorB->GetComponentsBoundingBox(true);
	const double Gap = FMath::Sqrt(BestSq);

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("a"), ActorA->GetActorLabel());
	Out->SetStringField(TEXT("b"), ActorB->GetActorLabel());
	Out->SetNumberField(TEXT("surface_gap_cm"), FMath::RoundToDouble(Gap * 100.0) / 100.0);
	Out->SetBoolField(TEXT("touching_or_overlapping"), Gap < 0.05 || BoxA.Intersect(BoxB) && Gap < 0.05);
	Out->SetNumberField(TEXT("center_distance_cm"), FMath::RoundToDouble(FVector::Dist(BoxA.GetCenter(), BoxB.GetCenter()) * 100.0) / 100.0);
	Out->SetObjectField(TEXT("closest_point_on_a"), VecJson(PointA));
	Out->SetObjectField(TEXT("closest_point_on_b"), VecJson(PointB));
	Out->SetStringField(TEXT("note"), TEXT("surface_gap_cm is between the surfaces. A part fully inside another reports a gap above 0, because only surfaces are compared."));
	return ToJsonString(Out);
}

FString UModellingMeasureToolset::Raycast(const FVector& Origin, const FVector& Direction, float MaxDistance, const FString& ActorNames)
{
	if (Direction.IsNearlyZero())
	{
		Fail(TEXT("Direction must not be zero."));
		return FString();
	}
	if (MaxDistance <= 0.f)
	{
		Fail(TEXT("MaxDistance must be greater than 0."));
		return FString();
	}
	TArray<ADynamicMeshActor*> Actors;
	if (!ResolveActors(ActorNames, Actors))
	{
		return FString();
	}

	const FVector Dir = Direction.GetSafeNormal();
	double BestT = TNumericLimits<double>::Max();
	FString BestActor;
	FVector BestPoint = FVector::ZeroVector, BestNormal = FVector::ZeroVector;

	for (ADynamicMeshActor* Actor : Actors)
	{
		FQueryMesh Q;
		if (!Q.Init(Actor)) { continue; }

		// Do the query in the mesh's own space.
		const FVector LocalOrigin = Q.ToWorld.InverseTransformPosition(Origin);
		const FVector LocalDir = Q.ToWorld.InverseTransformVectorNoScale(Dir);
		const FRay3d Ray(FVector3d(LocalOrigin), FVector3d(LocalDir.GetSafeNormal()));
		const int32 Tid = Q.Tree->FindNearestHitTriangle(Ray);
		if (Tid == IndexConstants::InvalidID) { continue; }

		FVector3d V0, V1, V2;
		Q.Mesh.GetTriVertices(Tid, V0, V1, V2);
		FIntrRay3Triangle3d Intersection(Ray, FTriangle3d(V0, V1, V2));
		if (!Intersection.Find()) { continue; }

		const FVector LocalHit = FVector(Ray.PointAt(Intersection.RayParameter));
		const FVector WorldHit = Q.ToWorld.TransformPosition(LocalHit);
		const double T = FVector::Dist(Origin, WorldHit);
		if (T < BestT)
		{
			BestT = T;
			BestActor = Actor->GetActorLabel();
			BestPoint = WorldHit;
			BestNormal = Q.ToWorld.TransformVectorNoScale(FVector(Q.Mesh.GetTriNormal(Tid))).GetSafeNormal();
		}
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	if (BestActor.IsEmpty() || BestT > MaxDistance)
	{
		Out->SetBoolField(TEXT("hit"), false);
		Out->SetStringField(TEXT("note"), TEXT("The ray did not hit any model part within MaxDistance."));
		return ToJsonString(Out);
	}
	Out->SetBoolField(TEXT("hit"), true);
	Out->SetStringField(TEXT("actor"), BestActor);
	Out->SetObjectField(TEXT("point"), VecJson(BestPoint));
	Out->SetObjectField(TEXT("surface_normal"), VecJson(BestNormal));
	Out->SetNumberField(TEXT("distance_cm"), FMath::RoundToDouble(BestT * 100.0) / 100.0);
	return ToJsonString(Out);
}
