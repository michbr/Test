// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RobotController.h"
#include "RoboEyes3.h"
#include "RobotAntenna3.h"

using namespace std;
// Sets default values
ARobotController::ARobotController() {
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	//eyes = CreateDefaultSubobject<URoboEyes3>(TEXT("eyes"));
	//antenna = CreateDefaultSubobject<URobotAntenna3>(TEXT("antenna"));

	sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cone'"));
	RootComponent = sphere;
	sphere->RelativeLocation = FVector(0.f, 0.f, 0.f);


	sphere->SetStaticMesh(SphereVisualAsset.Object);

	//eyes->AttachParent = RootComponent;
	//eyes->AttachSocketName = "RoboEyes";
	//eyes->RelativeLocation = FVector(0.f, 0.f, 90.f);
	//eyes->setController(this);

	//antenna->AttachParent = RootComponent;
	//antenna->AttachSocketName = "RobotAntenna";
	//antenna->RelativeLocation = FVector(30.f, 30.f, 91.f);
	//antenna->SetRelativeScale3D(FVector(.1f, .1f, 1.f));
	//antenna->setController(this);

	ConstructorHelpers::FObjectFinder <UMaterial>Material_Green(TEXT("Material'/Game/AutoDoor/progressBarGreen.progressBarGreen'"));
	ConstructorHelpers::FObjectFinder <UMaterial>Material_Red(TEXT("Material'/Game/AutoDoor/progressBarRed.progressBarRed'"));

	red = Material_Red.Object;
	green = Material_Green.Object;
}

// Called when the game starts or when spawned
void ARobotController::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ARobotController::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
	while (messageQueue.size() > 0) {
		string message = messageQueue.front();
		messageQueue.pop_front();
		if (message.compare("player sighted") == 0) {
			sphere->SetMaterial(0, green);
		}
		else if (message.compare("player lost") == 0) {
			sphere->SetMaterial(0, red);
		}
	}

}

// Called to bind functionality to input
void ARobotController::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);

}

void ARobotController::submitMessage(string message) {
	messageQueue.push_back(message);
}

