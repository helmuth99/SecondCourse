// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;
class UAnimMontage;
class USAttributeComponent;
class UActionComponent;

UCLASS()
class SECONDCOURSE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USAttributeComponent* AttributeComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UActionComponent* ActionComp;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	FTimerHandle TimerHandle_Attack1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void SprintStart();

	void SprintStop();

	void Action1();

	void TimeEllaps();

<<<<<<< Updated upstream
=======
	UFUNCTION()
	void OnHealthChanged(USAttributeComponent* OwningComp, AActor* InstigatorActor, float NewHealth, float Delta);

	virtual void PostInitializeComponents() override;

	virtual FVector GetPawnViewLocation() const override;

>>>>>>> Stashed changes

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(Exec)
	void HealSelf(float Amount);

};
