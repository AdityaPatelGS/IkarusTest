// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "PlayerCharacter.generated.h"

UCLASS()
class ANGRYBIRDS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* SlingShot;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USceneComponent* LaunchPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	

};
