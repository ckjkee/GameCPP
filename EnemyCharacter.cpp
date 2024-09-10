// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyCharacter::AEnemyCharacter()
{
	Tags.Add(FName("Enemy"));
	GetCharacterMovement()->MaxWalkSpeed = 900.f;
}

