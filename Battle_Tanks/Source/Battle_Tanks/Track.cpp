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


void UTrack::ApplySidewaysForce()
{
	auto SidewaysVector = GetRightVector();
	auto VelocityofTank = GetComponentVelocity();
	auto SlippageSpeed = FVector::DotProduct(VelocityofTank, SidewaysVector);

	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto correctionacceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * correctionacceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}


void UTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
	//UE_LOG(LogTemp, Warning, TEXT("Throttling!! %s") ,*ForceApplied.ToString());
}

void UTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

void UTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
