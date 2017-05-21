// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float ClampedElevation = FMath::Clamp(RawNewElevation, MinElevation, MaxElevation);
	

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
	//UE_LOG(LogTemp, Warning, TEXT("elevation: %f"), GetOwner()->GetActorRotation);
}


