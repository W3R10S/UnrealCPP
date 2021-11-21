// Fill out your copyright notice in the Description page of Project Settings.


#include "Lava.h"
#include "Components/StaticMeshComponent.h"
#include "CppCharacter.h"

// Sets default values
ALava::ALava()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LavaMesh"));

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	Box->OnComponentBeginOverlap.AddDynamic(this, &ALava::OnActorBeginOverlap);
}

// Called when the game starts or when spawned
void ALava::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALava::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALava::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	ACppCharacter* Character = Cast<ACppCharacter>(OtherActor);
	if (!Character)
		return;

	Character->Health = 0;
	Character->OnHealthChanged();
}