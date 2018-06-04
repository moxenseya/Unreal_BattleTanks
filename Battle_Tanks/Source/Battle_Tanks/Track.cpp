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
void UTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	auto SidewaysVector = GetRightVector();
	auto VelocityofTank = GetComponentVelocity();
	auto SlippageSpeed = FVector::DotProduct(VelocityofTank,SidewaysVector);


	auto correctionacceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * correctionacceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}


void UTrack::SetThrottle(float Throttle)
{
	
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);

	UE_LOG(LogTemp, Warning, TEXT("Throttling!! %s") ,*ForceApplied.ToString());
}

void UTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{

	UE_LOG(LogTemp, Warning, TEXT("I'm HIT I'm HIT!!"));
}
