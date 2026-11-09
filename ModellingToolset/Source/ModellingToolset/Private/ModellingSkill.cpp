// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingSkill.h"

#include "ModellingToolsetUtils.h"

UModellingWorkflowSkill::UModellingWorkflowSkill()
{
	Description = TEXT("Use when the user wants to model something in Unreal with the Modelling Toolset (start of a Modelling Assistant job, 'start the modelling job', build from reference images). "
		"Gives the exact step-by-step workflow: read the job, study the reference images first, build and check with screenshots and a comparison against the references, colour it, ask the user to review, apply changes, then finish when the user presses Done.");

	Instructions = TEXT(
		"MODELLING TOOLSET WORKFLOW. Follow these steps in order. Do not skip ahead.\n"
		"\n"
		"STEP 1. READ THE JOB\n"
		"- Call GetModellingJob (ModellingJobToolset) before anything else.\n"
		"- If status is \"not_started\": STOP. Do not model. Tell the user to follow the steps in the Modelling Assistant panel (toolbar button in the Level Editor), press Go, and then tell you to start.\n"
		"- If the job says it was cancelled, or any job tool says the user cancelled: STOP IMMEDIATELY and tell the user you stopped. Do nothing else.\n"
		"- Otherwise read \"instructions\" (what the user wants), \"references\" (image file names) and \"output_name\".\n"
		"\n"
		"STEP 2. LOOK AT THE REFERENCE IMAGES FIRST (mandatory)\n"
		"- References folder: {ReferencesFolder}\n"
		"- Call ListReferences to see each image's label (front, side, back, top) and any real sizes the user wrote (height_cm, width_cm, depth_cm).\n"
		"- Call GetReference (or modelling_get_reference) for EVERY file listed in \"references\" and look at each image. Read its notes too.\n"
		"- Do NOT create, move or edit any geometry until you have viewed every reference image.\n"
		"- Call GetReferencePalette on each reference to get its real colours as hex. Use bIgnoreBackground true. Sample a region (RegionX, RegionY, RegionWidth, RegionHeight) for a specific part such as the roof. Never guess colours by eye when you can measure them.\n"
		"- Then write down for yourself: what the object is, its proportions (width : depth : height), the main parts, symmetry, repeated elements, the main colours, and any real sizes in the notes or instructions.\n"
		"- Call ReportProgress with one short sentence, e.g. \"Studied 3 reference images: a tall white lighthouse with a red top.\"\n"
		"- If there are no references, model from the instructions only and say so in ReportProgress. If the instructions are unclear, ask the user a short question instead of guessing.\n"
		"\n"
		"STEP 3. PREPARE\n"
		"- Call StartSession with the output name so screenshots go to a fresh folder.\n"
		"- Use centimetres. +X is the front, +Y is the right, +Z is up. Build the model standing on the ground (Z = 0).\n"
		"- Only parts you create can be edited. Never touch other level content.\n"
		"- Every edit returns the part's summary. If it contains \"warnings\" (faces pointing inward, open edges, faces without a material), fix them right away: FlipNormals, FillHoles, PaintPart. Do not carry a warning forward.\n"
		"- Use RunBatch to do many steps in one call (for example create a part, add several shapes and paint them). It is much faster than one call per shape. If a batch stops at a failed step, fix that step and run the rest.\n"
		"\n"
		"STEP 4. BLOCK OUT THE BIG SHAPES\n"
		"- Use primitives (boxes, cylinders, cones, spheres) and, where they fit, AddRevolve for round objects (vases, towers, domes), AddExtrudedPolygon for floor plans, AddStairs, AddArch and AddSweep. No small details yet.\n"
		"- Call MeasureModel and check the overall width, depth and height against the real sizes from the notes or instructions. Fix sizes now.\n"
		"- Call CompareToReference (or modelling_compare_to_reference) for each reference that has a straight-on view (front, side, back, top). It returns an overlap score and plain hints such as \"between 25% and 37% of the way down the model is 22% narrower\". Fix the biggest differences first and compare again. Aim for an overlap score of 0.85 or more before adding detail.\n"
		"- Also call CaptureViews (views front, right, top, iso, mode clay) and look at it yourself. Modes: lit (fixed studio lighting), clay (grey, best for form), unlit (flat colour), normals (surface direction, shows creases).\n"
		"- Call ReportProgress after this stage.\n"
		"\n"
		"STEP 5. ADD DETAIL, STEP BY STEP\n"
		"- Work from large to small: cut-outs and openings (BooleanOp), extrude and inset, bevels, MirrorMesh, ArrayCopies, then bends and flares if needed.\n"
		"- Direction rules: for MirrorMesh and CutWithPlane the PlaneNormal points toward the side you KEEP. For Bend, BendDirection is where the ends curve toward.\n"
		"- Before any risky step (BooleanOp, UniformRemesh, Simplify) call SaveCheckpoint. If a single edit looks wrong, call RevertLastEdit. For bigger mistakes call RestoreCheckpoint.\n"
		"- Use MeasureDistance to check parts connect, and Raycast to check heights and openings (for example shoot down through a doorway to read its height).\n"
		"- After every major step call CaptureViews and compare with the reference. CompareToReference again after changes to proportions.\n"
		"- Call ReportProgress after each stage, one plain sentence.\n"
		"\n"
		"STEP 6. SURFACES AND COLOUR\n"
		"- Real surfaces first, flat colour last. For every visible material in the reference (wall, roof, base, door, trim) do this in order:\n"
		"  a) Call FindClosestSurface with plain words for what you see (\"worn red brick wall\", \"white plaster\", \"terracotta roof tiles\") and TargetHex from GetReferencePalette. It ranks the surface library (Fab and Megascans downloads) by words first and colour second, and tells you the tint that makes each candidate match.\n"
		"  b) If \"use_flat_color\" is false, use the top candidate: PreviewSurface to check the look, then ApplySurfacePart or ApplySurfaceFaces with the same TargetHex and a Finish (matte, satin, glossy or auto). The plugin tweaks tint and roughness to match the reference before applying. Keep bWorldAligned true so nothing stretches. Set TileCm to the real size of one repeat when you can tell it from the reference (a brick course, a plank).\n"
		"  c) Windows, lantern rooms, bottles: ApplyGlass on those faces (TintHex, Opacity about 0.1 to 0.3 for windows, Roughness, IOR).\n"
		"  d) If \"use_flat_color\" is true, check the textures folder: ListTextureSets, then ApplyTexturePart or ApplyTextureFaces. ListLibraryMaterials and ApplyLibraryMaterial cover any other ready-made materials (run AutoUV first and confirm with CheckTextureStretch, since those follow the UV map).\n"
		"  e) Only when nothing usable exists anywhere: PaintPart or PaintFaces with the hex colour from GetReferencePalette, and say in ReportProgress which surface is missing and what the user could add (\"please add Brick_albedo.png to the textures folder\").\n"
		"- Set Roughness (0 shiny to 1 matte) and Metallic (0 or 1) to suit the material you see: painted walls are about 0.7 and 0, bare metal is about 0.3 and 1, glass-like surfaces are about 0.1.\n"
		"- Compare the result with the reference in a lit CaptureViews, and check colours again with GetReferencePalette on your own screenshot if unsure.\n"
		"\n"
		"STEP 7. CLEAN UP\n"
		"- Use FillHoles, RemoveSmallParts, RemoveHiddenFaces or MergeOverlaps, and RecomputeNormals so the model is clean. If it looks inside out, FlipNormals.\n"
		"\n"
		"STEP 8. FINAL CHECK, THEN ASK FOR REVIEW\n"
		"- Run AutoUV on every part (or confirm CheckTextureStretch is good) so the exported file has a proper texture layout.\n"
		"- Call CompareToReference once more for each straight-on reference, then CaptureViews with views iso, iso_back, front, right, left, top. Fix any visible difference.\n"
		"- Call RequestReview with a short, plain-language summary: what you built, how well it matches (mention the overlap score in simple words), and anything approximate or missing. Use simple words, no technical terms.\n"
		"- Immediately call WaitForUserDecision. Do NOT export, do NOT save an asset, and do NOT tell the user you are finished. The user decides in the panel.\n"
		"\n"
		"STEP 9. ACT ON THE USER'S DECISION\n"
		"- Call WaitForUserDecision. If it returns decision \"pending\", call it again. Keep waiting.\n"
		"- decision \"changes\": the text in \"changes\" is what the user wants. Re-read the references if needed, apply the changes, check with CaptureViews and CompareToReference, call ReportProgress, then go back to STEP 8 (RequestReview, then WaitForUserDecision).\n"
		"- decision \"done\": the user approved it and the plugin already exported the FBX. Tell the user the \"fbx_path\" in one or two sentences. Stop. Do nothing else.\n"
		"- decision \"export_failed\": tell the user the error in simple words. They can retry from the panel. Then call WaitForUserDecision again.\n"
		"- decision \"cancelled\": the user cancelled. Stop immediately and say so.\n"
		"\n"
		"RULES\n"
		"- References first, always. Never model before viewing every reference image.\n"
		"- Measure, do not guess: colours with GetReferencePalette, shapes with CompareToReference, sizes with MeasureModel, surfaces with FindClosestSurface.\n"
		"- Keep messages short and simple. The user may not be technical.\n"
		"- If a tool returns an error, read it, fix the cause and retry. Do not loop on the same failing call.\n"
		"- Never overwrite or delete anything the user made themselves.\n");
}

FString UModellingWorkflowSkill::GeneratePrompt_Implementation(const FString& InitialInstructions) const
{
	FString Prompt = InitialInstructions;
	Prompt.ReplaceInline(TEXT("{ReferencesFolder}"), *ModellingToolset::GetReferencesDir());
	return Prompt;
}


