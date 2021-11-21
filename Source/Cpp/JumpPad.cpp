// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFrameWork/Character.h"
#include "JumpPad.h"

// Sets default values
AJumpPad::AJumpPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	StaticMesh->SetSimulatePhysics(true);
	StaticMesh->OnComponentHit.AddDynamic(this, &AJumpPad::OnHit);

	RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
void AJumpPad::BeginPlay()
{
	Super::BeginPlay();

	//GLog->Log("Bonjour");
}

// Called every frame
void AJumpPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJumpPad::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (!Character)
		return;

	Character->LaunchCharacter(FVector(0, 0, 1000), false, true);
}

