// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Turret.h"
#include "TankAimingComponent.generated.h"

//enum for aiming states
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};


class UTankBarrel;
class UTurret;
class AProjectile;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties


	// TODO add SetTurretReference
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();




	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000.f;

	UPROPERTY(EditAnywhere, Category = Firing)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0;
	float ReloadTimeInSeconds = 3;
	bool isReloaded = false;


	void AimAt(FVector HitLocation, float LaunchSpeed);
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTurret* TurretToSet);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringState = EFiringStatus::Reloading;
private:
	UTankAimingComponent();

	UTankBarrel * Barrel = nullptr;
	UTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);




	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	virtual void BeginPlay() override;

};