// Copyright Epic Games, Inc. All Rights Reserved.

#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "ModellingAssetToolset.h"
#include "ModellingDeformToolset.h"
#include "ModellingEditToolset.h"
#include "ModellingJob.h"
#include "ModellingBatchToolset.h"
#include "ModellingCapture.h"
#include "ModellingCompare.h"
#include "ModellingJobToolset.h"
#include "ModellingMaterialsToolset.h"
#include "ModellingMeasureToolset.h"
#include "ModellingReferenceToolset.h"
#include "ModellingPrimitivesToolset.h"
#include "ModellingSceneToolset.h"
#include "ModellingSkill.h"
#include "ModellingSurfaceToolset.h"
#include "ModellingSurfaces.h"
#include "ModellingTextureToolset.h"
#include "ModellingToolsetSettings.h"
#include "ModellingToolsetUtils.h"
#include "UI/SModellingAssistant.h"

#include "Framework/Application/SlateApplication.h"

#include "DynamicMesh/DynamicMesh3.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "DynamicMeshActor.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "HAL/FileManager.h"
#include "AssetToolsModule.h"
#include "Engine/Texture2D.h"
#include "Factories/MaterialFactoryNew.h"
#include "GeometryScript/MeshSelectionFunctions.h"
#include "GeometryScript/MeshUVFunctions.h"
#include "IAssetTools.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/PackageName.h"
#include "UDynamicMesh.h"

using namespace ModellingToolset;

namespace
{
	constexpr EAutomationTestFlags TestFlags = EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter;

	int32 TriCount(ADynamicMeshActor* Actor)
	{
		int32 Count = -1;
		if (UDynamicMesh* Mesh = GetDynamicMesh(Actor))
		{
			Mesh->ProcessMesh([&Count](const UE::Geometry::FDynamicMesh3& M) { Count = M.TriangleCount(); });
		}
		return Count;
	}

	/** Destroys test actors even when an assertion fails part-way. */
	struct FActorCleanup
	{
		TArray<TWeakObjectPtr<ADynamicMeshActor>> Actors;
		~FActorCleanup()
		{
			for (const TWeakObjectPtr<ADynamicMeshActor>& A : Actors)
			{
				if (A.IsValid() && A->GetWorld())
				{
					A->GetWorld()->DestroyActor(A.Get());
				}
			}
		}
		ADynamicMeshActor* Track(ADynamicMeshActor* A) { Actors.Add(A); return A; }
	};
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingUtilsTest, "ModellingToolset.Utils", TestFlags)
bool FModellingUtilsTest::RunTest(const FString& Parameters)
{
	TestEqual(TEXT("sanitise replaces separators"), SanitizeFileName(TEXT("a b/c")), FString(TEXT("a_b_c")));
	TestEqual(TEXT("sanitise never empty"), SanitizeFileName(FString()), FString(TEXT("untitled")));

	TestTrue(TEXT("child path accepted"), IsPathUnder(TEXT("C:/Proj/Refs/a.png"), TEXT("C:/Proj/Refs")));
	TestFalse(TEXT("sibling prefix rejected"), IsPathUnder(TEXT("C:/Proj/Refs2/a.png"), TEXT("C:/Proj/Refs")));
	TestFalse(TEXT("dot-dot escape rejected"), IsPathUnder(TEXT("C:/Proj/Refs/../Secret/a.png"), TEXT("C:/Proj/Refs")));

	// Resizing keeps a flat colour flat.
	TArray<FColor> Src;
	Src.Init(FColor(200, 100, 50, 255), 8 * 8);
	TArray<FColor> Dst;
	ResizeImage(Src, FIntPoint(8, 8), FIntPoint(3, 5), Dst);
	TestEqual(TEXT("resized pixel count"), Dst.Num(), 15);
	TestEqual(TEXT("flat colour preserved"), Dst[7], FColor(200, 100, 50, 255));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingActorsTest, "ModellingToolset.Actors", TestFlags)
bool FModellingActorsTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld())
	{
		AddError(TEXT("No editor world."));
		return false;
	}
	FActorCleanup Cleanup;

	// Same requested name must yield distinct labels.
	ADynamicMeshActor* A = Cleanup.Track(CreateMeshActor(TEXT("MtTestPart"), FVector::ZeroVector, FRotator::ZeroRotator));
	ADynamicMeshActor* B = Cleanup.Track(CreateMeshActor(TEXT("MtTestPart"), FVector::ZeroVector, FRotator::ZeroRotator));
	if (!TestNotNull(TEXT("first actor"), A) || !TestNotNull(TEXT("second actor"), B))
	{
		return false;
	}
	TestNotEqual(TEXT("labels are unique"), A->GetActorLabel(), B->GetActorLabel());
	TestTrue(TEXT("actor is tagged"), A->Tags.Contains(ActorTag));

	// Untagged dynamic mesh actors must not be editable.
	A->Tags.Remove(ActorTag);
	FEditScope Guarded(A->GetActorLabel(), TEXT("Test"), false);
	TestFalse(TEXT("untagged actor rejected"), Guarded.IsValid());
	A->Tags.AddUnique(ActorTag);

	// A missing actor is not auto-created unless asked.
	FEditScope Missing(TEXT("MtDoesNotExist"), TEXT("Test"), false);
	TestFalse(TEXT("missing actor not auto-created"), Missing.IsValid());
	TestNull(TEXT("no stray actor"), FindMeshActor(TEXT("MtDoesNotExist")));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingEditTest, "ModellingToolset.Edit", TestFlags)
bool FModellingEditTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld())
	{
		AddError(TEXT("No editor world."));
		return false;
	}
	FActorCleanup Cleanup;

	ADynamicMeshActor* Part = Cleanup.Track(CreateMeshActor(TEXT("MtEditTest"), FVector::ZeroVector, FRotator::ZeroRotator));
	if (!TestNotNull(TEXT("actor"), Part))
	{
		return false;
	}
	const FString Name = Part->GetActorLabel();

	UModellingPrimitivesToolset::AddBox(Name, FVector(100, 100, 100), FVector::ZeroVector, FRotator::ZeroRotator, false);
	TestEqual(TEXT("box has 12 triangles"), TriCount(Part), 12);

	// Checkpoint round trip.
	TestTrue(TEXT("checkpoint saved"), UModellingSceneToolset::SaveCheckpoint(Name, TEXT("cube")));
	FModellingSelection Top;
	Top.Mode = TEXT("normal");
	Top.A = FVector(0, 0, 1);
	Top.Scalar = 10.f;
	UModellingEditToolset::ExtrudeFaces(Name, 20.f, Top, FVector::ZeroVector);
	TestTrue(TEXT("extrude adds triangles"), TriCount(Part) > 12);
	UModellingSceneToolset::RestoreCheckpoint(Name, TEXT("cube"));
	TestEqual(TEXT("restore returns to 12 triangles"), TriCount(Part), 12);

	// Array copies: 3 extra copies of a 12-triangle box.
	UModellingEditToolset::ArrayCopies(Name, 3, FVector(200, 0, 0), FRotator::ZeroRotator, FVector::OneVector);
	TestEqual(TEXT("array makes 4 boxes"), TriCount(Part), 48);

	// Boolean subtract with a cutter actor, which is removed afterwards.
	ADynamicMeshActor* Target = Cleanup.Track(CreateMeshActor(TEXT("MtBoolTarget"), FVector::ZeroVector, FRotator::ZeroRotator));
	ADynamicMeshActor* Cutter = Cleanup.Track(CreateMeshActor(TEXT("MtBoolCutter"), FVector(50, 0, 0), FRotator::ZeroRotator));
	if (TestNotNull(TEXT("boolean actors"), Target) && TestNotNull(TEXT("cutter"), Cutter))
	{
		const FString TargetName = Target->GetActorLabel();
		const FString CutterName = Cutter->GetActorLabel();
		UModellingPrimitivesToolset::AddBox(TargetName, FVector(100, 100, 100), FVector::ZeroVector, FRotator::ZeroRotator, false);
		UModellingPrimitivesToolset::AddBox(CutterName, FVector(60, 60, 60), FVector::ZeroVector, FRotator::ZeroRotator, false);
		const int32 Before = TriCount(Target);
		UModellingEditToolset::BooleanOp(TargetName, CutterName, TEXT("subtract"), true);
		TestTrue(TEXT("boolean changed the target"), TriCount(Target) != Before);
		TestNull(TEXT("cutter deleted"), FindMeshActor(CutterName));
	}

	// Subdivide multiplies triangles by (level+1)^2.
	ADynamicMeshActor* Sub = Cleanup.Track(CreateMeshActor(TEXT("MtSubTest"), FVector::ZeroVector, FRotator::ZeroRotator));
	if (TestNotNull(TEXT("subdivide actor"), Sub))
	{
		UModellingPrimitivesToolset::AddBox(Sub->GetActorLabel(), FVector(100, 100, 100), FVector::ZeroVector, FRotator::ZeroRotator, false);
		UModellingDeformToolset::Subdivide(Sub->GetActorLabel(), 1);
		TestTrue(TEXT("subdivide increases triangles"), TriCount(Sub) > 12);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingAssetTest, "ModellingToolset.Asset", TestFlags)
bool FModellingAssetTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld())
	{
		AddError(TEXT("No editor world."));
		return false;
	}

	const FString Folder = TEXT("/Game/__ModellingToolsetTest");
	const FString Package = Folder + TEXT("/MtSaveTest");
	const FString ObjectPath = Package + TEXT(".MtSaveTest");

	// Remove the test asset (memory and disk) however the test ends.
	struct FAssetCleanup
	{
		FString Folder, ObjectPath;
		~FAssetCleanup()
		{
			if (UStaticMesh* SM = FindObject<UStaticMesh>(nullptr, *ObjectPath))
			{
				FAssetRegistryModule::AssetDeleted(SM);
				SM->MarkAsGarbage();
			}
			IFileManager::Get().DeleteDirectory(*FPackageName::LongPackageNameToFilename(Folder + TEXT("/")), false, true);
		}
	} AssetCleanup{ Folder, ObjectPath };
	FActorCleanup Cleanup;

	ADynamicMeshActor* Part = Cleanup.Track(CreateMeshActor(TEXT("MtAssetTest"), FVector::ZeroVector, FRotator::ZeroRotator));
	if (!TestNotNull(TEXT("source actor"), Part))
	{
		return false;
	}
	const FString Name = Part->GetActorLabel();
	UModellingPrimitivesToolset::AddBox(Name, FVector(100, 100, 100), FVector::ZeroVector, FRotator::ZeroRotator, false);

	// Bad paths are rejected.
	TestTrue(TEXT("non-/Game path rejected"), UModellingAssetToolset::SaveToStaticMesh(Name, TEXT("/Engine/Evil"), false, TEXT("none"), false, false, false, false).IsEmpty());
	TestTrue(TEXT("dot-dot path rejected"), UModellingAssetToolset::SaveToStaticMesh(Name, TEXT("/Game/../Evil"), false, TEXT("none"), false, false, false, false).IsEmpty());
	TestTrue(TEXT("bad collision mode rejected"), UModellingAssetToolset::SaveToStaticMesh(Name, Package, false, TEXT("banana"), false, false, false, false).IsEmpty());

	// Real save to disk.
	const FString Saved = UModellingAssetToolset::SaveToStaticMesh(Name, Package, false, TEXT("box"), false, false, false, true);
	TestFalse(TEXT("save returned a result"), Saved.IsEmpty());
	UStaticMesh* SM = FindObject<UStaticMesh>(nullptr, *ObjectPath);
	TestNotNull(TEXT("asset exists in memory"), SM);
	TestTrue(TEXT("package file written"), FPackageName::DoesPackageExist(Package));
	if (SM)
	{
		TestTrue(TEXT("asset has geometry"), SM->GetNumSourceModels() >= 1);
		TestNotNull(TEXT("collision body setup"), SM->GetBodySetup());
	}

	// Overwrite protection.
	TestTrue(TEXT("second save without overwrite fails"), UModellingAssetToolset::SaveToStaticMesh(Name, Package, false, TEXT("none"), false, false, false, false).IsEmpty());
	TestFalse(TEXT("save with overwrite succeeds"), UModellingAssetToolset::SaveToStaticMesh(Name, Package, true, TEXT("none"), false, false, false, false).IsEmpty());

	// Round trip back into an editable actor.
	const FString Imported = UModellingAssetToolset::ImportStaticMesh(Package, TEXT("MtAssetImported"));
	TestFalse(TEXT("import returned a result"), Imported.IsEmpty());
	if (ADynamicMeshActor* Back = FindMeshActor(TEXT("MtAssetImported")))
	{
		Cleanup.Track(Back);
		TestEqual(TEXT("imported box has 12 triangles"), TriCount(Back), 12);
	}
	else
	{
		AddError(TEXT("Imported actor not found."));
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingJobTest, "ModellingToolset.Job", TestFlags)
bool FModellingJobTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld())
	{
		AddError(TEXT("No editor world."));
		return false;
	}
	FActorCleanup Cleanup;

	// Removes the files this test creates, and nothing else.
	const FString JobName = TEXT("MtJobTest");
	struct FFileCleanup
	{
		FString Name;
		~FFileCleanup()
		{
			ModellingToolset::ResetJob();
			const FString Package = TEXT("/Game/ModellingToolset/Exports/") + Name;
			if (UStaticMesh* SM = FindObject<UStaticMesh>(nullptr, *(Package + TEXT(".") + Name)))
			{
				FAssetRegistryModule::AssetDeleted(SM);
				SM->MarkAsGarbage();
			}
			IFileManager::Get().Delete(*FPackageName::LongPackageNameToFilename(Package, TEXT(".uasset")), false, true);
			IFileManager::Get().Delete(*(GetExportsDir() / (Name + TEXT(".fbx"))), false, true);
			// Only removes the folders if they are now empty.
			IFileManager::Get().DeleteDirectory(*FPackageName::LongPackageNameToFilename(TEXT("/Game/ModellingToolset/Exports/")), false, false);
			IFileManager::Get().DeleteDirectory(*FPackageName::LongPackageNameToFilename(TEXT("/Game/ModellingToolset/")), false, false);
		}
	} FileCleanup{ JobName };

	ResetJob();
	FString Error, Json;

	// Before Go: the AI is told not to start.
	TestEqual(TEXT("starts idle"), GetJob().Status, EJobStatus::Idle);
	const FString NotStarted = UModellingJobToolset::GetModellingJob();
	TestTrue(TEXT("reports not_started"), NotStarted.Contains(TEXT("not_started")));
	TestTrue(TEXT("tells the AI not to model"), NotStarted.Contains(TEXT("Do NOT start modelling")));
	TestEqual(TEXT("asking does not start the job"), GetJob().Status, EJobStatus::Idle);

	// Go needs a description.
	TestFalse(TEXT("empty description rejected"), StartJob(TEXT("   "), JobName, Error));
	TestTrue(TEXT("Go accepted"), StartJob(TEXT("A small box house"), JobName, Error));
	TestEqual(TEXT("ready for AI"), GetJob().Status, EJobStatus::ReadyForAI);
	TestFalse(TEXT("cannot start twice"), StartJob(TEXT("again"), JobName, Error));

	// The AI starts, and must tell the user in the log.
	const FString Started = UModellingJobToolset::GetModellingJob();
	TestEqual(TEXT("working"), GetJob().Status, EJobStatus::Working);
	TestTrue(TEXT("job carries the instructions"), Started.Contains(TEXT("A small box house")));
	TestTrue(TEXT("AI is told to view references first or model from text"), Started.Contains(TEXT("references")));
	UModellingJobToolset::ReportProgress(TEXT("Blocked out the walls"));
	TestTrue(TEXT("progress is logged"), GetJob().Log.Last().Contains(TEXT("Blocked out the walls")));

	// Build something so the export has a model.
	ADynamicMeshActor* Part = Cleanup.Track(CreateMeshActor(TEXT("MtJobPart"), FVector(500, 200, 100), FRotator::ZeroRotator));
	if (!TestNotNull(TEXT("model part"), Part))
	{
		return false;
	}
	UModellingPrimitivesToolset::AddBox(Part->GetActorLabel(), FVector(100, 100, 100), FVector::ZeroVector, FRotator::ZeroRotator, false);

	// Review flow.
	TestTrue(TEXT("review requested"), RequestReview(TEXT("A simple box"), Error));
	TestEqual(TEXT("review pending"), GetJob().Status, EJobStatus::ReviewPending);
	TestFalse(TEXT("cannot review twice"), RequestReview(TEXT("again"), Error));
	TestFalse(TEXT("no decision yet"), TryConsumeDecision(Json));
	TestTrue(TEXT("GetUserDecision says pending"), UModellingJobToolset::GetUserDecision().Contains(TEXT("pending")));

	TestFalse(TEXT("empty change request rejected"), SubmitChanges(TEXT(" "), Error));
	TestTrue(TEXT("changes accepted"), SubmitChanges(TEXT("Make it taller"), Error));
	TestEqual(TEXT("changes requested"), GetJob().Status, EJobStatus::ChangesRequested);
	TestTrue(TEXT("AI receives the changes"), TryConsumeDecision(Json));
	TestTrue(TEXT("decision is changes"), Json.Contains(TEXT("\"decision\": \"changes\"")) || Json.Contains(TEXT("\"decision\":\"changes\"")));
	TestTrue(TEXT("decision carries the text"), Json.Contains(TEXT("Make it taller")));
	TestEqual(TEXT("back to working"), GetJob().Status, EJobStatus::Working);
	TestFalse(TEXT("changes are delivered only once"), TryConsumeDecision(Json) && Json.Contains(TEXT("Make it taller")));

	// Done: exports the FBX.
	TestTrue(TEXT("second review requested"), RequestReview(TEXT("Now taller"), Error));
	const bool bExported = FinishAndExport(Error);
	TestTrue(*FString::Printf(TEXT("export succeeded (%s)"), *Error), bExported);
	TestEqual(TEXT("done"), GetJob().Status, EJobStatus::Done);
	TestTrue(TEXT("FBX file exists"), IFileManager::Get().FileExists(*GetJob().FbxPath));
	TestTrue(TEXT("FBX is not empty"), IFileManager::Get().FileSize(*GetJob().FbxPath) > 100);
	TestTrue(TEXT("AI is told it is done"), TryConsumeDecision(Json) && Json.Contains(TEXT("done")) && Json.Contains(TEXT(".fbx")));

	// A finished job can be started again.
	TestTrue(TEXT("new job after done"), StartJob(TEXT("Another"), JobName, Error));
	ResetJob();
	TestEqual(TEXT("reset"), GetJob().Status, EJobStatus::Idle);
	return true;
}

