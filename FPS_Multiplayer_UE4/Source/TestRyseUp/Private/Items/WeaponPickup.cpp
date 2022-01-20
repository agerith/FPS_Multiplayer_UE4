// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponPickup.h"
#include "TestRyseUpCharacter.h"
#include "Weapon.h"
#include "WeaponPickup.h"
#include "TestRyseUp.h"

AWeaponPickup::AWeaponPickup(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bAllowRespawn = false;

	/* Enabled to support simulated physics movement when weapons are dropped by a player */
	bReplicateMovement = true;
}

void AWeaponPickup::OnUsed(APawn* InstigatorPawn)
{
	ATestRyseUpCharacter* MyPawn = Cast<ATestRyseUpCharacter>(InstigatorPawn);
	if (MyPawn)
	{
		if (MyPawn->WeaponSlotAvailable(WeaponClass->GetDefaultObject<AWeapon>()->GetStorageSlot()))
		{
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			AWeapon* NewWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass, SpawnInfo);

			MyPawn->AddWeapon(NewWeapon);

			Super::OnUsed(InstigatorPawn);
		}
	}
}


