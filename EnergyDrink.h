// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "EnergyDrink.generated.h"

UCLASS()
class GAMETUTORIALCPP_API AEnergyDrink : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	

	AEnergyDrink();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* DrinkSound;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StaminaToAdd = 5.f;

	UFUNCTION()
	void Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool FromSweep, const FHitResult& HitResult);


};
