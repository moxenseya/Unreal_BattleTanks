// Fill out your copyright notice in the Description page of Project Settings.

#include "Track.h"


UTrack::UTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UTrack::BeginPlay()

{

	OnComponentHit.AddDynamic(this, &UTrack::OnHit);

}



void UTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)

{

	DriveTrack();

	ApplySidewaysForce();

	CurrentThrottle = 0;

}



void UTrack::ApplySidewaysForce()

{

	// Work-out the required acceleration this frame to correct

	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();



	// Calculate and apply sideways (F = m a)

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tracks

	TankRoot->AddForce(CorrectionForce);

}



void UTrack::SetThrottle(float Throttle)

{

	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);

}



void UTrack::DriveTrack()

{

	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;

	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}