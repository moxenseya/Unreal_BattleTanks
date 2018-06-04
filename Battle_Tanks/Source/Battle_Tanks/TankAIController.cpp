// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = (GetPawn());
	auto *AimingComp = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(PlayerTank && AITank)) { return; }
	if (!ensure(AimingComp)) { return; }


	MoveToActor(PlayerTank, AcceptanceRadius);

	AimingComp->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		AimingComp->Fire();
	
}