// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto *AimingComp = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (AimingComp)
	{
		FoundAimingComponent(AimingComp);
		//UE_LOG(LogTemp, Warning, TEXT("Aiming Component was FOUND! by tank player controller on Begin Play"))


	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Aiming Component was not found by tank player controller on Begin Play"))
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


void ATankPlayerController::AimTowardsCrosshair()
{

	if (!GetPawn()) { return; }
	auto *AimingComp = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComp)) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		AimingComp->AimAt(HitLocation);
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//	UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}

	// Line-trace along that LookDirection, and see what we hit (up to max range)
	GetLookVectorHitLocation(LookDirection, HitLocation);
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult hitresult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection *LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(hitresult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = hitresult.Location;
		return true;
	}
	HitLocation = FVector(0.f);
	return false;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);

}


