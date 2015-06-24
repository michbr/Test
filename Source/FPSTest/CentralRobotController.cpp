// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "CentralRobotController.h"

#include "RobotAntenna.h"

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
	for (int i = 0; i < robots.Num(); i++) {
		TArray<URobotAntenna*> Comps;
		robots[i]->GetComponents(Comps);
		UE_LOG(LogTemp, Warning, TEXT("checking for antenna..."));
		if (Comps.Num() > 0) {
			UE_LOG(LogTemp, Warning, TEXT("...antenna found!!!"));
			URobotAntenna* FoundComp = Comps[0];
			//FoundComp->registerListener(this);
			FoundComp->attachMentalModel(&mentalModel);
			listeners.push_back(FoundComp);

			//do stuff with FoundComp
		}
	}
	
}

// Called every frame
void ACentralRobotController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACentralRobotController::broadcastMessage(RobotMessage message) {
	for (int i = 0; i < listeners.size(); i++) {
		//robots[i]->submitMessage(message);
		UE_LOG(LogTemp, Warning, TEXT("CRC: broadcasting message...."));

		//listeners[i]->onRecieveBroadcast(message);
	}
}

