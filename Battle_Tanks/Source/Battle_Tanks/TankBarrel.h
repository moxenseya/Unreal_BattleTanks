 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
		UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreePerSecond = 30.f;
		UPROPERTY(EditAnywhere, Category = Setup)
		 float MaxElevationDegrees = 40;
		UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0;
};