// Locks in how the direction-sensitive tools behave. Measured against real geometry, so a Geometry Script change that flips a direction fails here.
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingDirectionsTest, "ModellingToolset.Directions", TestFlags)
bool FModellingDirectionsTest::RunTest(const FString& Parameters)
{
	FActorCleanup Cleanup;
	const FRotator R0 = FRotator::ZeroRotator;
	auto Make = [&](const TCHAR* N) { return Cleanup.Track(CreateMeshActor(N, FVector::ZeroVector, FRotator::ZeroRotator)); };
	auto BoundsOf = [](ADynamicMeshActor* A)
	{
		FBox B(ForceInit);
		GetDynamicMesh(A)->ProcessMesh([&B](const UE::Geometry::FDynamicMesh3& M)
		{
			if (M.TriangleCount() > 0) { const UE::Geometry::FAxisAlignedBox3d X = M.GetBounds(); B = FBox(FVector(X.Min), FVector(X.Max)); }
		});
		return B;
	};
	auto Box = [&](const TCHAR* N, FVector Size, FVector At)
	{
		ADynamicMeshActor* A = Make(N);
		UModellingPrimitivesToolset::AddBox(A->GetActorLabel(), Size, At, R0, false);
		return A;
	};
	const double Tol = 0.5;

	// ---- Mirror: the normal points at the half you built ----
	{
		ADynamicMeshActor* A = Box(TEXT("DMirror"), FVector(100, 40, 40), FVector(50, 0, 0)); // built on +X
		UModellingEditToolset::MirrorMesh(A->GetActorLabel(), FVector::ZeroVector, FVector(1, 0, 0), true, true);
		const FBox B = BoundsOf(A);
		TestTrue(TEXT("mirror toward the built side makes a symmetric model"), FMath::IsNearlyEqual(B.Min.X, -100.0, Tol) && FMath::IsNearlyEqual(B.Max.X, 100.0, Tol));
	}
	{
		ADynamicMeshActor* A = Box(TEXT("DMirrorWrong"), FVector(100, 40, 40), FVector(50, 0, 0));
		UModellingEditToolset::MirrorMesh(A->GetActorLabel(), FVector::ZeroVector, FVector(-1, 0, 0), true, true); // points at the empty side
		TestEqual(TEXT("mirror toward an empty side is undone, not destructive"), TriCount(A), 12);
		TestTrue(TEXT("original geometry restored"), FMath::IsNearlyEqual(BoundsOf(A).Max.X, 100.0, Tol));
	}

	// ---- Plane cut: the normal points at the side you keep ----
	{
		struct FCase { FVector Normal; bool bFlip; double MinX; double MaxX; };
		const FCase Cases[] = {
			{ FVector(1, 0, 0), false, 0, 50 }, { FVector(1, 0, 0), true, -50, 0 },
			{ FVector(-1, 0, 0), false, -50, 0 }, { FVector(-1, 0, 0), true, 0, 50 } };
		for (const FCase& C : Cases)
		{
			ADynamicMeshActor* A = Box(TEXT("DCut"), FVector(100, 40, 40), FVector::ZeroVector);
			UModellingEditToolset::CutWithPlane(A->GetActorLabel(), FVector::ZeroVector, C.Normal, C.bFlip, true);
			const FBox B = BoundsOf(A);
			TestTrue(*FString::Printf(TEXT("cut normal %g flip %d keeps X %g..%g"), C.Normal.X, C.bFlip, C.MinX, C.MaxX),
				FMath::IsNearlyEqual(B.Min.X, C.MinX, Tol) && FMath::IsNearlyEqual(B.Max.X, C.MaxX, Tol));
		}
	}

	// ---- Bend: positive angle curves the ends toward BendDirection ----
	{
		auto Tall = [&](const TCHAR* N)
		{
			ADynamicMeshActor* A = Box(N, FVector(20, 20, 200), FVector::ZeroVector);
			UModellingDeformToolset::Subdivide(A->GetActorLabel(), 8);
			return A;
		};
		struct FBendCase { FVector Dir; float Angle; int32 Axis; int32 Sign; }; // Axis 0=X 1=Y ; Sign +1/-1 = which side grows
		const FBendCase Cases[] = { { FVector(1,0,0), 90, 0, +1 }, { FVector(0,1,0), 90, 1, +1 }, { FVector(-1,0,0), 90, 0, -1 }, { FVector(0,-1,0), 90, 1, -1 }, { FVector(1,0,0), -90, 0, -1 } };
		for (const FBendCase& C : Cases)
		{
			ADynamicMeshActor* A = Tall(TEXT("DBend"));
			UModellingDeformToolset::Bend(A->GetActorLabel(), C.Angle, 100.f, FVector(0, 0, 1), FVector::ZeroVector, C.Dir);
			const FBox B = BoundsOf(A);
			const double Grown = C.Sign > 0 ? (C.Axis == 0 ? B.Max.X : B.Max.Y) : -(C.Axis == 0 ? B.Min.X : B.Min.Y);
			const double Other = C.Axis == 0 ? B.GetExtent().Y : B.GetExtent().X;
			TestTrue(*FString::Printf(TEXT("bend %g toward (%g,%g) curves the ends that way"), C.Angle, C.Dir.X, C.Dir.Y), Grown > 40.0);
			TestTrue(TEXT("bend does not move sideways"), Other < 10.5);
		}
	}

	// ---- Flare: FlareX widens X, FlareY widens Y ----
	{
		ADynamicMeshActor* A = Box(TEXT("DFlareX"), FVector(20, 20, 200), FVector::ZeroVector);
		UModellingDeformToolset::Subdivide(A->GetActorLabel(), 8);
		UModellingDeformToolset::Flare(A->GetActorLabel(), 100.f, 0.f, 100.f, FVector(0, 0, 1), FVector::ZeroVector);
		const FBox B = BoundsOf(A);
		TestTrue(TEXT("FlareX widens X"), B.Max.X > 15.0 && B.Max.Y < 10.5);
	}
	{
		ADynamicMeshActor* A = Box(TEXT("DFlareY"), FVector(20, 20, 200), FVector::ZeroVector);
		UModellingDeformToolset::Subdivide(A->GetActorLabel(), 8);
		UModellingDeformToolset::Flare(A->GetActorLabel(), 0.f, 100.f, 100.f, FVector(0, 0, 1), FVector::ZeroVector);
		const FBox B = BoundsOf(A);
		TestTrue(TEXT("FlareY widens Y"), B.Max.Y > 15.0 && B.Max.X < 10.5);
	}

	// ---- Face tools on a 100 cm cube ----
	FModellingSelection Top; Top.Mode = TEXT("normal"); Top.A = FVector(0, 0, 1); Top.Scalar = 10.f;
	{
		ADynamicMeshActor* A = Box(TEXT("DExtrude"), FVector(100, 100, 100), FVector::ZeroVector);
		UModellingEditToolset::ExtrudeFaces(A->GetActorLabel(), 30.f, Top, FVector::ZeroVector);
		TestTrue(TEXT("extrude +30 raises the top to 80"), FMath::IsNearlyEqual(BoundsOf(A).Max.Z, 80.0, Tol));
	}
	{
		ADynamicMeshActor* A = Box(TEXT("DOffset"), FVector(100, 100, 100), FVector::ZeroVector);
		UModellingEditToolset::OffsetFaces(A->GetActorLabel(), 20.f, Top);
		TestTrue(TEXT("offset +20 raises the top to 70"), FMath::IsNearlyEqual(BoundsOf(A).Max.Z, 70.0, Tol));
	}
	{
		ADynamicMeshActor* A = Box(TEXT("DInset"), FVector(100, 100, 100), FVector::ZeroVector);
		UModellingEditToolset::InsetFaces(A->GetActorLabel(), 10.f, Top);
		TestTrue(TEXT("inset keeps the outer size and adds faces"), FMath::IsNearlyEqual(BoundsOf(A).Max.Z, 50.0, Tol) && TriCount(A) > 12);
	}

	// ---- Pivot ----
	{
		ADynamicMeshActor* A = Box(TEXT("DPivot"), FVector(100, 100, 100), FVector::ZeroVector);
		A->SetActorLocation(FVector(500, 0, 50));
		UModellingEditToolset::SetPivot(A->GetActorLabel(), TEXT("base"));
		TestTrue(TEXT("pivot base puts the mesh above the actor origin"), FMath::IsNearlyEqual(BoundsOf(A).Min.Z, 0.0, Tol));
		TestTrue(TEXT("actor moved down by the same amount"), FMath::IsNearlyEqual(A->GetActorLocation().Z, 0.0, Tol));
	}

	// ---- Revert last edit ----
	{
		ADynamicMeshActor* A = Box(TEXT("DRevert"), FVector(100, 100, 100), FVector::ZeroVector);
		UModellingEditToolset::ExtrudeFaces(A->GetActorLabel(), 30.f, Top, FVector::ZeroVector);
		TestTrue(TEXT("edit changed the mesh"), TriCount(A) > 12);
		UModellingSceneToolset::RevertLastEdit(A->GetActorLabel());
		TestEqual(TEXT("revert restores the previous mesh"), TriCount(A), 12);
	}
	return true;
}
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingSkillTest, "ModellingToolset.Skill", TestFlags)
bool FModellingSkillTest::RunTest(const FString& Parameters)
{
	const UModellingWorkflowSkill* Skill = GetDefault<UModellingWorkflowSkill>();
	TestFalse(TEXT("skill has a description"), Skill->Description.IsEmpty());

	const FString Text = Skill->GetDetails().Instructions;
	TestFalse(TEXT("folder placeholder was replaced"), Text.Contains(TEXT("{ReferencesFolder}")));
	TestTrue(TEXT("mentions the real references folder"), Text.Contains(GetReferencesDir()));

	// The order matters: job, then references, then modelling, then review, then the decision.
	const int32 Job = Text.Find(TEXT("GetModellingJob"));
	const int32 Refs = Text.Find(TEXT("LOOK AT THE REFERENCE IMAGES FIRST"));
	const int32 Block = Text.Find(TEXT("BLOCK OUT"));
	const int32 Palette = Text.Find(TEXT("GetReferencePalette"));
	const int32 Compare = Text.Find(TEXT("CompareToReference"));
	const int32 Colour = Text.Find(TEXT("STEP 6. SURFACES AND COLOUR"));
	TestTrue(TEXT("surfaces step mentions textures, the library, AutoUV and asking the user"),
		Text.Contains(TEXT("ListTextureSets")) && Text.Contains(TEXT("ListLibraryMaterials")) && Text.Contains(TEXT("AutoUV")) && Text.Contains(TEXT("please add Brick_albedo.png")));
	const int32 Review = Text.Find(TEXT("RequestReview"));
	const int32 Decision = Text.Find(TEXT("WaitForUserDecision"));
	TestTrue(TEXT("job is read first"), Job != INDEX_NONE && Job < Refs);
	TestTrue(TEXT("references come before modelling"), Refs != INDEX_NONE && Refs < Block);
	TestTrue(TEXT("review comes after modelling"), Block < Review);
	TestTrue(TEXT("colours are read from the references before any modelling"), Palette != INDEX_NONE && Palette < Block);
	TestTrue(TEXT("comparison happens while blocking out, before colouring"), Compare != INDEX_NONE && Block < Compare && Compare < Colour);
	TestTrue(TEXT("mentions batching, measuring, reverting and cancelling"),
		Text.Contains(TEXT("RunBatch")) && Text.Contains(TEXT("MeasureModel")) && Text.Contains(TEXT("RevertLastEdit")) && Text.Contains(TEXT("cancelled")));
	TestTrue(TEXT("decision comes after review"), Review < Decision);
	TestTrue(TEXT("tells the AI not to export itself"), Text.Contains(TEXT("do NOT export")) || Text.Contains(TEXT("Do NOT export")));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingPanelTest, "ModellingToolset.Panel", TestFlags)
