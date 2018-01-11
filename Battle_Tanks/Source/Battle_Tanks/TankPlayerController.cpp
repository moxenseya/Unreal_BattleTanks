// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	
	
		return Cast<ATank>(GetPawn());
	
		
		
}

void ATankPlayerController::BeginPlay()
{

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Found Player Controller"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Player Controller: %s"), *ControlledTank->GetName());
	}

	Super::BeginPlay();
}
