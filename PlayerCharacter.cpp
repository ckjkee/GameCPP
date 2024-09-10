// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>

APlayerCharacter::APlayerCharacter() : Super()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->bUsePawnControlRotation = true;
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false; 
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* MyPlayerInput)
{
	Super::SetupPlayerInputComponent(MyPlayerInput);

	//movement
	MyPlayerInput->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	MyPlayerInput->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	//mouse
	MyPlayerInput->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput);
	MyPlayerInput->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);

	//actions
	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	MyPlayerInput->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump);
	//Sprint
	MyPlayerInput->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint);
	MyPlayerInput->BindAction("Sprint", IE_Released, this, &APlayerCharacter::StopSprinting);
}

void APlayerCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void APlayerCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void APlayerCharacter::Jump()
{
	if (JumpAnimation)
	{
		PlayAnimMontage(JumpAnimation, 1.5f, NAME_None);
	}
	bPressedJump = true;
	
}

void APlayerCharacter::StopJump()
{
	bPressedJump = false;
}

//===============================Sprint==============================//
void APlayerCharacter::Sprint()
{
		bIsSprinting = true;
		GetCharacterMovement()->MaxWalkSpeed = 1200.f;
}

void APlayerCharacter::StopSprinting()
{
		bIsSprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

void APlayerCharacter::IncreaseStamina()
{
	Stamina = Stamina + PlusStamina;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Stamina Increase %f"), Stamina));
	}
}	

void APlayerCharacter::DecreaseStamina()
{
	Stamina = Stamina - MinusStamina;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Stamina Decrease %f"), Stamina));
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RegulateStamina();
	TouchEnemy();
}

void APlayerCharacter::RegulateStamina()
{
	if (bIsSprinting && Stamina)
	{
		DecreaseStamina();
	}
	if (!bIsSprinting && Stamina < 100.f)
	{
		IncreaseStamina();
	}
	if (FMath::IsNearlyZero(Stamina))
	{
		StopSprinting();
	}
}

void APlayerCharacter::AddStamina_Implementation(float value)
{
	Stamina += value;
}

void APlayerCharacter::TouchEnemy()
{
	FVector TraceStart = GetActorLocation();
	FRotator CharacterRotation = GetActorRotation();
	FVector TraceEnd = TraceStart + (CharacterRotation.Vector() * 300.f);
	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	
	

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 1.f, 0, 1.f);

	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, QueryParams);
	

	if (HitResult.bBlockingHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, FString::Printf(TEXT("You hit: %s"), *HitResult.GetActor()->GetName()));
	}

	AActor* Target = HitResult.GetActor();
	if (Target && Target->ActorHasTag(FName("Enemy")))
	{
		UKismetSystemLibrary::QuitGame(this, UGameplayStatics::GetPlayerController(this, 0), EQuitPreference::Quit, true);
	}
}


