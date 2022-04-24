// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction.h"
#include "ActionComponent.h"
#include <GameplayTagContainer.h>

void USAction::StartAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Running: %s"), *GetNameSafe(this));

	UActionComponent* Comp = GetOwningComponent();

	Comp->ActiveGamePlayTags.AppendTags(GrantsTags);

	bIsRunning = true;

}

void USAction::StopAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Stopped: %s"), *GetNameSafe(this));

	ensureAlways(bIsRunning);

	UActionComponent* Comp = GetOwningComponent();
	Comp->ActiveGamePlayTags.RemoveTags(GrantsTags);

	bIsRunning = false;
}



UWorld* USAction::GetWorld() const
{
	//Outer is set when vreating action via newObject
	UActorComponent* Comp = Cast<UActorComponent>(GetOuter());
	if (Comp)
	{
		return Comp->GetWorld();
	}
	return nullptr;
}

bool USAction::CanStart_Implementation(AActor* Instigator)
{
	if (IsRunning())
	{
		return false;
	}
	UActionComponent* Comp = GetOwningComponent();

	if (Comp->ActiveGamePlayTags.HasAny(BlockedTags))
	{
		return false;
	}
	return true;
}

UActionComponent* USAction::GetOwningComponent() const
{
	return Cast<UActionComponent>(GetOuter());
}

bool USAction::IsRunning() const
{
	return bIsRunning;
}

