// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_EnemyController.generated.h"

class UNavigationSystemV1;

UCLASS()
class GAMETUTORIALCPP_API AAI_EnemyController : public AAIController
{
	GENERATED_BODY()

public:

	void BeginPlay() override;

	UFUNCTION()
	void RandomPatrol();

	UFUNCTION(BlueprintCallable)
	void RunAwayFromPlayer();

	UFUNCTION(BlueprintCallable)
	void ClearTimer();

	UNavigationSystemV1* NavigationMesh;
	FVector RandomLocation;
	FTimerHandle PointDelay;
	bool bPlayerIsNear;
	FTimerHandle RunAway;

	
	
};
