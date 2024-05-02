// Copyright Epic Games, Inc. All Rights Reserved.

#include "ReckersTaphouseGameMode.h"
#include "ReckersTaphouseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AReckersTaphouseGameMode::AReckersTaphouseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
