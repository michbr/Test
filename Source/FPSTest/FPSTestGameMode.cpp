// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "FPSTest.h"
#include "FPSTestGameMode.h"
#include "FPSTestHUD.h"
#include "FPSTestCharacter.h"

AFPSTestGameMode::AFPSTestGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSTestHUD::StaticClass();
}