bool FModellingPanelTest::RunTest(const FString& Parameters)
{
	if (!FSlateApplication::IsInitialized())
	{
		AddWarning(TEXT("Slate is not initialised in this run; panel test skipped."));
		return true;
	}

	// Build the panel in every job state and force Slate to evaluate all bindings and layout.
	const EJobStatus States[] = {
		EJobStatus::Idle, EJobStatus::ReadyForAI, EJobStatus::Working, EJobStatus::ReviewPending,
		EJobStatus::ChangesRequested, EJobStatus::Exporting, EJobStatus::Done, EJobStatus::Failed };

	ResetJob();
	TSharedRef<SModellingAssistant> Panel = SNew(SModellingAssistant);
	for (const EJobStatus State : States)
	{
		GetJob().Status = State;
		GetJob().ReviewSummary = TEXT("Summary");
		GetJob().Error = TEXT("Example error");
		Panel->SlatePrepass(1.0f);
		TestTrue(*FString::Printf(TEXT("panel has a size in state %s"), StatusToString(State)), Panel->GetDesiredSize().Y > 0.f);
	}
	ResetJob();
	return true;
}

// ---- Shapes, measuring, materials, palette, comparison ------------------------------------------------------------

namespace
{
	FBox MeshBounds(ADynamicMeshActor* A)
	{
		FBox B(ForceInit);
		GetDynamicMesh(A)->ProcessMesh([&B](const UE::Geometry::FDynamicMesh3& M)
		{
			if (M.TriangleCount() > 0) { const UE::Geometry::FAxisAlignedBox3d X = M.GetBounds(); B = FBox(FVector(X.Min), FVector(X.Max)); }
		});
		return B;
	}

	TSharedPtr<FJsonObject> ParseJson(const FString& Text)
	{
		TSharedPtr<FJsonObject> Obj;
		FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(Text), Obj);
		return Obj;
	}
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingShapesTest, "ModellingToolset.Shapes", TestFlags)
bool FModellingShapesTest::RunTest(const FString& Parameters)
{
	FActorCleanup Cleanup;
	const FRotator R0 = FRotator::ZeroRotator;
	auto Make = [&](const TCHAR* N) { return Cleanup.Track(CreateMeshActor(N, FVector::ZeroVector, FRotator::ZeroRotator)); };

	// Revolve: a vase profile spun a full turn.
	{
		ADynamicMeshActor* A = Make(TEXT("SRevolve"));
		const TArray<FVector2D> Profile = { FVector2D(0, 0), FVector2D(30, 0), FVector2D(40, 40), FVector2D(25, 90), FVector2D(15, 110) };
		UModellingPrimitivesToolset::AddRevolve(A->GetActorLabel(), Profile, FVector::ZeroVector, R0, 360.f, 24, true, false);
		const FBox B = MeshBounds(A);
		TestTrue(TEXT("revolve has geometry"), TriCount(A) > 0);
		TestTrue(TEXT("revolve is 80 wide at its belly"), FMath::IsNearlyEqual(B.Max.X, 40.0, 1.5) && FMath::IsNearlyEqual(B.Min.X, -40.0, 1.5));
		TestTrue(TEXT("revolve is 110 tall, standing on Z=0"), FMath::IsNearlyEqual(B.Min.Z, 0.0, 0.5) && FMath::IsNearlyEqual(B.Max.Z, 110.0, 0.5));
		TestFalse(TEXT("revolve faces outward"), DiagnoseMesh(A).bInsideOut);
	}
	// The same profile written top-to-bottom, and a hollow (U-shaped) profile, must also face outward.
	{
		ADynamicMeshActor* A = Make(TEXT("SRevolveRev"));
		UModellingPrimitivesToolset::AddRevolve(A->GetActorLabel(), { FVector2D(15, 110), FVector2D(25, 90), FVector2D(40, 40), FVector2D(30, 0), FVector2D(0, 0) }, FVector::ZeroVector, R0, 360.f, 24, true, false);
		TestTrue(TEXT("reversed profile has geometry"), TriCount(A) > 0);
		TestFalse(TEXT("reversed profile faces outward"), DiagnoseMesh(A).bInsideOut);
	}
	{
		ADynamicMeshActor* A = Make(TEXT("SRevolveHollow"));
		const TArray<FVector2D> Hollow = { FVector2D(0, 0), FVector2D(18, 0), FVector2D(24, 30), FVector2D(14, 70), FVector2D(16, 100), FVector2D(13, 100), FVector2D(11, 70), FVector2D(20, 30), FVector2D(15, 4), FVector2D(0, 4) };
		UModellingPrimitivesToolset::AddRevolve(A->GetActorLabel(), Hollow, FVector::ZeroVector, R0, 360.f, 24, true, false);
		const FMeshDiagnostics D = DiagnoseMesh(A);
		TestTrue(TEXT("hollow vase is closed"), D.OpenBoundaryEdges == 0 && D.Triangles > 0);
		TestFalse(TEXT("hollow vase faces outward"), D.bInsideOut);
		TestTrue(TEXT("hollow vase has positive volume"), D.SignedVolume > 0.0);
	}
	{
		ADynamicMeshActor* A = Make(TEXT("SRevolveBad"));
		UModellingPrimitivesToolset::AddRevolve(A->GetActorLabel(), { FVector2D(-5, 0), FVector2D(10, 50) }, FVector::ZeroVector, R0, 360.f, 24, true, false);
		TestEqual(TEXT("negative radius is rejected"), TriCount(A), 0);
	}

	// Extruded outline: an L shape, in both winding directions.
	{
		const TArray<FVector2D> L = { FVector2D(0, 0), FVector2D(200, 0), FVector2D(200, 50), FVector2D(50, 50), FVector2D(50, 200), FVector2D(0, 200) };
		TArray<FVector2D> Reversed = L; Algo::Reverse(Reversed);
		int32 Tris[2] = { 0, 0 };
		int32 Index = 0;
		const TArray<FVector2D>* Outlines[2] = { &L, &Reversed };
		for (const TArray<FVector2D>* Outline : Outlines)
		{
			ADynamicMeshActor* A = Make(TEXT("SExtrude"));
			UModellingPrimitivesToolset::AddExtrudedPolygon(A->GetActorLabel(), *Outline, 100.f, FVector::ZeroVector, R0, false);
			const FBox B = MeshBounds(A);
			TestTrue(TEXT("L shape is 200 x 200 x 100"), FMath::IsNearlyEqual(B.GetSize().X, 200.0, 0.5) && FMath::IsNearlyEqual(B.GetSize().Y, 200.0, 0.5) && FMath::IsNearlyEqual(B.GetSize().Z, 100.0, 0.5));
			Tris[Index++] = TriCount(A);
		}
		TestEqual(TEXT("winding direction does not matter"), Tris[0], Tris[1]);
		TestFalse(TEXT("extruded outline faces outward"), DiagnoseMesh(FindMeshActor(TEXT("SExtrude"))).bInsideOut);
	}

	// Stairs.
	{
		ADynamicMeshActor* A = Make(TEXT("SStairs"));
		UModellingPrimitivesToolset::AddStairs(A->GetActorLabel(), 10, 100.f, 20.f, 30.f, FVector::ZeroVector, R0, false, false);
		const FBox B = MeshBounds(A);
		TestTrue(TEXT("10 steps rise about 200"), B.GetSize().Z > 190.0 && B.GetSize().Z < 215.0);
		TestTrue(TEXT("10 steps run about 300"), B.GetSize().X > 290.0 && B.GetSize().X < 330.0);
		TestTrue(TEXT("stairs are 100 wide"), FMath::IsNearlyEqual(B.GetSize().Y, 100.0, 1.0));
	}
	{
		ADynamicMeshActor* A = Make(TEXT("SCurved"));
		UModellingPrimitivesToolset::AddCurvedStairs(A->GetActorLabel(), 12, 100.f, 20.f, 150.f, 180.f, FVector::ZeroVector, R0, false, false);
		TestTrue(TEXT("curved stairs exist and climb"), TriCount(A) > 0 && MeshBounds(A).GetSize().Z > 200.0);
	}

	// Arch: correct size, and a real opening (checked with rays).
	{
		ADynamicMeshActor* A = Make(TEXT("SArch"));
		UModellingPrimitivesToolset::AddArch(A->GetActorLabel(), 200.f, 250.f, 40.f, 30.f, FVector::ZeroVector, R0, 16, false);
		const FBox B = MeshBounds(A);
		TestTrue(TEXT("arch is 200 wide, 40 deep, 250 tall"),
			FMath::IsNearlyEqual(B.GetSize().X, 200.0, 1.0) && FMath::IsNearlyEqual(B.GetSize().Y, 40.0, 1.0) && FMath::IsNearlyEqual(B.GetSize().Z, 250.0, 1.0));
		TestTrue(TEXT("arch is centred on the location"), FMath::IsNearlyEqual(B.GetCenter().Z, 0.0, 1.0) && FMath::IsNearlyEqual(B.GetCenter().X, 0.0, 1.0));
		TestFalse(TEXT("arch faces outward"), DiagnoseMesh(A).bInsideOut);

		const auto Hit = [&](const FVector& From, const FVector& Dir) { TSharedPtr<FJsonObject> J = ParseJson(UModellingMeasureToolset::Raycast(From, Dir, 10000.f, A->GetActorLabel())); bool bHit = false; return J.IsValid() && J->TryGetBoolField(TEXT("hit"), bHit) && bHit; };
		TestFalse(TEXT("the doorway is open"), Hit(FVector(0, -500, -50), FVector(0, 1, 0)));
		TestTrue(TEXT("the left pier is solid"), Hit(FVector(-85, -500, -50), FVector(0, 1, 0)));
		TestTrue(TEXT("the right pier is solid"), Hit(FVector(85, -500, -50), FVector(0, 1, 0)));
		TestTrue(TEXT("the top of the arch is solid"), Hit(FVector(7, -500, 115), FVector(0, 1, 0)) && Hit(FVector(-7, -500, 115), FVector(0, 1, 0)));
		TestFalse(TEXT("just under the curve is open"), Hit(FVector(7, -500, 80), FVector(0, 1, 0)));
	}
	{
		ADynamicMeshActor* A = Make(TEXT("SArchBad"));
		UModellingPrimitivesToolset::AddArch(A->GetActorLabel(), 200.f, 250.f, 40.f, 120.f, FVector::ZeroVector, R0, 16, false); // band wider than half the width
		TestEqual(TEXT("impossible arch is rejected"), TriCount(A), 0);
	}

	// Sweep: a round pipe along an L-shaped path.
	{
		ADynamicMeshActor* A = Make(TEXT("SSweep"));
		TArray<FVector2D> Circle;
		for (int32 i = 0; i < 8; ++i) { const double Angle = 2.0 * PI * i / 8; Circle.Add(FVector2D(5.0 * FMath::Cos(Angle), 5.0 * FMath::Sin(Angle))); }
		UModellingPrimitivesToolset::AddSweep(A->GetActorLabel(), Circle, { FVector(0, 0, 0), FVector(100, 0, 0), FVector(100, 100, 0) }, false, true, false);
		const FBox B = MeshBounds(A);
		TestTrue(TEXT("pipe has geometry"), TriCount(A) > 0);
		TestTrue(TEXT("pipe follows the path"), B.Max.X > 99.0 && B.Max.X < 110.0 && B.Max.Y > 99.0 && B.Max.Y < 110.0);
		TestTrue(TEXT("pipe is thin"), B.Min.Z > -6.0 && B.Max.Z < 6.0);
		TestFalse(TEXT("pipe faces outward"), DiagnoseMesh(A).bInsideOut);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingMeasureTest, "ModellingToolset.Measure", TestFlags)
bool FModellingMeasureTest::RunTest(const FString& Parameters)
{
	FActorCleanup Cleanup;
	const FRotator R0 = FRotator::ZeroRotator;
	ADynamicMeshActor* A = Cleanup.Track(CreateMeshActor(TEXT("MeasA"), FVector::ZeroVector, R0));
	ADynamicMeshActor* B = Cleanup.Track(CreateMeshActor(TEXT("MeasB"), FVector(300, 0, 0), R0));
	UModellingPrimitivesToolset::AddBox(A->GetActorLabel(), FVector(100, 100, 100), FVector::ZeroVector, R0, false);
	UModellingPrimitivesToolset::AddBox(B->GetActorLabel(), FVector(100, 100, 100), FVector::ZeroVector, R0, false);
	const FString NA = A->GetActorLabel(), NB = B->GetActorLabel();
	const FString Both = NA + TEXT(",") + NB;

	// Overall size: x from -50 to 350, y 100, z 100.
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingMeasureToolset::MeasureModel(Both));
		TestTrue(TEXT("model measured"), J.IsValid());
		if (J.IsValid())
		{
			TestTrue(TEXT("width is 400"), FMath::IsNearlyEqual(J->GetNumberField(TEXT("width_x_cm")), 400.0, 0.5));
			TestTrue(TEXT("depth is 100"), FMath::IsNearlyEqual(J->GetNumberField(TEXT("depth_y_cm")), 100.0, 0.5));
			TestTrue(TEXT("height is 100"), FMath::IsNearlyEqual(J->GetNumberField(TEXT("height_z_cm")), 100.0, 0.5));
		}
	}
	// Gap between the cubes: 250 - 50 = 200.
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingMeasureToolset::MeasureDistance(NA, NB));
		TestTrue(TEXT("distance measured"), J.IsValid());
		if (J.IsValid())
		{
			TestTrue(TEXT("surface gap is 200"), FMath::IsNearlyEqual(J->GetNumberField(TEXT("surface_gap_cm")), 200.0, 0.5));
			TestTrue(TEXT("centres are 300 apart"), FMath::IsNearlyEqual(J->GetNumberField(TEXT("center_distance_cm")), 300.0, 0.5));
		}
	}
	// Moving a part changes the answer.
	{
		B->SetActorLocation(FVector(100, 0, 0)); // now x 50..150: touching A's face
		TSharedPtr<FJsonObject> J = ParseJson(UModellingMeasureToolset::MeasureDistance(NA, NB));
		TestTrue(TEXT("touching parts have no gap"), J.IsValid() && J->GetNumberField(TEXT("surface_gap_cm")) < 0.1);
		B->SetActorLocation(FVector(300, 0, 0));
	}
	// Rays.
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingMeasureToolset::Raycast(FVector(-500, 0, 0), FVector(1, 0, 0), 10000.f, Both));
		TestTrue(TEXT("ray from the left hits cube A"), J.IsValid() && J->GetBoolField(TEXT("hit")) && J->GetStringField(TEXT("actor")) == NA);
		if (J.IsValid() && J->HasField(TEXT("distance_cm"))) { TestTrue(TEXT("hit is 450 away"), FMath::IsNearlyEqual(J->GetNumberField(TEXT("distance_cm")), 450.0, 0.5)); }

		J = ParseJson(UModellingMeasureToolset::Raycast(FVector(300, 0, 500), FVector(0, 0, -1), 10000.f, Both));
		TestTrue(TEXT("ray from above hits the top of cube B"), J.IsValid() && J->GetBoolField(TEXT("hit")) && J->GetStringField(TEXT("actor")) == NB);
		if (J.IsValid() && J->HasField(TEXT("point"))) { TestTrue(TEXT("the top is at z=50"), FMath::IsNearlyEqual(J->GetObjectField(TEXT("point"))->GetNumberField(TEXT("z")), 50.0, 0.5)); }

		J = ParseJson(UModellingMeasureToolset::Raycast(FVector(150, 0, 500), FVector(0, 0, -1), 10000.f, Both));
		TestTrue(TEXT("ray between the cubes misses"), J.IsValid() && !J->GetBoolField(TEXT("hit")));

		J = ParseJson(UModellingMeasureToolset::Raycast(FVector(-500, 0, 0), FVector(1, 0, 0), 100.f, Both));
		TestTrue(TEXT("ray beyond max distance misses"), J.IsValid() && !J->GetBoolField(TEXT("hit")));
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingMaterialsTest, "ModellingToolset.Materials", TestFlags)
bool FModellingMaterialsTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld()) { AddError(TEXT("No editor world.")); return false; }
	FActorCleanup Cleanup;
	const FRotator R0 = FRotator::ZeroRotator;

	// Remove only the material assets this test makes.
	struct FMaterialCleanup
	{
		~FMaterialCleanup()
		{
			const FString Dir = FPackageName::LongPackageNameToFilename(TEXT("/Game/ModellingToolset/Materials/"));
			TArray<FString> Files;
			IFileManager::Get().FindFiles(Files, *(Dir + TEXT("MI_MtMat*.uasset")), true, false);
			for (const FString& F : Files)
			{
				const FString Name = FPaths::GetBaseFilename(F);
				if (UObject* Obj = FindObject<UObject>(nullptr, *(TEXT("/Game/ModellingToolset/Materials/") + Name + TEXT(".") + Name)))
				{
					FAssetRegistryModule::AssetDeleted(Obj);
					Obj->MarkAsGarbage();
				}
				IFileManager::Get().Delete(*(Dir + F), false, true);
			}
		}
	} MaterialCleanup;

	// Bad input.
	TestTrue(TEXT("bad hex rejected"), UModellingMaterialsToolset::CreateColorMaterial(TEXT("MtMatBad"), TEXT("not-a-colour"), 0.5f, 0.f, 0.f).IsEmpty());
	TestTrue(TEXT("short hex rejected"), UModellingMaterialsToolset::CreateColorMaterial(TEXT("MtMatBad"), TEXT("#FFF"), 0.5f, 0.f, 0.f).IsEmpty());

	// A material with the right colour, roughness and metallic values.
	const FString Created = UModellingMaterialsToolset::CreateColorMaterial(TEXT("MtMatRed"), TEXT("#C03A2B"), 0.3f, 0.8f, 0.f);
	TSharedPtr<FJsonObject> CreatedJson = ParseJson(Created);
	TestTrue(TEXT("material created"), CreatedJson.IsValid() && !CreatedJson->GetStringField(TEXT("material")).IsEmpty());
	if (CreatedJson.IsValid())
	{
		UMaterialInstanceConstant* MI = Cast<UMaterialInstanceConstant>(FindObject<UObject>(nullptr, *CreatedJson->GetStringField(TEXT("material"))));
		if (TestNotNull(TEXT("material instance exists"), MI))
		{
			FLinearColor Colour; float Roughness = -1.f, Metallic = -1.f;
			TestTrue(TEXT("has a Color parameter"), MI->GetVectorParameterValue(FHashedMaterialParameterInfo(TEXT("Color")), Colour));
			const FLinearColor Expected = FLinearColor::FromSRGBColor(FColor::FromHex(TEXT("C03A2B")));
			TestTrue(TEXT("colour matches the hex"), FMath::Abs(Colour.R - Expected.R) < 0.01f && FMath::Abs(Colour.G - Expected.G) < 0.01f && FMath::Abs(Colour.B - Expected.B) < 0.01f);
			TestTrue(TEXT("has Roughness"), MI->GetScalarParameterValue(FHashedMaterialParameterInfo(TEXT("Roughness")), Roughness) && FMath::IsNearlyEqual(Roughness, 0.3f, 0.01f));
			TestTrue(TEXT("has Metallic"), MI->GetScalarParameterValue(FHashedMaterialParameterInfo(TEXT("Metallic")), Metallic) && FMath::IsNearlyEqual(Metallic, 0.8f, 0.01f));
		}
	}
	// Updating an existing material changes its colour.
	UModellingMaterialsToolset::CreateColorMaterial(TEXT("MtMatRed"), TEXT("#00FF00"), 0.3f, 0.8f, 0.f);
	if (CreatedJson.IsValid())
	{
		if (UMaterialInstanceConstant* MI = Cast<UMaterialInstanceConstant>(FindObject<UObject>(nullptr, *CreatedJson->GetStringField(TEXT("material")))))
		{
			FLinearColor Colour; MI->GetVectorParameterValue(FHashedMaterialParameterInfo(TEXT("Color")), Colour);
			TestTrue(TEXT("the same name updates the colour"), Colour.G > 0.9f && Colour.R < 0.05f);
		}
	}

	// Painting a part and then some of its faces.
	ADynamicMeshActor* Part = Cleanup.Track(CreateMeshActor(TEXT("MtMatBox"), FVector::ZeroVector, R0));
	UModellingPrimitivesToolset::AddBox(Part->GetActorLabel(), FVector(100, 100, 100), FVector::ZeroVector, R0, false);
	const FString Name = Part->GetActorLabel();

	TestFalse(TEXT("paint part works"), UModellingMaterialsToolset::PaintPart(Name, TEXT("#FFFFFF"), 0.7f, 0.f, TEXT("MtMatWall")).IsEmpty());
	{
		TSharedPtr<FJsonValue> Dummy;
		TArray<TSharedPtr<FJsonValue>> Slots;
		FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(UModellingMaterialsToolset::ListMaterialSlots(Name)), Slots);
		TestEqual(TEXT("one slot after painting the part"), Slots.Num(), 1);
		if (Slots.Num() == 1) { TestEqual(TEXT("all 12 faces use slot 0"), static_cast<int32>(Slots[0]->AsObject()->GetNumberField(TEXT("faces"))), 12); }
	}

	FModellingSelection Top; Top.Mode = TEXT("normal"); Top.A = FVector(0, 0, 1); Top.Scalar = 10.f;
	const FString Painted = UModellingMaterialsToolset::PaintFaces(Name, Top, TEXT("#C03A2B"), 0.5f, 0.f, TEXT("MtMatRoof"));
	TSharedPtr<FJsonObject> PaintedJson = ParseJson(Painted);
	TestTrue(TEXT("paint faces works and uses slot 1"), PaintedJson.IsValid() && static_cast<int32>(PaintedJson->GetNumberField(TEXT("slot"))) == 1);
	{
		TArray<TSharedPtr<FJsonValue>> Slots;
		FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(UModellingMaterialsToolset::ListMaterialSlots(Name)), Slots);
		TestEqual(TEXT("two slots now"), Slots.Num(), 2);
		if (Slots.Num() == 2)
		{
			TestEqual(TEXT("the top has 2 triangles in slot 1"), static_cast<int32>(Slots[1]->AsObject()->GetNumberField(TEXT("faces"))), 2);
			TestEqual(TEXT("the rest keeps slot 0"), static_cast<int32>(Slots[0]->AsObject()->GetNumberField(TEXT("faces"))), 10);
			TestTrue(TEXT("slot 1 is the roof material"), Slots[1]->AsObject()->GetStringField(TEXT("material")).Contains(TEXT("MtMatRoof")));
		}
	}
	// Painting the same colour again reuses the slot.
	UModellingMaterialsToolset::PaintFaces(Name, Top, TEXT("#C03A2B"), 0.5f, 0.f, TEXT("MtMatRoof"));
	{
		TArray<TSharedPtr<FJsonValue>> Slots;
		FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(UModellingMaterialsToolset::ListMaterialSlots(Name)), Slots);
		TestEqual(TEXT("the same material does not add a slot"), Slots.Num(), 2);
	}
	// A cut with an unpainted cutter must not put the grey checker on the cut faces.
	{
		ADynamicMeshActor* Cutter = Cleanup.Track(CreateMeshActor(TEXT("MtMatCutter"), FVector(40, 0, 0), R0));
		UModellingPrimitivesToolset::AddBox(Cutter->GetActorLabel(), FVector(40, 40, 40), FVector::ZeroVector, R0, false);
		UModellingEditToolset::BooleanOp(Name, Cutter->GetActorLabel(), TEXT("subtract"), true);
		const FMeshDiagnostics D = DiagnoseMesh(Part);
		TestEqual(TEXT("no faces point at a missing material after the cut"), D.FacesWithMissingMaterial, 0);
		TestFalse(TEXT("the checker material did not become a slot"), UModellingMaterialsToolset::ListMaterialSlots(Name).Contains(TEXT("WorldGridMaterial")));
		TArray<TSharedPtr<FJsonValue>> Slots;
		FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(UModellingMaterialsToolset::ListMaterialSlots(Name)), Slots);
		int32 PaintedFaces = 0;
		for (const TSharedPtr<FJsonValue>& S : Slots) { if (S->AsObject()->GetStringField(TEXT("material")).Contains(TEXT("MI_MtMat"))) { PaintedFaces += static_cast<int32>(S->AsObject()->GetNumberField(TEXT("faces"))); } }
		TestEqual(TEXT("every face still has a painted colour"), PaintedFaces, TriCount(Part));
	}
	// Merging a painted part into another keeps both colours.
	{
		ADynamicMeshActor* Other = Cleanup.Track(CreateMeshActor(TEXT("MtMatOther"), FVector(0, 300, 0), R0));
		UModellingPrimitivesToolset::AddBox(Other->GetActorLabel(), FVector(50, 50, 50), FVector::ZeroVector, R0, false);
		UModellingMaterialsToolset::PaintPart(Other->GetActorLabel(), TEXT("#2244AA"), 0.5f, 0.f, TEXT("MtMatBlue"));
		UModellingEditToolset::CombineActors(Name, Other->GetActorLabel(), true);
		const FString SlotsText = UModellingMaterialsToolset::ListMaterialSlots(Name);
		TestTrue(TEXT("merged part keeps the blue material"), SlotsText.Contains(TEXT("MI_MtMatBlue")));
		TestEqual(TEXT("merge leaves no faces without a material"), DiagnoseMesh(Part).FacesWithMissingMaterial, 0);
	}

	// Painted slots survive saving to a StaticMesh.
	TestTrue(TEXT("assign an engine material"), !UModellingMaterialsToolset::AssignMaterial(Name, 2, TEXT("/Engine/BasicShapes/BasicShapeMaterial")).IsEmpty());
	TestTrue(TEXT("bad material path rejected"), UModellingMaterialsToolset::AssignMaterial(Name, 0, TEXT("/Game/DoesNotExist/Nothing")).IsEmpty());
	TestTrue(TEXT("non-game path rejected"), UModellingMaterialsToolset::AssignMaterial(Name, 0, TEXT("/Script/Evil")).IsEmpty());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingReferenceTest, "ModellingToolset.Reference", TestFlags)
