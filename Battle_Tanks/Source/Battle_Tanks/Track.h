// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Track.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANKS_API UTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	
};
