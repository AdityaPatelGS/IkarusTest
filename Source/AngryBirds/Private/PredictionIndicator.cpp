// Fill out your copyright notice in the Description page of Project Settings.


#include "PredictionIndicator.h"

// Sets default values
APredictionIndicator::APredictionIndicator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IndicatorActor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("IndicatorMesh"));
	IndicatorActor->SetupAttachment(RootComponent);

	IndicatorActor->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void APredictionIndicator::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(DestroyTimer, this, &APredictionIndicator::DestryIndicator, DestroyDelay, false);
}

// Called every frame
void APredictionIndicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APredictionIndicator::DestryIndicator()
{
	Destroy();
}

