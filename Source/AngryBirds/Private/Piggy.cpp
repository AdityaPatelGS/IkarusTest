// Fill out your copyright notice in the Description page of Project Settings.


#include "Piggy.h"
#include "Components/SphereComponent.h"
#include "Bird.h"

// Sets default values
APiggy::APiggy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PiggyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PiggyMesh"));
	SetRootComponent(PiggyMesh);

	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));
	AreaSphere->SetupAttachment(PiggyMesh);
	AreaSphere->InitSphereRadius(65.0f);

	PiggyMesh->SetSimulatePhysics(true);

	AreaSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	//AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &APiggy::OnSphereOverlap);

}

// Called when the game starts or when spawned
void APiggy::BeginPlay()
{
	Super::BeginPlay();
	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &APiggy::OnSphereOverlap);
	
}

void APiggy::DestroyPiggy()
{

}

void APiggy::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("Piggy Overlapped"));
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("OTher Actor Not NULL"));
		
		DestroyPiggy();

		ABird* Bird = Cast<ABird>(OtherActor);
		if (Bird)
		{
			UE_LOG(LogTemp, Warning, TEXT("Calling Destroy"));

			Bird->BirdDeathCountDown();
		}
	}
}

