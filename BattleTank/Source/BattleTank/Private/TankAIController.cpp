// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("AIController begin Play"));

	ControlledTank = GetControlledTank();

	if (ControlledTank)
	{
	//	UE_LOG(LogTemp, Warning, TEXT("AIcontrolledTank: %s"), *(tank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't find controlled tank"));
	}

	PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
	//	UE_LOG(LogTemp, Warning, TEXT("Found player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No player tank"));
	}
}

void ATankAIController::Tick(float DeltaTime) 
{
	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

