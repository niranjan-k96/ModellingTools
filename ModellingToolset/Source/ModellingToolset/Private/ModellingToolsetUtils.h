// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "GeometryScript/GeometryScriptSelectionTypes.h"
#include "ScopedTransaction.h"
#include "UObject/StrongObjectPtr.h"

class ADynamicMeshActor;
class UDynamicMesh;
class UMaterialInterface;
class UWorld;
struct FModellingSelection;
namespace UE::Geometry { class FDynamicMesh3; }

namespace ModellingToolset
{
	/** Tag added to every actor this plugin creates. Only tagged actors may be modified or deleted. */
	extern const FName ActorTag;

	UWorld* GetEditorWorld();

	// ---- Folders -------------------------------------------------------------------------------

	/** Absolute folders resolved from the project settings. */
	FString GetReferencesDir();
	FString GetProgressDir();
	FString GetExportsDir();
	FString GetTexturesDir();
	/** Creates the workspace folders. Called lazily by the tools that need them, never at editor startup. */
	void EnsureWorkspaceFolders();

	/** File names (png, jpg, jpeg, bmp) currently in the references folder, sorted. */
	TArray<FString> ListReferenceImageNames();

	/** What the user told us about a reference picture, from its notes file and file name. */
	struct FReferenceMeta
	{
		/** front, back, left, right, top, bottom, or empty if unknown. ("side" counts as right.) */
		FString View;
		double HeightCm = 0.0;
		double WidthCm = 0.0;
		double DepthCm = 0.0;
		FString Notes;
	};

	/**
	 * Reads the optional notes file next to a reference (same name, .txt or .md) and the file name.
	 * Recognised note lines: "view: front", "height_cm: 1200", "width_cm: 300", "depth_cm: 300". A view word in the file name
	 * (Lighthouse_front.png) is used when the notes do not say.
	 */
	FReferenceMeta ReadReferenceMeta(const FString& ImageFileName);

	/** True if Path, after normalisation, is inside Root. Rejects ".." escapes. Symlinks are not resolved. */
	bool IsPathUnder(const FString& Path, const FString& Root);

	/** Keeps letters, digits, '_' and '-'. Never empty. */
	FString SanitizeFileName(const FString& In);

	// ---- Actors --------------------------------------------------------------------------------

	/** Finds any dynamic mesh actor by label or object name. For read-only queries. */
	ADynamicMeshActor* FindMeshActor(const FString& Name);

	/** Finds an actor this plugin created. Raises a tool error and returns null if it is missing or was not created by this plugin. */
	ADynamicMeshActor* FindModelActor(const FString& Name);

	/** Spawns a tagged dynamic mesh actor with a guaranteed-unique label derived from Name. */
	ADynamicMeshActor* CreateMeshActor(const FString& Name, const FVector& Location, const FRotator& Rotation);

	UDynamicMesh* GetDynamicMesh(ADynamicMeshActor* Actor);

	// ---- Results -------------------------------------------------------------------------------

	/** Raises a tool error visible to the AI caller. While an FErrorCapture is alive the message is stored there instead. */
	void Fail(const FString& Message);

	/**
	 * While alive, Fail() stores its (first) message here and does not raise a tool error. Lets one tool call run other tools
	 * and report each one's error itself, instead of the whole call aborting at the first failure.
	 */
	struct FErrorCapture
	{
		FErrorCapture();
		~FErrorCapture();
		bool HasError() const { return !Message.IsEmpty(); }
		FString Message;
	private:
		FErrorCapture* Previous = nullptr;
	};

	FString ToJsonString(const TSharedRef<FJsonObject>& Object);
	FString ToJsonString(const TArray<TSharedPtr<FJsonValue>>& Array);

	/** JSON summary of an actor's mesh: triangle/vertex counts, transform and world size. */
	TSharedRef<FJsonObject> DescribeActor(ADynamicMeshActor* Actor);

	// ---- Editing -------------------------------------------------------------------------------

	/**
	 * Opens an undo transaction, resolves the target actor and marks the actor, component and mesh as modified so the
	 * geometry change is recorded. Only actors created by this plugin are accepted.
	 * If bCreateIfMissing is true and no actor has that name, a new one is created inside the same transaction.
	 */
	struct FEditScope
	{
		FEditScope(const FString& Name, const TCHAR* Description, bool bCreateIfMissing = false);

		bool IsValid() const { return Actor != nullptr && Mesh != nullptr; }

