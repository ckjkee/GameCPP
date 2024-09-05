// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacter.generated.h"


/**
 * 
 */
UCLASS()
class GAMETUTORIALCPP_API APlayerCharacter : public AMainCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumpAnimation")
	UAnimMontage* JumpAnimation;

	void SetupPlayerInputComponent(class UInputComponent* MyPlayerInput) override;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void Jump();

	void StopJump();

	//================================Sprint Component=================================//


	void Sprint();

	void StopSprinting();

	void IncreaseStamina();

	void DecreaseStamina();

	bool bIsSprinting;
	float CurrentStamina;
	float MinusStamina = 1.f;
	float PlusStamina = 1.f;
	//float Stamina = 100.f;
};
