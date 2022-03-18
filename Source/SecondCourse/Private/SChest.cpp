// Fill out your copyright notice in the Description page of Project Settings.


#include "SChest.h"
#include <Components/StaticMeshComponent.h>

// Sets default values
ASChest::ASChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMeshh"));
	LidMesh->SetupAttachment(RootComponent);

	//Variables
	TargetPitch = 110;

	bclosed = true;
}

// Called when the game starts or when spawned
void ASChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASChest::Interact_Implementation(APawn* InstigatorPawn)
{
	if (bclosed)
	{
		LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
		bclosed = false;
	}
	else
	{
		LidMesh->SetRelativeRotation(FRotator(0, 0, 0));
		bclosed = true;
	}
	
}

