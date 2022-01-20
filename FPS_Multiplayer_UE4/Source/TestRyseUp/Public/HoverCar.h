// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HoverCar.generated.h"

UCLASS()
class TESTRYSEUP_API AHoverCar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHoverCar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/* Use the usable actor currently in focus, if any */
	virtual void ReturnToPawn();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReturnToPawn();

	void ServerReturnToPawn_Implementation();

	bool ServerReturnToPawn_Validate();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Possess")
	void PossessCar(APawn* InstigatorPawn);

	/* Called when player enter with object */
	virtual void OnUsed(APawn* InstigatorPawn);

	APawn* previousPawn;
	AController* previousController;
	
};
