// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestRyseUpPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTRYSEUP_API ATestRyseUpPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	ATestRyseUpPlayerController(const FObjectInitializer& ObjectInitializer);

	/* Flag to respawn or start spectating upon death */
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	bool bRespawnImmediately;
	
};
