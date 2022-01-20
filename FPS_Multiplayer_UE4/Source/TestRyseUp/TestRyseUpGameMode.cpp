// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TestRyseUpGameMode.h"
#include "TestRyseUpHUD.h"
#include "TestRyseUpCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestRyseUpGameMode::ATestRyseUpGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestRyseUpHUD::StaticClass();
}
