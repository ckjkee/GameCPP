// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "InteractionInterface.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class GAMETUTORIALCPP_API APlayerCharacter : public AMainCharacter,  public IInteractionInterface
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

    void Tick(float DeltaTime) override;

	void RegulateStamina();

	UPROPERTY(EditDefaultsOnly, Category = "Stamina")
	bool bIsSprinting;
	UPROPERTY(EditDefaultsOnly, Category = "Stamina")
	float MinusStamina = 1.f;
	UPROPERTY(EditDefaultsOnly, Category = "Stamina")
	float PlusStamina = 1.f;
	UPROPERTY(EditDefaultsOnly, Category = "Stamina", meta = (ClampMin = "0", ClampMax = "100"))
	float Stamina = 100.f; 

	//===========================================IInterface=================================//

	
	void AddStamina_Implementation(float value) override;

	//===============================LineTrace===================================//

	UFUNCTION()
	void TouchEnemy();

};
