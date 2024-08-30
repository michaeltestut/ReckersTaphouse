// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/InteractionActors/Door.h"

#include "Kismet/GameplayStatics.h"


void ADoor::Interact()
{
	Super::Interact();

	UGameplayStatics::OpenLevel(this, FName("BarExterior"));
	

}
