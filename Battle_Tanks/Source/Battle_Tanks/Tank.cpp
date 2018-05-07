// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Turret.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
	
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay(); // Required for BP Begin Play!! (If you don't have this line, your BP will not work)

}


void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent)
		return;
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}

void ATank::Fire()
{
	if (!Barrel) { return; }

	 isReloaded = (FPlatformTime::Seconds()- LastFireTime) > ReloadTimeInSeconds;


	if (isReloaded)
	{
		auto projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("FireSpawn")), Barrel->GetSocketRotation(FName("FireSpawn")));
		projectile->Launchprojectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	

	
	
}
