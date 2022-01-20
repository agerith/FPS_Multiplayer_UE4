// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PickupActor.h"
#include "ConsumableActor.generated.h"

/**
 * 
 */
UCLASS()
class TESTRYSEUP_API AConsumableActor : public APickupActor
{
	GENERATED_BODY()

	AConsumableActor(const FObjectInitializer& ObjectInitializer);

protected:
	
	/* Consume item, restoring energy to player */
	virtual void OnUsed(APawn* InstigatorPawn) override;

	/* Amount of hitpoints restored and hunger reduced when consumed. */
	UPROPERTY(EditDefaultsOnly, Category = "Consumable")
	float Nutrition;

};
