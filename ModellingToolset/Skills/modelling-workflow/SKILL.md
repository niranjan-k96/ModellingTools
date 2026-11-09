---
name: modelling-workflow
description: Use when the user wants to model something in Unreal Engine with the Modelling Toolset, says "start the modelling job", or has pressed Go in the Modelling Assistant panel. Gives the exact steps - read the job, study the reference images first, model and check with screenshots and a comparison against the references, colour it, ask the user to review, apply changes, and finish when the user presses Done (the plugin exports the FBX).
---

# Modelling Toolset workflow

Follow these steps in order. Do not skip ahead.

This file is a copy of the skill built into the plugin (`UModellingWorkflowSkill`, found through the Agent Skill toolset). Copy this folder to `.claude/skills/` if your AI app reads skill files.

## Step 1. Read the job
- Call `GetModellingJob` (Job toolset) before anything else.
- If `status` is `not_started`: **stop**. Do not model. Tell the user to follow the steps in the **Modelling Assistant** panel (Level Editor toolbar button), press **Go**, and then tell you to start.
- If the job (or any job tool) says the user **cancelled**: stop immediately and say so. Do nothing else.
- Otherwise read `instructions`, `references` (image file names) and `output_name`.

## Step 2. Look at the reference images FIRST (mandatory)
- Call `ListReferences` to see each image's label (front, side, back, top) and any real sizes (`height_cm`, `width_cm`, `depth_cm`).
- Call `GetReference` (or `modelling_get_reference`) for **every** file in `references`. Read its notes too.
- Do **not** create, move or edit any geometry until every reference image has been viewed.
- Call `GetReferencePalette` on each reference for its real colours as hex (`bIgnoreBackground` true). Sample a region for one part, such as the roof. Never guess colours by eye when you can measure them.
- Note: what the object is, proportions (width : depth : height), main parts, symmetry, repeated elements, main colours, real sizes.
- Call `ReportProgress` with one short sentence, e.g. "Studied 3 reference images: a tall white lighthouse with a red top."
- No references? Model from the instructions only and say so. If the instructions are unclear, ask a short question instead of guessing.

## Step 3. Prepare
- Call `StartSession` with the output name.
- Units are centimetres. +X is front, +Y is right, +Z is up. Build the model standing on the ground (Z = 0).
- Only parts you create can be edited. Never touch other level content.
- Every edit returns the part's summary. If it contains `warnings` (faces pointing inward, open edges, faces without a material), fix them right away with `FlipNormals`, `FillHoles` or `PaintPart`. Do not carry a warning forward.
- Use `RunBatch` to do many steps in one call (create a part, add several shapes, paint them). If a batch stops at a failed step, fix that step and run the rest.

## Step 4. Block out the big shapes
- Use primitives, and where they fit `AddRevolve` (vases, towers, domes), `AddExtrudedPolygon` (floor plans), `AddStairs`, `AddArch`, `AddSweep`. No small details yet.
- `MeasureModel`: check overall width, depth and height against the real sizes. Fix sizes now.
- `CompareToReference` (or `modelling_compare_to_reference`) for each straight-on reference. It returns an overlap score and hints like "between 25% and 37% of the way down the model is 22% narrower". Fix the biggest differences first and compare again. Aim for an overlap score of 0.85 or more before adding detail.
- Also `CaptureViews` (front, right, top, iso, mode `clay`) and look at it yourself. Modes: `lit` (fixed studio lighting), `clay` (grey, best for form), `unlit` (flat colour), `normals` (surface direction, shows creases).
- `ReportProgress` after this stage.

## Step 5. Add detail, step by step
- Large to small: cut-outs (`BooleanOp`), extrude and inset, bevels, `MirrorMesh`, `ArrayCopies`, then bends and flares.
- Direction rules: for `MirrorMesh` and `CutWithPlane` the `PlaneNormal` points toward the side you **keep**. For `Bend`, `BendDirection` is where the ends curve toward.
- `SaveCheckpoint` before risky steps (`BooleanOp`, `UniformRemesh`, `Simplify`). One bad edit: `RevertLastEdit`. Bigger mistake: `RestoreCheckpoint`.
- `MeasureDistance` to check parts connect; `Raycast` to check heights and openings.
- `CaptureViews` after every major step; `CompareToReference` again after proportion changes.
- `ReportProgress` after each stage, one plain sentence.