		/**
		 * JSON summary of the actor after the edit. If the edit wiped out a mesh that had geometry (for example a mirror
		 * across the wrong side), the mesh is restored, a tool error is raised and an empty string is returned.
		 */
		FString Result();

		FScopedTransaction Transaction;
		ADynamicMeshActor* Actor = nullptr;
		UDynamicMesh* Mesh = nullptr;
		int32 TrianglesBefore = 0;
	};

	/** Restores the mesh to how it was before the most recent edit made through an FEditScope. False if there is no snapshot. */
	bool RestoreLastEdit(ADynamicMeshActor* Actor);

	// ---- Materials -----------------------------------------------------------------------------

	/** The material slots of an actor's mesh component (null entries for empty slots). */
	TArray<UMaterialInterface*> GetMaterialSlots(ADynamicMeshActor* Actor);

	/** Puts one material on every face of a part (slot 0 only). */
	void ApplyMaterialToWholePart(ADynamicMeshActor* Actor, UDynamicMesh* Mesh, UMaterialInterface* Material);

	/** Puts a material on the selected faces, reusing its slot if the part already has it, otherwise adding one. Returns the slot used. */
	int32 ApplyMaterialToSelection(ADynamicMeshActor* Actor, UDynamicMesh* Mesh, const FGeometryScriptMeshSelection& Selection, UMaterialInterface* Material);

	/**
	 * Makes every face point at a usable material slot. Faces whose number is out of range, or whose slot is empty, are moved
	 * to the first slot that holds a material (or 0). Prevents faces rendering with the fallback material after cuts and merges.
	 * Returns the number of faces changed.
	 */
	int32 NormaliseMaterialIDs(ADynamicMeshActor* Actor);

	/**
	 * Prepares a mesh from Source to be appended into Target without mixing up colours: Source's material slots are added to
	 * Target's slot list and the copy's face numbers are offset to match. A source with no materials of its own takes Target's base slot.
	 * The returned mesh is transient; keep the TStrongObjectPtr alive while it is used.
	 */
	TStrongObjectPtr<UDynamicMesh> CopyMeshForMerge(ADynamicMeshActor* Target, ADynamicMeshActor* Source);

	// ---- Orientation ---------------------------------------------------------------------------

	/** True when a mesh's faces point inward: by signed volume for a closed mesh, by facing-away-from-the-axis for an open one (revolves). */
	bool IsInsideOut(const UE::Geometry::FDynamicMesh3& Mesh);

	/** Flips the whole mesh if it is inside out. Returns true if it was flipped. Use on freshly built shapes before appending them. */
	bool EnsureFacesPointOutward(UDynamicMesh* Mesh);

	// ---- Diagnostics ---------------------------------------------------------------------------

	struct FMeshDiagnostics
	{
		int32 Triangles = 0;
		int32 OpenBoundaryEdges = 0;
		/** True when the mesh is closed and its faces point inward (it would look dark or see-through). */
		bool bInsideOut = false;
		double SignedVolume = 0.0;
		int32 FacesWithMissingMaterial = 0;
		int32 MaterialSlots = 0;
	};
	FMeshDiagnostics DiagnoseMesh(ADynamicMeshActor* Actor);

	/** Translates a FModellingSelection into a Geometry Script selection. Raises a tool error and returns false if it matches nothing. */
	bool BuildSelection(UDynamicMesh* Mesh, const FModellingSelection& Selection, FGeometryScriptMeshSelection& OutSelection);

	// ---- Checkpoints ---------------------------------------------------------------------------

	bool SaveCheckpoint(ADynamicMeshActor* Actor, const FString& Label);
	bool RestoreCheckpoint(ADynamicMeshActor* Actor, const FString& Label);
	TArray<FString> ListCheckpoints(const FString& ActorName);

	// ---- Images --------------------------------------------------------------------------------

	/** Bilinear resize of a BGRA image. */
	void ResizeImage(const TArray<FColor>& Src, FIntPoint SrcSize, FIntPoint DstSize, TArray<FColor>& Dst);

	/** Decodes png/jpg/bmp from disk and downsizes so the longest side is <= MaxDimension. */
	bool LoadImageFile(const FString& Path, int32 MaxDimension, TArray<FColor>& OutPixels, FIntPoint& OutSize, FIntPoint& OutOriginalSize, FString& OutError);

	bool SavePng(const FString& Path, const TArray<FColor>& Pixels, FIntPoint Size);
}

