// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorMoving.generated.h"

UCLASS()
class HW06_API AActorMoving : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorMoving();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (AllowPrivateAccess = "true"))
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data", meta = (AllowPrivateAccess = "true"))
	float MaxRange;
};
