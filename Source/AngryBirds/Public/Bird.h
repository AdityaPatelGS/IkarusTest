// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bird.generated.h"

UCLASS()
class ANGRYBIRDS_API ABird : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABird();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* BirdMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DestroyDelay{3.0f};

	FTimerHandle DestroyTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	void DestroyBird();

	void BirdDeathCountDown();

};
