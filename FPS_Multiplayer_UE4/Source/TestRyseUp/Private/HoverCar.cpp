// Fill out your copyright notice in the Description page of Project Settings.

#include "HoverCar.h"
#include "TestRyseUp.h"
//#include "Runtime/Engine/Classes/GameFramework/PlayerController.h


// Sets default values
AHoverCar::AHoverCar()
{
	SetReplicates(true);
	bReplicateMovement = true;
}

// Called when the game starts or when spawned
void AHoverCar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void AHoverCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Interaction
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &AHoverCar::ReturnToPawn);
}

void AHoverCar::ReturnToPawn()
{
	// Only allow on server. If called on client push this request to the server
	if (Role == ROLE_Authority)
	{
		PossessCar(previousPawn);

		if (previousController != nullptr)
			previousController->UnPossess();

		if (previousController->GetPawn() == NULL)
		{
			previousController->Possess(previousPawn);
			previousPawn->SetOwner(previousController);
		}

		previousPawn = nullptr;
	}
	else
	{
		ServerReturnToPawn();
	}
}

void AHoverCar::ServerReturnToPawn_Implementation()
{
	ReturnToPawn();
}

bool AHoverCar::ServerReturnToPawn_Validate()
{
	return true;
}


void AHoverCar::OnUsed(APawn* InstigatorPawn)
{
	if (!previousPawn)
	{
		previousPawn = InstigatorPawn;

		AController* controller = InstigatorPawn->GetController();
		previousController = controller;


		controller->UnPossess();

		if (controller->GetPawn() == NULL)
		{
			controller->Possess(this);
			InstigatorPawn->SetOwner(controller);
		}

		PossessCar(previousPawn);
	}

	return;
}

void AHoverCar::PossessCar_Implementation(APawn* InstigatorPawn)
{
}

