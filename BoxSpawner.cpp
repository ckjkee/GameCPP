// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxSpawner.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABoxSpawner::ABoxSpawner()
{
	SpawnObjectCount = 5;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

// Called when the game starts or when spawned
void ABoxSpawner::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle SpawnDelay;
	GetWorldTimerManager().SetTimer(SpawnDelay, this, &ABoxSpawner::SpawnActor, 5.f, bShouldSpawnLoop, 1);
}

void ABoxSpawner::SpawnActor()
{
	for(int i  = 0; i < SpawnObjectCount; ++i)
	{
		FRotator Rotation(0, 0, 0);
		FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxCollision->GetScaledBoxExtent());
		GetWorld()->SpawnActor<AActor>(SpawnerClass, RandomLocation, Rotation);
	}
	
}


