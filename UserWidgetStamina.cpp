// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetStamina.h"
#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

float UUserWidgetStamina::GetCharacterStamina()
{
	APlayerCharacter* OurPlayer = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	
	return OurPlayer->Stamina / 100.f;
}
