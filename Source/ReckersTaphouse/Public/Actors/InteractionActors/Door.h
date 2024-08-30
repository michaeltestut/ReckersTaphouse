// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/InteractionActor.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class RECKERSTAPHOUSE_API ADoor : public AInteractionActor
{
	GENERATED_BODY()


public:
	virtual void Interact() override;
};
