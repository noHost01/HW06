// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorRotating.h"

// Sets default values
AActorRotating::AActorRotating()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	// 큐브 또는 메시에 대한 경로를 TEXT 안에 넣기
	// /Script/Engine.StaticMesh'/Engine/BasicShapes/Plane.Plane'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("/Engine/BasicShapes/Plane.Plane"));
	if (cubeMesh.Succeeded())
	{
		UStaticMesh* InStaticMesh = cubeMesh.Object;
		Mesh->SetStaticMesh(InStaticMesh);
	}

	// /Script/Engine.Material'/Engine/EngineMaterials/CubeMaterial.CubeMaterial'
	static ConstructorHelpers::FObjectFinder<UMaterial> goldMat(TEXT("/Engine/EngineMaterials/CubeMaterial.CubeMaterial"));

	if (goldMat.Succeeded())
	{
		UMaterialInterface* Material = goldMat.Object;
		Mesh->SetMaterial(0, Material);
	}
}

// Called when the game starts or when spawned
void AActorRotating::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorRotating::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Yaw += DeltaTime * RotateSpeed;
	AddActorLocalRotation(DeltaRotation);

}

