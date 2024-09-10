// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoxSpawner.generated.h"

class UBoxComponent;

UCLASS()
class GAMETUTORIALCPP_API ABoxSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UBoxComponent* BoxCollision;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> SpawnerClass;

	UPROPERTY(EditDefaultsOnly)
	int SpawnObjectCount;

	UPROPERTY(EditDefaultsOnly)
	bool bShouldSpawnLoop;

	void SpawnActor();

};
