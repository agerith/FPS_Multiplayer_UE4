// Fill out your copyright notice in the Description page of Project Settings.

#include "ConsumableActor.h"

#include "TestRyseUp.h"
#include "ConsumableActor.h"
#include "TestRyseUpCharacter.h"


AConsumableActor::AConsumableActor(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	/* A default to tweak per food variation in Blueprint */
	Nutrition = 40;

	bAllowRespawn = true;
	RespawnDelay = 60.0f;
	RespawnDelayRange = 20.0f;
}


void AConsumableActor::OnUsed(APawn* InstigatorPawn)
{
	ATestRyseUpCharacter* Pawn = Cast<ATestRyseUpCharacter>(InstigatorPawn);
	if (Pawn)
	{
		Pawn->RestoreLife(Nutrition);
	}

	Super::OnUsed(InstigatorPawn);
}


