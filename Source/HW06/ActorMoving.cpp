// ActorMoving.cpp

// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorMoving.h"

// Sets default values
AActorMoving::AActorMoving()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 200.f;
	MaxRange = 300.f;
	Direcion = 1;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	// 큐브 또는 메시에 대한 경로를 TEXT 안에 넣기
	// /Script/Engine.StaticMesh'/Engine/BasicShapes/Sphere.Sphere'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (cubeMesh.Succeeded())
	{
		UStaticMesh* InStaticMesh = cubeMesh.Object;
		Mesh->SetStaticMesh(InStaticMesh);
	}

	// /Script/Engine.Material'/Engine/EngineMaterials/ScreenMaterial.ScreenMaterial'
	static ConstructorHelpers::FObjectFinder<UMaterial> goldMat(TEXT("/Engine/EngineMaterials/ScreenMaterial.ScreenMaterial"));

	if (goldMat.Succeeded())
	{
		UMaterialInterface* Material = goldMat.Object;
		Mesh->SetMaterial(0, Material);
	}
}

// Called when the game starts or when spawned
void AActorMoving::BeginPlay()
{
	Super::BeginPlay();

	// 스타트 StartLocation()
	
	StartLocation = GetActorLocation();
	
}

// Called every frame
void AActorMoving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 이동 제한 MaxRange()
	FVector CurLocation = GetActorLocation();
	float DistanceY = CurLocation.Y - StartLocation.Y;

	if ((DistanceY >= MaxRange && Direcion > 0) || (DistanceY <= -MaxRange && Direcion < 0))
	{
		Direcion *= -1;
	}

	// 무브 스피드 MoveSpeed()
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.Y += DeltaTime * MoveSpeed * Direcion;
	AddActorWorldOffset(DeltaLocation);

}

