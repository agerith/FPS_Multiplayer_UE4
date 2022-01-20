// Fill out your copyright notice in the Description page of Project Settings.

#include "BombActor.h"
#include "TestRyseUp.h"

ABombActor::ABombActor(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	FuzePCS = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Fuze"));
	FuzePCS->bAutoActivate = false;
	FuzePCS->bAutoDestroy = false;
	FuzePCS->SetupAttachment(RootComponent);

	ExplosionPCS = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Explosion"));
	ExplosionPCS->bAutoActivate = false;
	ExplosionPCS->bAutoDestroy = false;
	ExplosionPCS->SetupAttachment(RootComponent);

	AudioComp = ObjectInitializer.CreateDefaultSubobject<UAudioComponent>(this, TEXT("AudioComp"));
	AudioComp->bAutoActivate = false;
	AudioComp->bAutoDestroy = false;
	AudioComp->SetupAttachment(RootComponent);

	// Let the bomb be thrown and roll around
	MeshComp->SetSimulatePhysics(true);

	MaxFuzeTime = 3.0f;
	ExplosionDamage = 200;
	ExplosionRadius = 600;

	SetReplicates(true);
	bReplicateMovement = true;
}


void ABombActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Ensure the fuze timer is cleared
	GetWorld()->GetTimerManager().ClearTimer(FuzeTimerHandle);
}


void ABombActor::OnUsed(APawn* InstigatorPawn)
{
	if (bIsFuzeActive)
	{
		return;
	}

	Super::OnUsed(InstigatorPawn);

	bIsFuzeActive = true;
	// Runs on all clients (NetMulticast)
	SimulateFuzeFX();

	// Activate the fuze to explode the bomb after several seconds
	GetWorldTimerManager().SetTimer(FuzeTimerHandle, this, &ABombActor::Explode, MaxFuzeTime, false);

}


void ABombActor::Explode()
{
	if (bExploded)
	{
		return;
	}

	bExploded = true;
	// Runs on all clients (NetMulticast)
	SimulateExplosion();

	// Apply damage to player, enemies and environmental objects
	TArray<AActor*> IgnoreActors;
	UGameplayStatics::ApplyRadialDamage(this, ExplosionDamage, GetActorLocation(), ExplosionRadius, DamageType, IgnoreActors, this, nullptr);

	//DrawDebugSphere(GetWorld(), GetActorLocation(), ExplosionRadius, 32, FColor::Red, false, 1.5f);

	/* Allow clients to show FX before deleting */
	SetLifeSpan(2.0f);
}


void ABombActor::SimulateFuzeFX_Implementation()
{
	if (FuzeFX)
	{
		FuzePCS->SetTemplate(FuzeFX);
		FuzePCS->ActivateSystem();
	}
}


void ABombActor::SimulateExplosion_Implementation()
{
	// First deactivate all running fuze effects
	FuzePCS->DeactivateSystem();
	AudioComp->Stop();

	MeshComp->SetVisibility(false, false);

	// Activate all explosion effects

	if (ExplosionFX)
	{
		ExplosionPCS->SetTemplate(ExplosionFX);
		ExplosionPCS->ActivateSystem();
	}
}

float ABombActor::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	Explode();

	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}


