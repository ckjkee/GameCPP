// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMETUTORIALCPP_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	 void NativeInitializeAnimation() override;
	 void NativeUpdateAnimation(float DeltaSeconds) override;

	 APawn* MyCharacter;
	 UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	 float Speed;
	 
};
