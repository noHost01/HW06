// RandowSpawner.cpp

// Fill out your copyright notice in the Description page of Project Settings.


#include "RandowSpawner.h"
#include "ActorRotating.h"
#include "ActorMoving.h"
#include "TimerManager.h"
#include "Engine/World.h"

// Sets default values
ARandowSpawner::ARandowSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ARandowSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ARandowSpawner::SpawnRandomActor, 2.0f, true);
	
}

// Called every frame
void ARandowSpawner::SpawnRandomActor()
{
	FVector RandomLocation;
	RandomLocation.X = FMath::RandRange(-500.f, 500.f);
	RandomLocation.Y = FMath::RandRange(-500.f, 500.f);
	RandomLocation.Z = 100.f;

	FRotator RandomRotation = FRotator::ZeroRotator;
	RandomRotation.Yaw = FMath::RandRange(0.f, 360.f);

	int32 RandomType = FMath::RandRange(0, 1);

	if (RandomType == 0)
	{
		GetWorld()->SpawnActor<AActorRotating>(AActorRotating::StaticClass(), RandomLocation, RandomRotation);
	}
	else
	{
		GetWorld()->SpawnActor<AActorMoving>(AActorMoving::StaticClass(), RandomLocation, RandomRotation);
	}

}

