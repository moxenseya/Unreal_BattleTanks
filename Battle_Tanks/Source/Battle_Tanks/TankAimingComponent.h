// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Turret.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state

UENUM()

enum class FiringState : uint8

{

	Reloading,

	Aiming,

	Locked,

	Empty

};



// Forward Declaration

class UTankBarrel;

class UTurret;

class AProjectile;



// Holds barrel's properties and Elevate method

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class BATTLE_TANKS_API UTankAimingComponent : public UActorComponent

{

	GENERATED_BODY()



public:

	UFUNCTION(BlueprintCallable, Category = "Setup")

		void Initialise(UTankBarrel* BarrelToSet, UTurret* TurretToSet);



	void AimAt(FVector HitLocation);
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		int32 rounds = 3;

		UFUNCTION(BlueprintCallable, Category = "Firing")
			int getrounds();


	UFUNCTION(BlueprintCallable, Category = "Firing")

		void Fire();

	FiringState GetFiringState() const;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")

		FiringState FiringState = FiringState::Reloading;



private:

	// Sets default values for this component's properties

	UTankAimingComponent();



	virtual void BeginPlay() override;



	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;



	void MoveBarrelTowards(FVector AimDirection);



	bool IsBarrelMoving();



	UTankBarrel* Barrel = nullptr;

	UTurret* Turret = nullptr;



	UPROPERTY(EditDefaultsOnly, Category = "Firing")

		float LaunchSpeed = 4000;



	UPROPERTY(EditDefaultsOnly, Category = "Setup")

		TSubclassOf<AProjectile> ProjectileBlueprint;



	UPROPERTY(EditDefaultsOnly, Category = "Firing")

		float ReloadTimeInSeconds = 3;



	double LastFireTime = 0;



	FVector AimDirection;

};