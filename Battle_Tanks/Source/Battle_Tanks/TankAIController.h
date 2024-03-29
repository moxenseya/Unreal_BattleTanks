// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAimingComponent.h"
#include "TankAIController.generated.h"



class UTankAimingComponent;
/**
 *
 */
UCLASS()
class BATTLE_TANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:

	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	virtual void SetPawn(APawn *InPawn) override;
	
	UFUNCTION()
	void OnPossessedTankDeath();
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 80000.f;
	
};
