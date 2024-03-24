// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Piggy.generated.h"

UCLASS()
class ANGRYBIRDS_API APiggy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiggy();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PiggyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* AreaSphere;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)

	UFUNCTION(BlueprintImplementableEvent)
	void DestroyPiggy();

};
