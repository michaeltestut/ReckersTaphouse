// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/InteractionActor.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "ReckersTaphouse/ReckersTaphouseCharacter.h"

// Sets default values
AInteractionActor::AInteractionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene=CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidgetComponent"));
	InteractionWidget->SetupAttachment(GetRootComponent());
	InteractionWidget->SetVisibility(false);

}

// Called when the game starts or when spawned
void AInteractionActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AInteractionActor::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AInteractionActor::OnSphereEndOverlap);
}

void AInteractionActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		if(AReckersTaphouseCharacter* PlayerCharacter = Cast<AReckersTaphouseCharacter>(OtherActor))
		{
			InteractionWidget->SetVisibility(true);
			PlayerCharacter->SetOverlappedItem(this);
			
		}
	
}

void AInteractionActor::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(AReckersTaphouseCharacter* PlayerCharacter = Cast<AReckersTaphouseCharacter>(OtherActor))
	{
		InteractionWidget->SetVisibility(false);
		PlayerCharacter->SetOverlappedItem(nullptr);
			
	}
}

// Called every frame
void AInteractionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractionActor::Interact()
{
	IInteractionInterface::Interact();
	
}