bool FModellingReferenceTest::RunTest(const FString& Parameters)
{
	EnsureWorkspaceFolders();
	const FString Dir = GetReferencesDir();

	// Test files, removed at the end.
	TArray<FString> Made;
	auto Cleanup = [&Made]() { for (const FString& F : Made) { IFileManager::Get().Delete(*F, false, true); } };
	auto WriteImage = [&](const FString& Name, int32 W, int32 H, TFunctionRef<FColor(int32, int32)> Pixel)
	{
		TArray<FColor> Px; Px.SetNumUninitialized(W * H);
		for (int32 Y = 0; Y < H; ++Y) { for (int32 X = 0; X < W; ++X) { Px[Y * W + X] = Pixel(X, Y); } }
		SavePng(Dir / Name, Px, FIntPoint(W, H));
		Made.Add(Dir / Name);
	};

	// Labels from file names and notes.
	{
		FFileHelper::SaveStringToFile(TEXT("view: back\nheight_cm: 1200\nwidth_cm: 300\nsome other note"), *(Dir / TEXT("MtRefNotes.txt")));
		Made.Add(Dir / TEXT("MtRefNotes.txt"));
		const FReferenceMeta Meta = ReadReferenceMeta(TEXT("MtRefNotes.png"));
		TestEqual(TEXT("view from notes"), Meta.View, FString(TEXT("back")));
		TestTrue(TEXT("sizes from notes"), FMath::IsNearlyEqual(Meta.HeightCm, 1200.0) && FMath::IsNearlyEqual(Meta.WidthCm, 300.0));
		TestEqual(TEXT("view from file name"), ReadReferenceMeta(TEXT("Lighthouse_front.png")).View, FString(TEXT("front")));
		TestEqual(TEXT("side means right"), ReadReferenceMeta(TEXT("Lighthouse_side.jpg")).View, FString(TEXT("right")));
		TestEqual(TEXT("unlabelled stays unknown"), ReadReferenceMeta(TEXT("photo1.png")).View, FString());
	}

	// Palette of a picture that is half red, half off-white.
	WriteImage(TEXT("MtRefPalette.png"), 100, 100, [](int32 X, int32) { return X < 50 ? FColor(200, 40, 40) : FColor(240, 240, 240); });
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingMaterialsToolset::GetReferencePalette(TEXT("MtRefPalette.png"), 2, false, 0.f, 0.f, 1.f, 1.f));
		TestTrue(TEXT("palette returned"), J.IsValid());
		if (J.IsValid())
		{
			const TArray<TSharedPtr<FJsonValue>>& Colors = J->GetArrayField(TEXT("colors"));
			TestEqual(TEXT("two colours found"), Colors.Num(), 2);
			TArray<FString> Hexes;
			for (const TSharedPtr<FJsonValue>& C : Colors) { Hexes.Add(C->AsObject()->GetStringField(TEXT("hex"))); }
			TestTrue(TEXT("red found"), Hexes.Contains(TEXT("#C82828")));
			TestTrue(TEXT("off-white found"), Hexes.Contains(TEXT("#F0F0F0")));
			if (Colors.Num() == 2) { TestTrue(TEXT("each covers half"), FMath::IsNearlyEqual(Colors[0]->AsObject()->GetNumberField(TEXT("percent")), 50.0, 3.0)); }
		}
		// Only the left half.
		J = ParseJson(UModellingMaterialsToolset::GetReferencePalette(TEXT("MtRefPalette.png"), 2, false, 0.f, 0.f, 0.4f, 1.f));
		if (J.IsValid() && J->GetArrayField(TEXT("colors")).Num() > 0)
		{
			TestEqual(TEXT("region of the left half is red"), J->GetArrayField(TEXT("colors"))[0]->AsObject()->GetStringField(TEXT("hex")), FString(TEXT("#C82828")));
		}
	}
	// A red square on a white background: the background is ignored.
	WriteImage(TEXT("MtRefSquare.png"), 100, 100, [](int32 X, int32 Y) { return (X > 30 && X < 70 && Y > 30 && Y < 70) ? FColor(200, 40, 40) : FColor(255, 255, 255); });
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingMaterialsToolset::GetReferencePalette(TEXT("MtRefSquare.png"), 3, true, 0.f, 0.f, 1.f, 1.f));
		TestTrue(TEXT("palette with background ignored"), J.IsValid());
		if (J.IsValid() && J->GetArrayField(TEXT("colors")).Num() > 0)
		{
			TestEqual(TEXT("only the object colour remains"), J->GetArrayField(TEXT("colors"))[0]->AsObject()->GetStringField(TEXT("hex")), FString(TEXT("#C82828")));
		}
	}
	TestTrue(TEXT("palette rejects folders in the name"), UModellingMaterialsToolset::GetReferencePalette(TEXT("../x.png")).IsEmpty());
	TestTrue(TEXT("palette rejects unknown files"), UModellingMaterialsToolset::GetReferencePalette(TEXT("MtDoesNotExist.png")).IsEmpty());

	// ListReferences reports the label.
	WriteImage(TEXT("MtRefList_front.png"), 16, 16, [](int32, int32) { return FColor::White; });
	{
		const FString List = UModellingReferenceToolset::ListReferences();
		TestTrue(TEXT("list shows the label from the file name"), List.Contains(TEXT("MtRefList_front.png")) && List.Contains(TEXT("\"view\": \"front\"")));
	}
	Cleanup();
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingCompareTest, "ModellingToolset.Compare", TestFlags)
bool FModellingCompareTest::RunTest(const FString& Parameters)
{
	// Silhouettes on a dark background, built directly, so the maths is tested without rendering.
	const int32 N = 128;
	auto Picture = [&](TFunctionRef<bool(int32, int32)> Inside)
	{
		TArray<FColor> Px; Px.Init(FColor(20, 20, 20), N * N);
		for (int32 Y = 0; Y < N; ++Y) { for (int32 X = 0; X < N; ++X) { if (Inside(X, Y)) { Px[Y * N + X] = FColor(200, 160, 120); } } }
		return Px;
	};
	auto MaskOf = [&](const TArray<FColor>& Px) { FMask M = MakeMask(Px, FIntPoint(N, N), 30.0); return M; };
	auto Normalised = [&](const FMask& M) { FIntRect B; MaskBounds(M, B); return NormaliseMask(M, B, 128); };

	const TArray<FColor> Rect = Picture([](int32 X, int32 Y) { return X > 40 && X < 90 && Y > 20 && Y < 110; });                 // tall rectangle
	const TArray<FColor> RectMovedSmaller = Picture([](int32 X, int32 Y) { return X > 10 && X < 35 && Y > 10 && Y < 55; });       // same proportions, other place and size
	const TArray<FColor> Triangle = Picture([](int32 X, int32 Y) { return Y > 20 && Y < 110 && FMath::Abs(X - 64) < (Y - 20) * 0.28; }); // pointing up

	// Bounds and masks.
	{
		const FMask M = MaskOf(Rect);
		FIntRect B;
		TestTrue(TEXT("bounds found"), MaskBounds(M, B));
		TestTrue(TEXT("bounds are right"), B.Min.X == 41 && B.Max.X == 90 && B.Min.Y == 21 && B.Max.Y == 110);
		FMask Empty = MaskOf(Picture([](int32, int32) { return false; }));
		TestFalse(TEXT("an empty picture has no bounds"), MaskBounds(Empty, B));
	}
	// Same shape at a different size and position is a perfect match.
	{
		const double Iou = IntersectionOverUnion(Normalised(MaskOf(Rect)), Normalised(MaskOf(RectMovedSmaller)));
		TestTrue(*FString::Printf(TEXT("scale and position do not matter (IoU %.3f)"), Iou), Iou > 0.95);
	}
	// Different shapes score lower and the differences are located.
	{
		const FMask Ref = Normalised(MaskOf(Rect));
		const FMask Model = Normalised(MaskOf(Triangle));
		const double Iou = IntersectionOverUnion(Ref, Model);
		TestTrue(*FString::Printf(TEXT("a triangle is not a rectangle (IoU %.3f)"), Iou), Iou > 0.3 && Iou < 0.75);

		const TArray<FProfileDifference> Bands = CompareWidthBands(Ref, Model, 8, 0.12);
		bool bTopNarrower = false;
		for (const FProfileDifference& D : Bands) { if (D.FromPercent == 0 && D.DifferencePercent < -12.0) { bTopNarrower = true; } }
		TestTrue(TEXT("the top of the model is reported as narrower"), bTopNarrower);
		TestTrue(TEXT("an identical shape has no differences"), CompareWidthBands(Ref, Ref, 8, 0.05).IsEmpty() && CompareHeightBands(Ref, Ref, 8, 0.05).IsEmpty());
	}
	// Specks are ignored.
	{
		TArray<FColor> Speckled = Rect;
		Speckled[5 * N + 5] = FColor(255, 255, 255);
		Speckled[6 * N + 5] = FColor(255, 255, 255);
		FMask M = MaskOf(Speckled);
		RemoveSmallComponents(M, 0.004);
		FIntRect B; MaskBounds(M, B);
		TestTrue(TEXT("a speck does not stretch the bounds"), B.Min.X == 41 && B.Min.Y == 21);
	}
	// A floor shadow under the object on a white background is not part of the object.
	{
		auto PictureOnWhite = [&](TFunctionRef<FColor(int32, int32)> Pixel)
		{
			TArray<FColor> Px; Px.SetNumUninitialized(N * N);
			for (int32 Y = 0; Y < N; ++Y) { for (int32 X = 0; X < N; ++X) { Px[Y * N + X] = Pixel(X, Y); } }
			return Px;
		};
		const TArray<FColor> WithShadow = PictureOnWhite([](int32 X, int32 Y)
		{
			if (X > 40 && X < 90 && Y > 20 && Y < 100) { return FColor(190, 60, 50); }   // red object
			if (X > 20 && X < 115 && Y >= 100 && Y < 112) { return FColor(205, 205, 205); } // soft grey shadow, wider than the object
			return FColor(250, 250, 250);
		});
		FMask M = MakeMask(WithShadow, FIntPoint(N, N), 30.0);
		FIntRect Before; MaskBounds(M, Before);
		TestTrue(TEXT("without shadow handling the shadow widens the outline"), Before.Min.X <= 21 && Before.Max.Y >= 111);
		const int32 Removed = RemoveFloorShadow(M, WithShadow, FIntPoint(N, N));
		FIntRect After; MaskBounds(M, After);
		TestTrue(TEXT("shadow pixels were removed"), Removed > 500);
		TestTrue(TEXT("the outline is just the object again"), After.Min.X == 41 && After.Max.X == 90 && After.Max.Y == 100);
		// A dark-grey object on white must survive (it is far darker than a shadow).
		const TArray<FColor> DarkObject = PictureOnWhite([](int32 X, int32 Y) { return (X > 40 && X < 90 && Y > 20 && Y < 100) ? FColor(60, 60, 60) : FColor(250, 250, 250); });
		FMask M2 = MakeMask(DarkObject, FIntPoint(N, N), 30.0);
		RemoveFloorShadow(M2, DarkObject, FIntPoint(N, N));
		FIntRect B2; TestTrue(TEXT("a dark grey object is kept"), MaskBounds(M2, B2) && B2.Width() == 49);
	}
	// Errors that need no rendering.
	{
		const FCompareResult R1 = CompareToReference(TEXT("MtNoSuchReference.png"), TEXT("front"), FString());
		TestTrue(TEXT("unknown reference is reported"), !R1.bOk && R1.Error.Contains(TEXT("not found")));
		const FCompareResult R2 = CompareToReference(TEXT("../x.png"), TEXT("front"), FString());
		TestFalse(TEXT("path tricks are rejected"), R2.bOk);
	}
	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingCancelTest, "ModellingToolset.Cancel", TestFlags)
