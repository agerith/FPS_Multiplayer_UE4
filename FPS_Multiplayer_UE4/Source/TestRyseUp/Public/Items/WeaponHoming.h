// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapon.h"
#include "WeaponHoming.generated.h"

/**
 * 
 */
UCLASS()
class TESTRYSEUP_API AWeaponHoming : public AWeapon
{
	GENERATED_BODY()
	
protected:

	AWeaponHoming(const FObjectInitializer& ObjectInitializer);

	/************************************************************************/
	/* Damage Processing                                                    */
	/************************************************************************/

	virtual void FireWeapon() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Fire")
	void Fire();
	
	
};