## Step 6. Surfaces and colour
Real surfaces first, flat colour last. For every visible material in the reference (wall, roof, base, door, trim), in order:
1. `FindClosestSurface` with plain words for what you see ("worn red brick wall", "white plaster", "terracotta roof tiles") and `TargetHex` from `GetReferencePalette`. It ranks the surface library (Fab and Megascans downloads) by words first and colour second, and gives the tint that makes each candidate match.
2. If `use_flat_color` is false, use the top candidate: `PreviewSurface` to check the look, then `ApplySurfacePart` or `ApplySurfaceFaces` with the same `TargetHex` and a `Finish` (`matte`, `satin`, `glossy` or `auto`). The plugin tweaks tint and roughness to match the reference before applying. Keep `bWorldAligned` true so nothing stretches. Set `TileCm` to the real size of one repeat when the reference shows it.
3. Windows, lantern rooms, bottles: `ApplyGlass` on those faces (`TintHex`, `Opacity` about 0.1 to 0.3 for windows, `Roughness`, `IOR`).
4. If `use_flat_color` is true, check the textures folder: `ListTextureSets`, then `ApplyTexturePart` or `ApplyTextureFaces`. `ListLibraryMaterials` and `ApplyLibraryMaterial` cover other ready-made materials (run `AutoUV` first and confirm with `CheckTextureStretch`, since those follow the UV map).
5. Only when nothing usable exists anywhere: `PaintPart` or `PaintFaces` with the hex colour from `GetReferencePalette`, and say in `ReportProgress` which surface is missing and what the user could add ("please add Brick_albedo.png to the textures folder").

- Roughness 0 shiny to 1 matte, Metallic 0 or 1. Painted walls about 0.7 and 0, bare metal about 0.3 and 1, glass-like about 0.1.
- Compare the result with the reference in a lit `CaptureViews`.

## Step 7. Clean up
- `FillHoles`, `RemoveSmallParts`, `RemoveHiddenFaces` or `MergeOverlaps`, `RecomputeNormals`. If it looks inside out, `FlipNormals`.

## Step 8. Final check, then ask for review
- Run `AutoUV` on every part (or confirm `CheckTextureStretch` is good) so the exported file has a proper texture layout.
- `CompareToReference` once more for each straight-on reference, then `CaptureViews` (iso, iso_back, front, right, left, top). Fix any visible difference.
- Call `RequestReview` with a short, plain-language summary: what you built, how well it matches (in simple words), and anything approximate or missing.
- Immediately call `WaitForUserDecision`. Do **not** export, do **not** save an asset, and do **not** say you are finished. The user decides in the panel.

## Step 9. Act on the user's decision
- `pending`: call `WaitForUserDecision` again. Keep waiting.
- `changes`: apply the text in `changes`, check with `CaptureViews` and `CompareToReference`, `ReportProgress`, then repeat Step 8.
- `done`: the user approved and the plugin already exported the FBX. Tell the user the `fbx_path` in one or two sentences. Stop.
- `export_failed`: tell the user the error in simple words. They can retry from the panel. Then call `WaitForUserDecision` again.
- `cancelled`: stop immediately and say so.

## Rules
- References first, always.
- Measure, do not guess: colours with `GetReferencePalette`, shapes with `CompareToReference`, sizes with `MeasureModel`, surfaces with `FindClosestSurface`, texture layouts with `CheckTextureStretch`.
- Keep messages short and simple. The user may not be technical.
- If a tool returns an error, read it, fix the cause and retry. Do not loop on the same failing call.
- Never overwrite or delete anything the user made themselves.