bool FModellingCancelTest::RunTest(const FString& Parameters)
{
	ResetJob();
	FString Error, Json;

	// Cancel while the AI is working: every job tool tells it to stop.
	TestTrue(TEXT("job started"), StartJob(TEXT("A tower"), TEXT("MtCancel"), Error));
	UModellingJobToolset::GetModellingJob();
	TestEqual(TEXT("working"), GetJob().Status, EJobStatus::Working);
	ResetJob(/*bCancelledByUser=*/true);
	TestEqual(TEXT("back to idle"), GetJob().Status, EJobStatus::Idle);
	TestTrue(TEXT("flagged as cancelled"), GetJob().bCancelled);

	TestTrue(TEXT("the AI is told it was cancelled"), UModellingJobToolset::GetModellingJob().Contains(TEXT("cancelled")));
	TestTrue(TEXT("waiting returns cancelled"), TryConsumeDecision(Json) && Json.Contains(TEXT("cancelled")));
	TestTrue(TEXT("progress reports are refused"), UModellingJobToolset::ReportProgress(TEXT("still going")).IsEmpty());
	TestTrue(TEXT("review requests are refused"), UModellingJobToolset::RequestReview(TEXT("done")).IsEmpty());

	// A new job clears the cancellation.
	TestTrue(TEXT("new job"), StartJob(TEXT("A house"), TEXT("MtCancel"), Error));
	TestFalse(TEXT("cancel flag cleared"), GetJob().bCancelled);

	// Resetting an idle job, or a finished one, is not a cancellation.
	ResetJob();
	ResetJob(true);
	TestFalse(TEXT("cancelling nothing is not a cancellation"), GetJob().bCancelled);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingBatchTest, "ModellingToolset.Batch", TestFlags)
bool FModellingBatchTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld()) { AddError(TEXT("No editor world.")); return false; }
	FActorCleanup Cleanup;

	// Several tools in one call, with arguments left to their defaults.
	const FString Steps = TEXT(R"json([
		{"tool":"CreateMeshActor","args":{"Name":"MtBatchTower","Location":{"X":0,"Y":0,"Z":0},"Rotation":{"Pitch":0,"Yaw":0,"Roll":0}}},
		{"tool":"AddCylinder","args":{"Name":"MtBatchTower","Radius":50,"Height":300,"Location":{"X":0,"Y":0,"Z":150},"Rotation":{"Pitch":0,"Yaw":0,"Roll":0}}},
		{"tool":"AddCone","args":{"Name":"MtBatchTower","BaseRadius":60,"TopRadius":0,"Height":100,"Location":{"X":0,"Y":0,"Z":350},"Rotation":{"Pitch":0,"Yaw":0,"Roll":0}}},
		{"tool":"MeasureModel","args":{"ActorNames":"MtBatchTower"}}
	])json");
	TSharedPtr<FJsonObject> J = ParseJson(UModellingBatchToolset::RunBatch(Steps, false));
	if (!TestTrue(TEXT("batch returned JSON"), J.IsValid())) { return false; }
	TestEqual(TEXT("all 4 steps completed"), static_cast<int32>(J->GetNumberField(TEXT("steps_completed"))), 4);
	TestFalse(TEXT("nothing failed"), J->HasField(TEXT("failed_at_step")));
	ADynamicMeshActor* Tower = FindMeshActor(TEXT("MtBatchTower"));
	Cleanup.Track(Tower);
	if (TestNotNull(TEXT("the tower exists"), Tower))
	{
		TestTrue(TEXT("the batch built the geometry"), TriCount(Tower) > 0);
		// The cylinder default (24 segments, capped) came from the tool's own defaults, so the sizes are right.
		TestTrue(TEXT("tower is about 400 tall"), FMath::IsNearlyEqual(Tower->GetComponentsBoundingBox(true).GetSize().Z, 400.0, 2.0));
	}
	// The last step's result is embedded as readable JSON, not an escaped string.
	const TArray<TSharedPtr<FJsonValue>>& Results = J->GetArrayField(TEXT("results"));
	TestTrue(TEXT("results embed JSON"), Results.Num() == 4 && Results[3]->AsObject()->HasTypedField<EJson::Object>(TEXT("result")));

	// A failing step stops the batch and is reported by number.
	{
		const FString Bad = TEXT(R"json([
			{"tool":"AddBox","args":{"Name":"MtBatchTower","Size":{"X":10,"Y":10,"Z":10},"Location":{"X":0,"Y":0,"Z":0},"Rotation":{"Pitch":0,"Yaw":0,"Roll":0}}},
			{"tool":"AddBox","args":{"Name":"NoSuchPart","Size":{"X":10,"Y":10,"Z":10},"Location":{"X":0,"Y":0,"Z":0},"Rotation":{"Pitch":0,"Yaw":0,"Roll":0}}},
			{"tool":"AddBox","args":{"Name":"MtBatchTower","Size":{"X":10,"Y":10,"Z":10},"Location":{"X":0,"Y":0,"Z":0},"Rotation":{"Pitch":0,"Yaw":0,"Roll":0}}}
		])json");
		const int32 Before = TriCount(Tower);
		J = ParseJson(UModellingBatchToolset::RunBatch(Bad, false));
		TestTrue(TEXT("failure reported at step 2"), J.IsValid() && static_cast<int32>(J->GetNumberField(TEXT("failed_at_step"))) == 2);
		TestTrue(TEXT("the error says which part is missing"), J.IsValid() && J->GetStringField(TEXT("first_error")).Contains(TEXT("NoSuchPart")));
		TestEqual(TEXT("it stopped before step 3"), static_cast<int32>(J->GetNumberField(TEXT("steps_run"))), 2);
		TestEqual(TEXT("step 1 was applied, step 3 was not"), TriCount(Tower), Before + 12);

		J = ParseJson(UModellingBatchToolset::RunBatch(Bad, true));
		TestTrue(TEXT("continue-on-error runs every step"), J.IsValid() && static_cast<int32>(J->GetNumberField(TEXT("steps_run"))) == 3 && static_cast<int32>(J->GetNumberField(TEXT("steps_completed"))) == 2);
	}

	// Things a batch must refuse.
	{
		J = ParseJson(UModellingBatchToolset::RunBatch(TEXT(R"json([{"tool":"RunBatch","args":{"StepsJson":"[]"}}])json"), false));
		TestTrue(TEXT("a batch cannot run a batch"), J.IsValid() && J->HasField(TEXT("failed_at_step")));
		J = ParseJson(UModellingBatchToolset::RunBatch(TEXT(R"json([{"tool":"CaptureViews","args":{}}])json"), false));
		TestTrue(TEXT("pictures are refused"), J.IsValid() && J->HasField(TEXT("failed_at_step")));
		J = ParseJson(UModellingBatchToolset::RunBatch(TEXT(R"json([{"tool":"DefinitelyNotATool"}])json"), false));
		TestTrue(TEXT("unknown tools are reported"), J.IsValid() && J->GetStringField(TEXT("first_error")).Contains(TEXT("DefinitelyNotATool")));
		TestTrue(TEXT("invalid JSON is rejected"), UModellingBatchToolset::RunBatch(TEXT("not json"), false).IsEmpty());
		TestTrue(TEXT("an empty list is rejected"), UModellingBatchToolset::RunBatch(TEXT("[]"), false).IsEmpty());
	}
	return true;
}


