// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	Mesh->SetStaticMesh(MeshRef.Object);

	Mesh->SetWorldScale3D(FVector(0.2F, 0.1F, 0.1F));

	//if (PrimitiveComponent != nullptr) {
	//	PrimitiveComponent->SetPhysicsLinearVelocity(GetActorForwardVector() * 3000);
	//}
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("HELLO"));
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

}
