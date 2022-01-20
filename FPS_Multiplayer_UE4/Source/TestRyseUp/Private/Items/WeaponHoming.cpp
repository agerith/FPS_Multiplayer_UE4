// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponHoming.h"
#include "TestRyseUp.h"
#include "ImpactEffect.h"
#include "TestRyseUpCharacter.h"
#include "TestRyseUpPlayerController.h"

AWeaponHoming::AWeaponHoming(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
}

void AWeaponHoming::FireWeapon()
{
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("AWeaponHoming::FireWeapon"));
	Fire();
}

void AWeaponHoming::Fire_Implementation()
{
}