namespace
{
	/** Writes a small checker image (two colours) as a PNG. */
	void WriteCheckerPng(const FString& Path, int32 Size, FColor A, FColor B, int32 Cells)
	{
		TArray<FColor> Px; Px.SetNumUninitialized(Size * Size);
		for (int32 Y = 0; Y < Size; ++Y) { for (int32 X = 0; X < Size; ++X) { const bool bA = ((X * Cells / Size) + (Y * Cells / Size)) % 2 == 0; Px[Y * Size + X] = bA ? A : B; } }
		SavePng(Path, Px, FIntPoint(Size, Size));
	}

	/** Removes test texture assets and material instances made for a set. */
	void DeleteTextureSetAssets(const FString& SetName)
	{
		auto Kill = [](const FString& Folder, const FString& Pattern)
		{
			const FString Dir = FPackageName::LongPackageNameToFilename(Folder + TEXT("/"));
			TArray<FString> Files;
			IFileManager::Get().FindFiles(Files, *(Dir + Pattern), true, false);
			for (const FString& F : Files)
			{
				const FString Name = FPaths::GetBaseFilename(F);
				if (UObject* Obj = FindObject<UObject>(nullptr, *(Folder + TEXT("/") + Name + TEXT(".") + Name)))
				{
					FAssetRegistryModule::AssetDeleted(Obj);
					Obj->MarkAsGarbage();
				}
				IFileManager::Get().Delete(*(Dir + F), false, true);
			}
		};
		Kill(TEXT("/Game/ModellingToolset/Textures"), TEXT("T_") + SetName + TEXT("_*.uasset"));
		Kill(TEXT("/Game/ModellingToolset/Materials"), TEXT("MI_Tex_") + SetName + TEXT("_*.uasset"));
	}

	double UvTileRatio(ADynamicMeshActor* A)
	{
		// Mesh area in cm² divided by UV area in (100 cm)² tiles. 1 means one tile per 100 cm, as intended.
		FGeometryScriptMeshSelection All;
		UGeometryScriptLibrary_MeshSelectionFunctions::CreateSelectAllMeshSelection(GetDynamicMesh(A), All, EGeometryScriptMeshSelectionType::Triangles);
		double MeshArea = 0, UVArea = 0; FBox MB; FBox2D UB; bool bValid = false, bUnset = false;
		UGeometryScriptLibrary_MeshUVFunctions::GetMeshUVSizeInfo(GetDynamicMesh(A), 0, All, MeshArea, UVArea, MB, UB, bValid, bUnset, true);
		return UVArea > 0 ? (UVArea * 10000.0) / MeshArea : 0.0;
	}
}

namespace
{
	/** Removes material instances the surface tests make (names start with the given prefixes). */
	void DeleteGeneratedMaterials(const TArray<FString>& Prefixes)
	{
		const FString Folder = TEXT("/Game/ModellingToolset/Materials");
		const FString Dir = FPackageName::LongPackageNameToFilename(Folder + TEXT("/"));
		for (const FString& Prefix : Prefixes)
		{
			TArray<FString> Files;
			IFileManager::Get().FindFiles(Files, *(Dir + Prefix + TEXT("*.uasset")), true, false);
			for (const FString& F : Files)
			{
				const FString Name = FPaths::GetBaseFilename(F);
				if (UObject* Obj = FindObject<UObject>(nullptr, *(Folder + TEXT("/") + Name + TEXT(".") + Name))) { FAssetRegistryModule::AssetDeleted(Obj); Obj->MarkAsGarbage(); }
				IFileManager::Get().Delete(*(Dir + F), false, true);
			}
		}
	}
}

// Needs a real renderer (run with -RenderOffScreen, not -nullrhi). Saves pictures of a cream vase and box in every view mode for inspection.
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingRenderProbeTest, "ModellingToolset.RenderProbe", TestFlags)
bool FModellingRenderProbeTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld()) { AddError(TEXT("No editor world.")); return false; }
	if (!FApp::CanEverRender()) { AddWarning(TEXT("No renderer; skipped.")); return true; }
	FActorCleanup Cleanup;
	const FRotator R0 = FRotator::ZeroRotator;

	ADynamicMeshActor* Vase = Cleanup.Track(CreateMeshActor(TEXT("RpVase"), FVector::ZeroVector, R0));
	const TArray<FVector2D> Profile = { FVector2D(0, 0), FVector2D(18, 0), FVector2D(24, 30), FVector2D(14, 70), FVector2D(12, 85), FVector2D(16, 100), FVector2D(13, 100), FVector2D(10, 86), FVector2D(11, 70), FVector2D(20, 30), FVector2D(15, 4), FVector2D(0, 4) };
	UModellingPrimitivesToolset::AddRevolve(Vase->GetActorLabel(), Profile, FVector::ZeroVector, R0, 360.f, 32, true, false);
	UModellingMaterialsToolset::PaintPart(Vase->GetActorLabel(), TEXT("#F3E9D2"), 0.6f, 0.f, TEXT("RpCream"));
	FModellingSelection Top; Top.Mode = TEXT("box"); Top.A = FVector(-50, -50, 95); Top.B = FVector(50, 50, 101);
	UModellingMaterialsToolset::PaintFaces(Vase->GetActorLabel(), Top, TEXT("#C9A227"), 0.3f, 1.f, TEXT("RpGold"));

	// A cutter through the front, deleted by the boolean, like the AI's spiral cut.
	ADynamicMeshActor* Cutter = Cleanup.Track(CreateMeshActor(TEXT("RpCutter"), FVector(20, 0, 60), R0));
	UModellingPrimitivesToolset::AddBox(Cutter->GetActorLabel(), FVector(20, 12, 40), FVector::ZeroVector, FRotator(0, 0, 30), false);
	UModellingEditToolset::BooleanOp(Vase->GetActorLabel(), Cutter->GetActorLabel(), TEXT("subtract"), true);

	ADynamicMeshActor* Box = Cleanup.Track(CreateMeshActor(TEXT("RpBox"), FVector(0, 70, 25), R0));
	UModellingPrimitivesToolset::AddBox(Box->GetActorLabel(), FVector(40, 40, 50), FVector::ZeroVector, R0, false);
	UModellingMaterialsToolset::PaintPart(Box->GetActorLabel(), TEXT("#F3E9D2"), 0.6f, 0.f, TEXT("RpCream"));

	{
		const FMeshDiagnostics D = DiagnoseMesh(Vase);
		AddInfo(FString::Printf(TEXT("DIAG vase tris=%d open_edges=%d inside_out=%d missing_material_faces=%d slots=%d"), D.Triangles, D.OpenBoundaryEdges, D.bInsideOut, D.FacesWithMissingMaterial, D.MaterialSlots));
		AddInfo(TEXT("DIAG slots ") + UModellingMaterialsToolset::ListMaterialSlots(Vase->GetActorLabel()).Replace(TEXT("\r"), TEXT("")).Replace(TEXT("\n"), TEXT("")).Replace(TEXT("\t"), TEXT("")));
		TestFalse(TEXT("probe vase faces outward"), D.bInsideOut);
		TestEqual(TEXT("probe vase has no faces without a material"), D.FacesWithMissingMaterial, 0);
	}
	StartCaptureSession(TEXT("RenderProbe"));
	for (const TCHAR* Mode : { TEXT("lit"), TEXT("unlit"), TEXT("clay"), TEXT("normals") })
	{
		FCaptureRequest Req; Req.Views = TEXT("iso,front"); Req.ViewMode = Mode; Req.Resolution = 256; Req.bIsolate = true; Req.Label = Mode;
		const FCaptureResult R = ModellingToolset::CaptureViews(Req);
		TestTrue(*FString::Printf(TEXT("capture %s ok: %s"), Mode, *R.Error), R.bOk);
		if (R.bOk)
		{
			// Mean brightness of the middle of the first tile, where the vase is.
			auto Spot = [&R](int32 X, int32 Y) { const FColor C = R.Sheet[Y * R.SheetSize.X + X]; return FString::Printf(TEXT("(%d,%d,%d)"), C.R, C.G, C.B); };
			// iso tile: box top ~(85,140), box right face ~(110,185), vase belly ~(150,140). front tile (x+256): belly left ~(400,160), belly right ~(455,160), hole ~(430,120)
			AddInfo(FString::Printf(TEXT("RENDER %s boxTop=%s boxSide=%s vaseIso=%s frontBellyL=%s frontBellyR=%s hole=%s"), Mode,
				*Spot(85, 140), *Spot(110, 185), *Spot(150, 140), *Spot(400, 160), *Spot(455, 160), *Spot(430, 120)));
		}
	}

	// Texture: a checker set on the vase (world aligned) and on the box (UV mode after AutoUV); squares must stay square everywhere.
	{
		EnsureWorkspaceFolders();
		const FString Dir = GetTexturesDir();
		WriteCheckerPng(Dir / TEXT("RpChecker_albedo.png"), 64, FColor(40, 40, 40), FColor(230, 230, 230), 8);
		ON_SCOPE_EXIT { IFileManager::Get().Delete(*(Dir / TEXT("RpChecker_albedo.png")), false, true); DeleteTextureSetAssets(TEXT("RpChecker")); };

		TestFalse(TEXT("checker on the vase"), UModellingTextureToolset::ApplyTexturePart(Vase->GetActorLabel(), TEXT("RpChecker"), 40.f, true, TEXT(""), -1.f, -1.f).IsEmpty());
		UModellingTextureToolset::AutoUV(Box->GetActorLabel(), TEXT("box"), FModellingSelection());
		TestFalse(TEXT("checker on the box, UV mode"), UModellingTextureToolset::ApplyTexturePart(Box->GetActorLabel(), TEXT("RpChecker"), 40.f, false, TEXT(""), -1.f, -1.f).IsEmpty());
		FCaptureRequest Req; Req.Views = TEXT("iso,front"); Req.ViewMode = TEXT("lit"); Req.Resolution = 320; Req.bIsolate = true; Req.Label = TEXT("textured");
		const FCaptureResult R = ModellingToolset::CaptureViews(Req);
		TestTrue(TEXT("textured capture ok"), R.bOk);
		const FModellingCapture P = UModellingTextureToolset::PreviewMaterial(TEXT("RpChecker"), TEXT(""), 25.f);
		TestFalse(TEXT("preview rendered"), P.Image.Data.IsEmpty());
		AddInfo(TEXT("PREVIEW ") + P.Summary);
		// Put the vase back to cream for the comparison below.
		UModellingMaterialsToolset::PaintPart(Vase->GetActorLabel(), TEXT("#F3E9D2"), 0.6f, 0.f, TEXT("RpCream"));
	}

	// Library surfaces: worn brick tinted to a reference red on the vase, glass on the box, and a roof-tile preview.
	if (BuildSurfaceCatalogue(false).Num() >= 10)
	{
		TestFalse(TEXT("brick on the vase"), UModellingSurfaceToolset::ApplySurfacePart(Vase->GetActorLabel(), TEXT("Brick Wall Worn"), TEXT("#B0503C"), TEXT("auto"), 60.f, true).IsEmpty());
		TestFalse(TEXT("glass on the box"), UModellingSurfaceToolset::ApplyGlass(Box->GetActorLabel(), FModellingSelection(), TEXT("#DDEEFF"), 0.2f, 0.05f, 1.52f).IsEmpty());
		FCaptureRequest Req; Req.Views = TEXT("iso,front"); Req.ViewMode = TEXT("lit"); Req.Resolution = 320; Req.bIsolate = true; Req.Label = TEXT("surfaces");
		TestTrue(TEXT("surfaces capture ok"), ModellingToolset::CaptureViews(Req).bOk);
		const FModellingCapture P = UModellingSurfaceToolset::PreviewSurface(TEXT("Red Roof Tiles"), TEXT("#B0523A"), TEXT("auto"), 100.f);
		TestFalse(TEXT("roof preview rendered"), P.Image.Data.IsEmpty());
		AddInfo(TEXT("SURFPREVIEW ") + P.Summary);
		UModellingMaterialsToolset::PaintPart(Vase->GetActorLabel(), TEXT("#F3E9D2"), 0.6f, 0.f, TEXT("RpCream"));
		UModellingMaterialsToolset::PaintPart(Box->GetActorLabel(), TEXT("#F3E9D2"), 0.6f, 0.f, TEXT("RpCream"));
		DeleteGeneratedMaterials({ TEXT("MI_Tex_Brick_Wall"), TEXT("MI_Tex_Red_Roof"), TEXT("MI_Glass_") });
	}

	// Live comparison: a front picture of the vase itself, used as the reference, must match almost perfectly.
	{
		FCaptureRequest Req; Req.ActorNames = Vase->GetActorLabel(); Req.Views = TEXT("front"); Req.ViewMode = TEXT("lit"); Req.Resolution = 256; Req.bIsolate = true; Req.Label = TEXT("selfref");
		const FCaptureResult R = ModellingToolset::CaptureViews(Req);
		if (TestTrue(TEXT("self reference captured"), R.bOk))
		{
			EnsureWorkspaceFolders();
			const FString RefFile = GetReferencesDir() / TEXT("RpSelf_front.png");
			SavePng(RefFile, R.Sheet, R.SheetSize);
			const FCompareResult C = CompareToReference(TEXT("RpSelf_front.png"), TEXT(""), Vase->GetActorLabel());
			TestTrue(*FString::Printf(TEXT("comparison ran: %s"), *C.Error), C.bOk);
			if (C.bOk)
			{
				AddInfo(TEXT("COMPARE ") + C.SummaryJson);
				TSharedPtr<FJsonObject> J = ParseJson(C.SummaryJson);
				TestTrue(TEXT("the vase matches a picture of itself"), J.IsValid() && J->GetNumberField(TEXT("overlap_score")) > 0.9);
				TestTrue(TEXT("the view came from the file name"), J.IsValid() && J->GetStringField(TEXT("view")) == TEXT("front"));
			}
			IFileManager::Get().Delete(*RefFile, false, true);
		}
	}
	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingTexturesTest, "ModellingToolset.Textures", TestFlags)
