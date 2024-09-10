// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialGameMode.h"
#include "CharacterHUD.h"

ATutorialGameMode::ATutorialGameMode() : Super()
{
	ConstructorHelpers::FClassFinder<APawn> PlayerCharacter(TEXT("/Game/Blueprints/BP_PlayerCharacter"));
	DefaultPawnClass = PlayerCharacter.Class;
	HUDClass = ACharacterHUD::StaticClass();
}
