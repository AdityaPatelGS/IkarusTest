// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird.h"
#include "Camera/CameraComponent.h"

// Sets default values
ABird::ABird()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	
	BirdMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BirdMesh"));
	SetRootComponent(BirdMesh);
	BirdMesh->SetupAttachment(RootComponent);
	BirdMesh->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(DestroyTimer, this, &ABird::DestroyBird, 3.f);
	
}



void ABird::DestroyBird()
{

	Destroy();
}

void ABird::BirdDeathCountDown()
{

	GetWorldTimerManager().SetTimer(DestroyTimer,this,&ABird::DestroyBird,DestroyDelay);
}


