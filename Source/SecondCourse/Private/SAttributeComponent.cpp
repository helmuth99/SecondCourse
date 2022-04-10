// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"

bool USAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	MaxHealth = 100;
	Health = MaxHealth;
}

bool USAttributeComponent::ApplyHealthChange(float delta)
{
	Health += delta;
	OnHealthChanged.Broadcast(this, nullptr, Health, delta);
	return true;
}

