// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "Components/PointLightComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LifeTrigger.generated.h"

UCLASS()
class CPP_API ALifeTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALifeTrigger();

	UPROPERTY(EditAnywhere, Category = "Params")
	UPointLightComponent* Light;

	UPROPERTY(EditAnywhere, Category = "Params")
	int HealthAdded;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Box;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
