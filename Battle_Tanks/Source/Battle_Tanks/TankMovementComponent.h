// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 *
 */
class UTrack;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable)
		void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable)
		void IntendMoveBackward(float Throw);
	UFUNCTION(BlueprintCallable)
		void IntendTurnLeft(float Throw);
	UFUNCTION(BlueprintCallable)
		void IntendTurnRight(float Throw);





	UFUNCTION(BlueprintCallable)
		void Initialise(UTrack* LeftTrackToSet, UTrack* RightTrackToSet);



private:
	//call from the pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTrack * LeftTrack = nullptr;
	UTrack * RightTrack = nullptr;
};