bool FModellingTexturesTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld()) { AddError(TEXT("No editor world.")); return false; }
	FActorCleanup Cleanup;
	const FRotator R0 = FRotator::ZeroRotator;
	EnsureWorkspaceFolders();
	const FString Dir = GetTexturesDir();
	const FString SetName = TEXT("MtTex");

	// Test files and assets are removed however the test ends.
	struct FTexCleanup
	{
		FString Dir, SetName;
		~FTexCleanup()
		{
			for (const TCHAR* Suffix : { TEXT("_albedo.png"), TEXT("_normal.png"), TEXT("_roughness.png"), TEXT(".txt"), TEXT("Lone.png") })
			{
				IFileManager::Get().Delete(*(Dir / (SetName + Suffix)), false, true);
			}
			DeleteTextureSetAssets(SetName);
			DeleteTextureSetAssets(SetName + TEXT("Lone"));
			// Library test material.
			if (UObject* Obj = FindObject<UObject>(nullptr, TEXT("/Game/MtLibTest/M_RedBrickTest.M_RedBrickTest"))) { FAssetRegistryModule::AssetDeleted(Obj); Obj->MarkAsGarbage(); }
			IFileManager::Get().DeleteDirectory(*FPackageName::LongPackageNameToFilename(TEXT("/Game/MtLibTest/")), false, true);
			GetMutableDefault<UModellingToolsetSettings>()->MaterialLibraryFolder = TEXT("/Game/Materials");
		}
	} TexCleanup{ Dir, SetName };

	WriteCheckerPng(Dir / (SetName + TEXT("_albedo.png")), 64, FColor(200, 60, 50), FColor(240, 230, 220), 4);
	WriteCheckerPng(Dir / (SetName + TEXT("_normal.png")), 16, FColor(128, 128, 255), FColor(128, 128, 255), 1);
	WriteCheckerPng(Dir / (SetName + TEXT("_roughness.png")), 16, FColor(180, 180, 180), FColor(180, 180, 180), 1);
	FFileHelper::SaveStringToFile(TEXT("tile_cm: 50\nRed brick test set"), *(Dir / (SetName + TEXT(".txt"))));
	WriteCheckerPng(Dir / (SetName + TEXT("Lone.png")), 16, FColor::Blue, FColor::Blue, 1); // no suffix: counts as albedo of set "MtTexLone"

	// Listing.
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingTextureToolset::ListTextureSets());
		if (!TestTrue(TEXT("list returned"), J.IsValid())) { return false; }
		const TArray<TSharedPtr<FJsonValue>>& Sets = J->GetArrayField(TEXT("sets"));
		const TSharedPtr<FJsonValue>* Found = Sets.FindByPredicate([&](const TSharedPtr<FJsonValue>& V) { return V->AsObject()->GetStringField(TEXT("name")) == SetName; });
		if (TestNotNull(TEXT("set is listed"), Found))
		{
			const TSharedPtr<FJsonObject> S = (*Found)->AsObject();
			TestTrue(TEXT("maps detected"), S->GetBoolField(TEXT("has_albedo")) && S->GetBoolField(TEXT("has_normal")) && S->GetBoolField(TEXT("has_roughness")) && !S->GetBoolField(TEXT("has_metallic")));
			TestTrue(TEXT("tile size read from notes"), FMath::IsNearlyEqual(S->GetNumberField(TEXT("tile_cm")), 50.0));
		}
		TestTrue(TEXT("a lone image is a set of its own"), Sets.ContainsByPredicate([&](const TSharedPtr<FJsonValue>& V) { return V->AsObject()->GetStringField(TEXT("name")) == SetName + TEXT("Lone"); }));
	}

	// Apply to a part: textures imported with the right settings, instance set up.
	ADynamicMeshActor* Part = Cleanup.Track(CreateMeshActor(TEXT("MtTexBox"), FVector::ZeroVector, R0));
	UModellingPrimitivesToolset::AddBox(Part->GetActorLabel(), FVector(300, 200, 100), FVector::ZeroVector, R0, false);
	const FString Name = Part->GetActorLabel();
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingTextureToolset::ApplyTexturePart(Name, SetName, 0.f, true, TEXT(""), -1.f, -1.f));
		if (!TestTrue(TEXT("apply texture works"), J.IsValid())) { return false; }
		const FString MiPath = J->GetStringField(TEXT("material"));
		TestTrue(TEXT("instance is world-aligned at the set's tile size"), MiPath.Contains(TEXT("MI_Tex_MtTex_World_50")));

		UTexture2D* Albedo = Cast<UTexture2D>(FindObject<UObject>(nullptr, TEXT("/Game/ModellingToolset/Textures/T_MtTex_Albedo.T_MtTex_Albedo")));
		UTexture2D* Normal = Cast<UTexture2D>(FindObject<UObject>(nullptr, TEXT("/Game/ModellingToolset/Textures/T_MtTex_Normal.T_MtTex_Normal")));
		UTexture2D* Rough = Cast<UTexture2D>(FindObject<UObject>(nullptr, TEXT("/Game/ModellingToolset/Textures/T_MtTex_Roughness.T_MtTex_Roughness")));
		if (TestNotNull(TEXT("albedo imported"), Albedo)) { TestTrue(TEXT("albedo is sRGB"), Albedo->SRGB); }
		if (TestNotNull(TEXT("normal imported"), Normal)) { TestTrue(TEXT("normal map settings"), !Normal->SRGB && Normal->CompressionSettings == TC_Normalmap); }
		if (TestNotNull(TEXT("roughness imported"), Rough)) { TestFalse(TEXT("roughness is linear"), Rough->SRGB); }

		UMaterialInstanceConstant* MI = Cast<UMaterialInstanceConstant>(FindObject<UObject>(nullptr, *MiPath));
		if (TestNotNull(TEXT("instance exists"), MI))
		{
			float Tile = 0.f;
			TestTrue(TEXT("TileCm set"), MI->GetScalarParameterValue(FHashedMaterialParameterInfo(TEXT("TileCm")), Tile) && FMath::IsNearlyEqual(Tile, 50.f));
			UTexture* T = nullptr;
			TestTrue(TEXT("albedo texture set"), MI->GetTextureParameterValue(FHashedMaterialParameterInfo(TEXT("AlbedoTexture")), T) && T == Albedo);
			bool bUse = false; FGuid Guid;
			TestTrue(TEXT("normal switch on"), MI->GetStaticSwitchParameterValue(FHashedMaterialParameterInfo(TEXT("UseNormalTexture")), bUse, Guid) && bUse);
			TestTrue(TEXT("roughness switch on"), MI->GetStaticSwitchParameterValue(FHashedMaterialParameterInfo(TEXT("UseRoughnessTexture")), bUse, Guid) && bUse);
			TestTrue(TEXT("metallic switch off (no texture)"), MI->GetStaticSwitchParameterValue(FHashedMaterialParameterInfo(TEXT("UseMetallicTexture")), bUse, Guid) && !bUse);
			const UMaterial* Master = MI->GetMaterial();
			TestTrue(TEXT("parent is the world-aligned master"), Master && Master->GetName() == TEXT("M_ModellingWorldAligned_v2"));
		}
	}
	// UV mode on the top faces, forced roughness.
	{
		FModellingSelection Top; Top.Mode = TEXT("normal"); Top.A = FVector(0, 0, 1); Top.Scalar = 10.f;
		TSharedPtr<FJsonObject> J = ParseJson(UModellingTextureToolset::ApplyTextureFaces(Name, Top, SetName, 25.f, false, TEXT("#FFFFFF"), 0.3f, -1.f));
		if (TestTrue(TEXT("apply to faces works"), J.IsValid()))
		{
			TestTrue(TEXT("UV instance at 25 cm"), J->GetStringField(TEXT("material")).Contains(TEXT("MI_Tex_MtTex_UV_25")));
			TestEqual(TEXT("goes to slot 1"), static_cast<int32>(J->GetNumberField(TEXT("slot"))), 1);
			UMaterialInstanceConstant* MI = Cast<UMaterialInstanceConstant>(FindObject<UObject>(nullptr, *J->GetStringField(TEXT("material"))));
			bool bUse = true; FGuid Guid;
			if (TestNotNull(TEXT("UV instance exists"), MI))
			{
				TestTrue(TEXT("forced roughness turns the roughness texture off"), MI->GetStaticSwitchParameterValue(FHashedMaterialParameterInfo(TEXT("UseRoughnessTexture")), bUse, Guid) && !bUse);
				TestTrue(TEXT("parent is the UV master"), MI->GetMaterial() && MI->GetMaterial()->GetName() == TEXT("M_ModellingTextured_v2"));
			}
		}
		TArray<TSharedPtr<FJsonValue>> Slots;
		FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(UModellingMaterialsToolset::ListMaterialSlots(Name)), Slots);
		TestEqual(TEXT("two slots: body and top"), Slots.Num(), 2);
	}
	// Errors.
	TestTrue(TEXT("unknown set is refused with help"), UModellingTextureToolset::ApplyTexturePart(Name, TEXT("NoSuchSet"), 0.f, true, TEXT(""), -1.f, -1.f).IsEmpty());
	TestTrue(TEXT("bad tint refused"), UModellingTextureToolset::ApplyTexturePart(Name, SetName, 0.f, true, TEXT("red"), -1.f, -1.f).IsEmpty());

	// Library materials: a material in a library folder is found, categorised and applied.
	{
		GetMutableDefault<UModellingToolsetSettings>()->MaterialLibraryFolder = TEXT("/Game/MtLibTest");
		IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
		UMaterial* Lib = Cast<UMaterial>(AssetTools.CreateAsset(TEXT("M_RedBrickTest"), TEXT("/Game/MtLibTest"), UMaterial::StaticClass(), NewObject<UMaterialFactoryNew>()));
		if (TestNotNull(TEXT("library material made"), Lib))
		{
			FAssetRegistryModule::AssetCreated(Lib);
			TSharedPtr<FJsonObject> J = ParseJson(UModellingTextureToolset::ListLibraryMaterials(TEXT("brick")));
			if (TestTrue(TEXT("library listed"), J.IsValid()))
			{
				const TArray<TSharedPtr<FJsonValue>>& Mats = J->GetArrayField(TEXT("materials"));
				TestEqual(TEXT("one brick material found"), Mats.Num(), 1);
				if (Mats.Num() == 1)
				{
					TestEqual(TEXT("category guessed"), Mats[0]->AsObject()->GetStringField(TEXT("category")), FString(TEXT("brick")));
					TSharedPtr<FJsonObject> Applied = ParseJson(UModellingTextureToolset::ApplyLibraryMaterial(Name, Mats[0]->AsObject()->GetStringField(TEXT("path")), FModellingSelection()));
					TestTrue(TEXT("library material applied"), Applied.IsValid() && Applied->GetStringField(TEXT("material")).Contains(TEXT("M_RedBrickTest")));
				}
			}
			TestTrue(TEXT("filter with no match lists nothing"), ParseJson(UModellingTextureToolset::ListLibraryMaterials(TEXT("zzz")))->GetArrayField(TEXT("materials")).Num() == 0);
		}
	}

	// UVs: primitives start with the wrong tile size; AutoUV fixes it; the stretch check sees both.
	{
		ADynamicMeshActor* Box = Cleanup.Track(CreateMeshActor(TEXT("MtUvBox"), FVector::ZeroVector, R0));
		UModellingPrimitivesToolset::AddBox(Box->GetActorLabel(), FVector(300, 300, 300), FVector::ZeroVector, R0, false);
		TSharedPtr<FJsonObject> Before = ParseJson(UModellingTextureToolset::CheckTextureStretch(Box->GetActorLabel()));
		TestTrue(TEXT("a raw 3 m box has the wrong tile size"), Before.IsValid() && Before->GetNumberField(TEXT("percent_area_wrong_tile_size")) > 90.0);

		UModellingTextureToolset::AutoUV(Box->GetActorLabel(), TEXT("box"), FModellingSelection());
		const double Ratio = UvTileRatio(Box);
		TestTrue(*FString::Printf(TEXT("box projection gives one tile per 100 cm (ratio %.3f)"), Ratio), FMath::IsNearlyEqual(Ratio, 1.0, 0.05));
		TSharedPtr<FJsonObject> After = ParseJson(UModellingTextureToolset::CheckTextureStretch(Box->GetActorLabel()));
		TestTrue(TEXT("after AutoUV the box is good"), After.IsValid() && After->GetStringField(TEXT("verdict")).StartsWith(TEXT("Good")));
		TestEqual(TEXT("no faces without layout"), static_cast<int32>(After->GetNumberField(TEXT("faces_without_layout"))), 0);

		ADynamicMeshActor* Cyl = Cleanup.Track(CreateMeshActor(TEXT("MtUvCyl"), FVector::ZeroVector, R0));
		UModellingPrimitivesToolset::AddCylinder(Cyl->GetActorLabel(), 50.f, 400.f, FVector::ZeroVector, R0, 32, true, false);
		UModellingTextureToolset::AutoUV(Cyl->GetActorLabel(), TEXT("cylinder"), FModellingSelection());
		TSharedPtr<FJsonObject> CylCheck = ParseJson(UModellingTextureToolset::CheckTextureStretch(Cyl->GetActorLabel()));
		TestTrue(*FString::Printf(TEXT("cylinder projection has little stretch (%.1f%%)"), CylCheck->GetNumberField(TEXT("percent_area_stretched"))), CylCheck.IsValid() && CylCheck->GetNumberField(TEXT("percent_area_stretched")) < 15.0);
		TestTrue(*FString::Printf(TEXT("cylinder tile ratio about 1 (%.3f)"), UvTileRatio(Cyl)), FMath::IsNearlyEqual(UvTileRatio(Cyl), 1.0, 0.1));

		ADynamicMeshActor* Ball = Cleanup.Track(CreateMeshActor(TEXT("MtUvBall"), FVector::ZeroVector, R0));
		UModellingPrimitivesToolset::AddSphere(Ball->GetActorLabel(), 80.f, FVector::ZeroVector, R0, 24, false);
		UModellingTextureToolset::AutoUV(Ball->GetActorLabel(), TEXT("unwrap"), FModellingSelection());
		TSharedPtr<FJsonObject> BallCheck = ParseJson(UModellingTextureToolset::CheckTextureStretch(Ball->GetActorLabel()));
		TestTrue(TEXT("unwrap gives every face a layout"), BallCheck.IsValid() && static_cast<int32>(BallCheck->GetNumberField(TEXT("faces_without_layout"))) == 0);
		TestTrue(*FString::Printf(TEXT("unwrapped sphere tile ratio about 1 (%.3f)"), UvTileRatio(Ball)), FMath::IsNearlyEqual(UvTileRatio(Ball), 1.0, 0.2));
		TestTrue(TEXT("bad method refused"), UModellingTextureToolset::AutoUV(Ball->GetActorLabel(), TEXT("magic"), FModellingSelection()).IsEmpty());
	}
	return true;
}


