// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <GameFramework/Character.h>
#include "SInteractionComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;


	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	InteractionComp = CreateDefaultSubobject<USInteractionComponent>("InteractionComp");

	//setup variables

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	

}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Action1", IE_Pressed, this, &ASCharacter::Action1);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this->InteractionComp, &USInteractionComponent::PrimaryInteract);
}

void ASCharacter::MoveForward(float Value)
{
	FRotator Controllrotation = GetControlRotation();
	Controllrotation.Pitch = 0.0f;
	Controllrotation.Roll = 0.0f;
	AddMovementInput(Controllrotation.Vector(), Value);
}

void ASCharacter::MoveRight(float Value)
{
	FRotator Controllrotation = GetControlRotation();
	Controllrotation.Pitch = 0.0f;
	Controllrotation.Roll = 0.0f;

	FVector RightVector =FRotationMatrix(Controllrotation).GetScaledAxis(EAxis::Y);


	AddMovementInput(RightVector, Value);
}

void ASCharacter::Action1()
{
	
	if (ProjectileClass) 
	{
		FVector HandLocatoin = GetMesh()->GetSocketLocation("Muzzle_01");
		FTransform SpawnTM = FTransform(GetControlRotation(), HandLocatoin);
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
	}
	
}



