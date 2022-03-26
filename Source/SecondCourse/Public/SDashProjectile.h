// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBaseProjectile.h"
#include "SDashProjectile.generated.h"

/**
 * 
 */
UCLASS()
class SECONDCOURSE_API ASDashProjectile : public ASBaseProjectile
{
	GENERATED_BODY()

public:

	ASDashProjectile();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float TeleportDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float DetonationDelay;

	//Handle for Detonation
	FTimerHandle TimerHandle_DelayedDetonate;

protected:

	virtual void Explode_Implementation() override;

	void TeleportInstigator();

	virtual void BeginPlay() override;


	
};
