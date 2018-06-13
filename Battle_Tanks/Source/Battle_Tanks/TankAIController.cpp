// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()

{

	Super::BeginPlay();

}



// Called every frame

void ATankAIController::Tick(float DeltaTime)

{

	Super::Tick(DeltaTime);


	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	auto ControlledTank = GetPawn();



	if (!ensure(PlayerTank && ControlledTank)) { return; }



	// Move towards the player

	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm



											   // Aim towards the player

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

	AimingComponent->AimAt(PlayerTank->GetActorLocation());


	if(AimingComponent->GetFiringState() == FiringState::Locked)
	AimingComponent->Fire(); // TODO limit firing rate

}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank))
		{
			return;
		}
		PossessedTank->OnDeath.AddUniqueDynamic(this, & ATankAIController::OnPossessedTankDeath);

		//TODO subscribe our local method to tank's death event
	}
	
}

void ATankAIController::OnPossessedTankDeath()
{
	GetPawn()->DetachFromControllerPendingDestroy();
	UE_LOG(LogTemp, Warning, TEXT("AI Has been Killed"));
}