// Uses the real Fab/Megascans surfaces when the project has them; skips the library parts otherwise.
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingSurfacesTest, "ModellingToolset.Surfaces", TestFlags)
bool FModellingSurfacesTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld()) { AddError(TEXT("No editor world.")); return false; }
	FActorCleanup Cleanup;
	const FRotator R0 = FRotator::ZeroRotator;
	struct FMatCleanup { ~FMatCleanup() { DeleteGeneratedMaterials({ TEXT("MI_Tex_Brick_Wall"), TEXT("MI_Tex_Red_Roof"), TEXT("MI_Glass_") }); } } MatCleanup;

	// Matching logic that needs no library.
	{
		TestEqual(TEXT("category: brick"), GuessSurfaceCategory(TEXT("Brick Wall Worn")), FString(TEXT("brick")));
		TestEqual(TEXT("category: roof"), GuessSurfaceCategory(TEXT("Red Roof Tiles")), FString(TEXT("roof")));
		TestEqual(TEXT("category: metal via rust"), GuessSurfaceCategory(TEXT("Rusty Metal Sheet")), FString(TEXT("metal")));
		TestEqual(TEXT("category: plaster"), GuessSurfaceCategory(TEXT("Cracked Wall Plaster")), FString(TEXT("plaster")));
		TestEqual(TEXT("category: ground via soil"), GuessSurfaceCategory(TEXT("Dirt Ground")), FString(TEXT("soil")));
		const FLinearColor Tint = TintToMatch(FColor(100, 100, 100), FColor(200, 100, 50));
		TestTrue(TEXT("tint brightens red and darkens blue"), Tint.R > 1.5f && FMath::IsNearlyEqual(Tint.G, 1.f, 0.05f) && Tint.B < 0.5f);
		const FLinearColor Clamped = TintToMatch(FColor(10, 10, 10), FColor(255, 255, 255));
		TestTrue(TEXT("tint is clamped"), Clamped.R <= 4.f);
	}

	const TArray<FSurfaceEntry> Catalogue = BuildSurfaceCatalogue(true);
	AddInfo(FString::Printf(TEXT("SURFACES catalogue has %d entries"), Catalogue.Num()));
	if (Catalogue.Num() < 10)
	{
		AddWarning(TEXT("Fewer than 10 library surfaces found; the library parts of this test were skipped."));
		return true;
	}
	for (const FSurfaceEntry& E : Catalogue) { AddInfo(FString::Printf(TEXT("SURFACE %-28s %-9s %s"), *E.Name, *E.Category, E.bHasAverageColour ? *E.AverageColour.ToHex().Left(6) : TEXT("?"))); }

	// Listing and lookup.
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingSurfaceToolset::ListSurfaces(TEXT("brick")));
		TestTrue(TEXT("brick listed"), J.IsValid() && J->GetArrayField(TEXT("surfaces")).Num() >= 1);
		const FSurfaceEntry* Brick = FindSurface(Catalogue, TEXT("Brick Wall Worn"));
		if (TestNotNull(TEXT("brick found by name"), Brick))
		{
			TestEqual(TEXT("brick category"), Brick->Category, FString(TEXT("brick")));
			TestTrue(TEXT("brick has all three maps"), !Brick->NormalPath.IsEmpty() && !Brick->PackedPath.IsEmpty());
			TestTrue(TEXT("brick average colour measured"), Brick->bHasAverageColour && Brick->AverageColour.R > Brick->AverageColour.B);
		}
		TestNotNull(TEXT("found by key with underscores"), FindSurface(Catalogue, TEXT("brick_wall_worn")));
	}

	// Closeness.
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingSurfaceToolset::FindClosestSurface(TEXT("worn red brick wall"), TEXT("#8B4A3A"), 5));
		if (TestTrue(TEXT("closest returned"), J.IsValid()))
		{
			const TArray<TSharedPtr<FJsonValue>>& C = J->GetArrayField(TEXT("candidates"));
			TestTrue(TEXT("brick is the top match"), C.Num() > 0 && C[0]->AsObject()->GetStringField(TEXT("name")).Contains(TEXT("Brick")));
			TestTrue(TEXT("brick is usable"), C.Num() > 0 && C[0]->AsObject()->GetBoolField(TEXT("usable")));
			TestFalse(TEXT("no flat colour needed"), J->GetBoolField(TEXT("use_flat_color")));
			TestTrue(TEXT("tint suggested"), C.Num() > 0 && C[0]->AsObject()->HasField(TEXT("tint_to_match")));
		}
		J = ParseJson(UModellingSurfaceToolset::FindClosestSurface(TEXT("terracotta roof tiles"), TEXT("#B0523A"), 3));
		TestTrue(TEXT("roof tiles is the top match"), J.IsValid() && J->GetArrayField(TEXT("candidates"))[0]->AsObject()->GetStringField(TEXT("name")).Contains(TEXT("Roof")));
		J = ParseJson(UModellingSurfaceToolset::FindClosestSurface(TEXT("white plaster wall"), TEXT("#EDE6DA"), 3));
		TestTrue(TEXT("plaster is the top match"), J.IsValid() && J->GetArrayField(TEXT("candidates"))[0]->AsObject()->GetStringField(TEXT("name")).Contains(TEXT("Plaster")));
		J = ParseJson(UModellingSurfaceToolset::FindClosestSurface(TEXT("pink fluffy fur"), TEXT("#FF88CC"), 3));
		TestTrue(TEXT("fur has no usable match"), J.IsValid() && J->GetBoolField(TEXT("use_flat_color")));
		J = ParseJson(UModellingSurfaceToolset::FindClosestSurface(TEXT("rusty metal"), TEXT(""), 3));
		TestTrue(TEXT("rust matches without a colour"), J.IsValid() && J->GetArrayField(TEXT("candidates"))[0]->AsObject()->GetStringField(TEXT("name")).Contains(TEXT("Rust")));
	}

	// Apply with a tint and finish.
	ADynamicMeshActor* Part = Cleanup.Track(CreateMeshActor(TEXT("MtSurfBox"), FVector::ZeroVector, R0));
	UModellingPrimitivesToolset::AddBox(Part->GetActorLabel(), FVector(300, 300, 300), FVector::ZeroVector, R0, false);
	const FString Name = Part->GetActorLabel();
	{
		TSharedPtr<FJsonObject> J = ParseJson(UModellingSurfaceToolset::ApplySurfacePart(Name, TEXT("Brick Wall Worn"), TEXT("#8B4A3A"), TEXT("matte"), 200.f, true));
		if (TestTrue(TEXT("surface applied"), J.IsValid()))
		{
			const TSharedPtr<FJsonObject> S = J->GetObjectField(TEXT("surface_settings"));
			const FString MiPath = S->GetStringField(TEXT("material"));
			UMaterialInstanceConstant* MI = Cast<UMaterialInstanceConstant>(FindObject<UObject>(nullptr, *MiPath));
			if (TestNotNull(TEXT("instance exists"), MI))
			{
				TestTrue(TEXT("parent is the world-aligned master v2"), MI->GetMaterial() && MI->GetMaterial()->GetName() == TEXT("M_ModellingWorldAligned_v2"));
				bool bOn = false; FGuid G;
				TestTrue(TEXT("packed ORM on"), MI->GetStaticSwitchParameterValue(FHashedMaterialParameterInfo(TEXT("UsePackedORM")), bOn, G) && bOn);
				UTexture* T = nullptr;
				TestTrue(TEXT("ORM texture set"), MI->GetTextureParameterValue(FHashedMaterialParameterInfo(TEXT("ORMTexture")), T) && T && T->GetName().EndsWith(TEXT("_ORM")));
				float RMin = -1.f, Tile = 0.f;
				TestTrue(TEXT("matte roughness range"), MI->GetScalarParameterValue(FHashedMaterialParameterInfo(TEXT("RoughnessMin")), RMin) && FMath::IsNearlyEqual(RMin, 0.55f, 0.01f));
				TestTrue(TEXT("tile 200"), MI->GetScalarParameterValue(FHashedMaterialParameterInfo(TEXT("TileCm")), Tile) && FMath::IsNearlyEqual(Tile, 200.f));
				FLinearColor Tint;
				TestTrue(TEXT("tint applied"), MI->GetVectorParameterValue(FHashedMaterialParameterInfo(TEXT("Tint")), Tint) && !Tint.Equals(FLinearColor::White, 0.01f));
			}
		}
		TestEqual(TEXT("no faces without material"), DiagnoseMesh(Part).FacesWithMissingMaterial, 0);
		FModellingSelection Top; Top.Mode = TEXT("normal"); Top.A = FVector(0, 0, 1); Top.Scalar = 10.f;
		TSharedPtr<FJsonObject> F = ParseJson(UModellingSurfaceToolset::ApplySurfaceFaces(Name, Top, TEXT("Red Roof Tiles"), TEXT(""), TEXT("auto"), 0.f, true));
		TestTrue(TEXT("roof on the top faces in slot 1"), F.IsValid() && static_cast<int32>(F->GetNumberField(TEXT("slot"))) == 1);
		TestTrue(TEXT("bad finish refused"), UModellingSurfaceToolset::ApplySurfacePart(Name, TEXT("Brick Wall Worn"), TEXT(""), TEXT("shiny-ish"), 0.f, true).IsEmpty());
		TestTrue(TEXT("unknown surface refused"), UModellingSurfaceToolset::ApplySurfacePart(Name, TEXT("Unobtainium"), TEXT(""), TEXT("auto"), 0.f, true).IsEmpty());
	}

	// Glass.
	{
		ADynamicMeshActor* Pane = Cleanup.Track(CreateMeshActor(TEXT("MtGlassBox"), FVector(0, 500, 0), R0));
		UModellingPrimitivesToolset::AddBox(Pane->GetActorLabel(), FVector(100, 100, 100), FVector::ZeroVector, R0, false);
		TSharedPtr<FJsonObject> J = ParseJson(UModellingSurfaceToolset::ApplyGlass(Pane->GetActorLabel(), FModellingSelection(), TEXT("#DDEEFF"), 0.2f, 0.05f, 1.52f));
		if (TestTrue(TEXT("glass applied"), J.IsValid()))
		{
			AddInfo(TEXT("GLASS master: ") + J->GetStringField(TEXT("glass_master")));
			UMaterialInstanceConstant* MI = Cast<UMaterialInstanceConstant>(FindObject<UObject>(nullptr, *J->GetStringField(TEXT("material"))));
			if (TestNotNull(TEXT("glass instance"), MI))
			{
				TestTrue(TEXT("glass is translucent"), MI->GetBlendMode() == BLEND_Translucent);
				float Op = -1.f;
				const bool bFab = J->GetStringField(TEXT("glass_master")).Contains(TEXT("Megascans"));
				TestTrue(TEXT("opacity set"), MI->GetScalarParameterValue(FHashedMaterialParameterInfo(bFab ? TEXT("Base Opacity") : TEXT("Opacity")), Op) && FMath::IsNearlyEqual(Op, 0.2f, 0.01f));
			}
		}
		FString Error;
		UMaterial* Own = UModellingMaterialsToolset::GetGlassMaterial(Error);
		TestTrue(TEXT("own glass master builds and is translucent"), Own && Own->GetBlendMode() == BLEND_Translucent);
		TestTrue(TEXT("bad glass colour refused"), UModellingSurfaceToolset::ApplyGlass(Pane->GetActorLabel(), FModellingSelection(), TEXT("blue"), 0.2f, 0.05f, 1.52f).IsEmpty());
	}
	return true;
}


// Needs a real renderer. Three glass boxes side by side: Megascans glass with refraction, without, and the plugin's own glass.
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModellingRenderGlassTest, "ModellingToolset.RenderGlass", TestFlags)
bool FModellingRenderGlassTest::RunTest(const FString& Parameters)
{
	if (!GetEditorWorld()) { AddError(TEXT("No editor world.")); return false; }
	if (!FApp::CanEverRender()) { AddWarning(TEXT("No renderer; skipped.")); return true; }
	FActorCleanup Cleanup;
	const FRotator R0 = FRotator::ZeroRotator;
	struct FMatCleanup { ~FMatCleanup() { DeleteGeneratedMaterials({ TEXT("MI_Glass_") }); } } MatCleanup;

	// A cream backdrop wall so transparency is visible, and three glass boxes in front of it.
	ADynamicMeshActor* Wall = Cleanup.Track(CreateMeshActor(TEXT("RgWall"), FVector(-120, 0, 60), R0));
	UModellingPrimitivesToolset::AddBox(Wall->GetActorLabel(), FVector(10, 420, 140), FVector::ZeroVector, R0, false);
	UModellingMaterialsToolset::PaintPart(Wall->GetActorLabel(), TEXT("#E8D8B0"), 0.7f, 0.f, TEXT("RgBackdrop"));
	FString Names;
	for (int32 i = 0; i < 3; ++i)
	{
		ADynamicMeshActor* Box = Cleanup.Track(CreateMeshActor(*FString::Printf(TEXT("RgGlass%d"), i), FVector(0, -130 + i * 130, 50), R0));
		UModellingPrimitivesToolset::AddBox(Box->GetActorLabel(), FVector(80, 80, 100), FVector::ZeroVector, R0, false);
		const float IOR = (i == 1) ? 1.0f : 1.52f;
		FString Result = UModellingSurfaceToolset::ApplyGlass(Box->GetActorLabel(), FModellingSelection(), TEXT("#DDEEFF"), 0.2f, 0.05f, IOR);
		if (i == 2)
		{
			// Force the plugin's own glass by making an instance of it directly.
			FString Error;
			UMaterial* Own = UModellingMaterialsToolset::GetGlassMaterial(Error);
			if (Own)
			{
				FGeometryScriptMeshSelection All;
				UGeometryScriptLibrary_MeshSelectionFunctions::CreateSelectAllMeshSelection(GetDynamicMesh(Box), All, EGeometryScriptMeshSelectionType::Triangles);
				ApplyMaterialToWholePart(Box, GetDynamicMesh(Box), Own);
			}
		}
		AddInfo(FString::Printf(TEXT("GLASSBOX %d: %s"), i, *Result.Left(160)));
		Names += (Names.IsEmpty() ? TEXT("") : TEXT(",")) + Box->GetActorLabel();
	}
	FCaptureRequest Req; Req.ActorNames = Wall->GetActorLabel() + TEXT(",") + Names; Req.Views = TEXT("front"); Req.ViewMode = TEXT("lit"); Req.Resolution = 512; Req.bIsolate = true; Req.bForcePerspective = true; Req.Label = TEXT("glass");
	const FCaptureResult R = ModellingToolset::CaptureViews(Req);
	TestTrue(TEXT("glass capture ok"), R.bOk);
	if (R.bOk)
	{
		// Brightness in the middle of each box (left to right: with refraction, without, own glass).
		for (int32 i = 0; i < 3; ++i)
		{
			const int32 X = 128 + i * 128, Y = 256;
			double Sum = 0; int32 N = 0;
			for (int32 dy = -10; dy <= 10; ++dy) for (int32 dx = -10; dx <= 10; ++dx) { const FColor C = R.Sheet[(Y + dy) * R.SheetSize.X + X + dx]; Sum += (C.R + C.G + C.B) / 3.0; ++N; }
			AddInfo(FString::Printf(TEXT("GLASSBOX %d brightness %.0f/255"), i, Sum / N));
		}
	}
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS















