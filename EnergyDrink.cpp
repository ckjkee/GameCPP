// Fill out your copyright notice in the Description page of Project Settings.


#include "EnergyDrink.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnergyDrink::AEnergyDrink()
{
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
    Mesh->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
    Mesh->OnComponentBeginOverlap.AddDynamic(this, &AEnergyDrink::Overlap);
}

void AEnergyDrink::Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& HitResult)
{
    IInteractionInterface::Execute_AddStamina(OtherActor,StaminaToAdd);
    if (DrinkSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, DrinkSound, GetActorLocation(), 1.f, 1.f, 0.f);
    }
    Destroy();
}


