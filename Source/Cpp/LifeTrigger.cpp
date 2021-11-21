// Fill out your copyright notice in the Description page of Project Settings.

#include "CppCharacter.h"
#include "LifeTrigger.h"

// Sets default values
ALifeTrigger::ALifeTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	Box->OnComponentBeginOverlap.AddDynamic(this, &ALifeTrigger::OnActorBeginOverlap);
}

// Called when the game starts or when spawned
void ALifeTrigger::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("TAMER"));

	if (HealthAdded < 0) {
		Light->SetLightColor(FLinearColor(1, 0, 0, 0), true);
	}
	else {
		Light->SetLightColor(FLinearColor(0, 1, 0, 0), true);
	}
}

// Called every frame
void ALifeTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALifeTrigger::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACppCharacter* Character = Cast<ACppCharacter>(OtherActor);
	if (!Character)
		return;

	Character->Health += HealthAdded;
	Character->OnHealthChanged();
}
