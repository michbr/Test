// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "CentralRobotController.h"

using namespace std;

// Sets default values
ACentralRobotController::ACentralRobotController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));


	sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cone'"));
	//UE_LOG(LogTemp, Warning, TEXT("after"));
	RootComponent = sphere;
	sphere->RelativeLocation = FVector(0.f, 0.f, 0.f);


	sphere->SetStaticMesh(SphereVisualAsset.Object);

}

// Called when the game starts or when spawned
void ACentralRobotController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACentralRobotController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACentralRobotController::broadcastMessage(string message) {
	for (int i = 0; i < robots.Num(); i++) {
		robots[i]->submitMessage(message);
	}
}

