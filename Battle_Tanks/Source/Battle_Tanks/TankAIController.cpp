// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	PlayerTank = Cast<ATank> (GetWorld()->GetFirstPlayerController()->GetPawn());
	AITank = Cast<ATank>(GetPawn());

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{



	Super::Tick(DeltaTime);
	if (!PlayerTank || !AITank) { return; }
	
	

		// TODO Move towards the player

		// Aim towards the player
		AITank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		AITank->Fire();
	
}