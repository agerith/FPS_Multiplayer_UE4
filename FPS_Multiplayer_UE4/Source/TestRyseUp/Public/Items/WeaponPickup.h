// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PickupActor.h"
#include "Weapon.h"
#include "WeaponPickup.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TESTRYSEUP_API AWeaponPickup : public APickupActor
{
	GENERATED_BODY()
		
	AWeaponPickup(const FObjectInitializer& ObjectInitializer);
	

public:

	/* Class to add to inventory when picked up */
	UPROPERTY(EditDefaultsOnly, Category = "WeaponClass")
	TSubclassOf<AWeapon> WeaponClass;

	virtual void OnUsed(APawn* InstigatorPawn) override;
	
	
};
