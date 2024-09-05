// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MainCharacter.generated.h"

UCLASS()
class GAMETUTORIALCPP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	UPROPERTY(EditDefaultsOnly,Category = "CharacterStamina")
	float CharacterStamina;
	bool bIsTired;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	USoundBase* TiredSound;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	UAnimMontage* VertigoAnimation;

	float GetStaminaPercent() const;
	float AddStamina();
	float DecreaseStamina();
	bool StaminaIsZero(); // func for character death
};
