// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"




void UTankBarrel::Elevate(float DegreesPerSecond)
{
	float FinalDegreePerSecond = FMath::Clamp(DegreesPerSecond, -1.f, 1.f);

	auto ElevationChange = FinalDegreePerSecond * MaxDegreePerSecond * GetWorld()->GetDeltaSeconds();
	auto RawElevation = RelativeRotation.Pitch + ElevationChange;
	auto trueElevation = FMath::Clamp(RawElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(trueElevation,0,0));
	
}