// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

namespace ModellingToolset
{
	/** Adds the "Modelling Assistant" toolbar button to the Level Editor and registers its tab. Safe to call when there is no UI (commandlets). */
	void RegisterAssistantUI();
	void UnregisterAssistantUI();

	/** Opens (or focuses) the Modelling Assistant tab. */
	void OpenAssistantTab();
}
