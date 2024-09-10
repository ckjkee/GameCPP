// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

/**
 * 
 */
UCLASS()
class GAMETUTORIALCPP_API ACharacterHUD : public AHUD
{
	GENERATED_BODY()

public:
	ACharacterHUD();

	void BeginPlay() override;

	TSubclassOf<UUserWidget> MainHUD;

	
};
