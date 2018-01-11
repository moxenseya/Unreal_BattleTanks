// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "TankAIController.h"
#include "Engine/World.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
	
}

void ATankAIController::BeginPlay()
{

	auto ControlledTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp,Warning, TEXT("Not Found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found the controller for Player : %s"), *(ControlledTank->GetName()));
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerController = GetWorld()->GetFirstPlayerController();
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Not Found by AI"));
		return nullptr;
	}
	else
	{
		
		return Cast<ATank>(PlayerController->GetPawn());
	}
}


