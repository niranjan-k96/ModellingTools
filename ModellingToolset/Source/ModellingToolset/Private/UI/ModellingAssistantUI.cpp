// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingAssistantUI.h"

#include "SModellingAssistant.h"

#include "Framework/Application/SlateApplication.h"
#include "Framework/Docking/TabManager.h"
#include "Misc/CoreDelegates.h"
#include "Styling/AppStyle.h"
#include "ToolMenus.h"
#include "Widgets/Docking/SDockTab.h"

#define LOCTEXT_NAMESPACE "ModellingAssistantUI"

namespace ModellingToolset
{
	namespace
	{
		const FName TabId(TEXT("ModellingAssistant"));
		const FName OwnerName(TEXT("ModellingToolsetAssistant"));
		bool bTabRegistered = false;
		FDelegateHandle StartupCallbackHandle;

		TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& Args)
		{
			return SNew(SDockTab)
				.TabRole(ETabRole::NomadTab)
				.Label(LOCTEXT("TabLabel", "Modelling Assistant"))
				[
					SNew(SModellingAssistant)
				];
		}

		void RegisterMenus()
		{
			FToolMenuOwnerScoped OwnerScoped(OwnerName);

			UToolMenu* Toolbar = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.User");
			FToolMenuSection& Section = Toolbar->FindOrAddSection("ModellingToolset");
			Section.AddEntry(FToolMenuEntry::InitToolBarButton(
				"OpenModellingAssistant",
				FUIAction(FExecuteAction::CreateStatic(&OpenAssistantTab)),
				LOCTEXT("ButtonLabel", "Modelling Assistant"),
				LOCTEXT("ButtonTip", "Open the step-by-step helper for modelling with an AI assistant: add reference images, describe what to build, press Go."),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.StaticMeshActor")));
		}
	}

	void RegisterAssistantUI()
	{
		// No UI in commandlets or headless runs.
		if (IsRunningCommandlet() || IsRunningDedicatedServer() || !FSlateApplication::IsInitialized())
		{
			return;
		}

		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TabId, FOnSpawnTab::CreateStatic(&SpawnTab))
			.SetDisplayName(LOCTEXT("TabLabel", "Modelling Assistant"))
			.SetTooltipText(LOCTEXT("TabTip", "Step-by-step modelling with an AI assistant."))
			.SetMenuType(ETabSpawnerMenuType::Hidden);
		bTabRegistered = true;

		StartupCallbackHandle = UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateStatic(&RegisterMenus));
	}

	void UnregisterAssistantUI()
	{
		if (StartupCallbackHandle.IsValid())
		{
			UToolMenus::UnRegisterStartupCallback(StartupCallbackHandle);
			StartupCallbackHandle.Reset();
		}
		if (UToolMenus::IsToolMenuUIEnabled())
		{
			UToolMenus::UnregisterOwner(OwnerName);
		}
		if (bTabRegistered && FSlateApplication::IsInitialized())
		{
			FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TabId);
		}
		bTabRegistered = false;
	}

	void OpenAssistantTab()
	{
		if (FSlateApplication::IsInitialized())
		{
			FGlobalTabmanager::Get()->TryInvokeTab(TabId);
		}
	}
}

#undef LOCTEXT_NAMESPACE
