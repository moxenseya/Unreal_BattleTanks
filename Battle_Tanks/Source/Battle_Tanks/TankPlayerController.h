// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent *AimCompRef);
private:
	
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	void SetPawn(APawn * InPawn) override;
	UFUNCTION()
	void OnPossessedTankDeath();

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = .5;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = .33333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.f;
	
};
