// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PredictionIndicator.generated.h"

UCLASS()
class ANGRYBIRDS_API APredictionIndicator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APredictionIndicator();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* IndicatorActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DestroyDelay{ 0.05f };

	FTimerHandle DestroyTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DestryIndicator();

};
