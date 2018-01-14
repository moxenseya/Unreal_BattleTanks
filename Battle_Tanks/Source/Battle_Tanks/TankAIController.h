// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

		ATank* GetControlledTank() const;
	void BeginPlay() override;
	ATank* GetPlayerTank() const;
	void Tick(float DeltaTime) override;
};
