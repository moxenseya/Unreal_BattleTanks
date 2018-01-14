// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANKS_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		void RotateTurret(float DegreesPerSecond);
	
		UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 25;
};
