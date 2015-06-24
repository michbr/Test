// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RobotController.h"
#include "AbstractRobotComponent.h"

using namespace std;
// Sets default values
ARobotController::ARobotController() {
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cone'"));
	RootComponent = sphere;
	sphere->RelativeLocation = FVector(0.f, 0.f, 0.f);


	sphere->SetStaticMesh(SphereVisualAsset.Object);
	ConstructorHelpers::FObjectFinder <UMaterial>Material_Green(TEXT("Material'/Game/AutoDoor/progressBarGreen.progressBarGreen'"));
	ConstructorHelpers::FObjectFinder <UMaterial>Material_Red(TEXT("Material'/Game/AutoDoor/progressBarRed.progressBarRed'"));

	red = Material_Red.Object;
	green = Material_Green.Object;

	sense = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Senses"));
}

void ARobotController::OnSeePawn(APawn *OtherPawn) {
	UE_LOG(LogTemp, Warning, TEXT("Vision info received"));

}

void ARobotController::PostInitializeComponents() {
	Super::PostInitializeComponents();
	//sense->OnSeePawn.AddDynamic(this, &ARobotController::OnSeePawn);
}

// Called when the game starts or when spawned
void ARobotController::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ARobotController::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );

	while (messageQueue.size() > 0) {

		RobotMessage message = messageQueue.front();
		messageQueue.pop_front();
		UE_LOG(LogTemp, Warning, TEXT("CONTROLLER: processing message - %s, %s, %s"), UTF8_TO_TCHAR(message.getSource().c_str()), UTF8_TO_TCHAR(message.getType().c_str()), *message.getTargetInfo()->getTargetType());

		//UE_LOG(LogTemp, Warning, TEXT("*********  %s  *********"), UTF8_TO_TCHAR(message.getType().c_str()));

		for (int i = 0; i < messageListeners.size(); i++) {
			UE_LOG(LogTemp, Warning, TEXT("Transmitting message from source %s"), UTF8_TO_TCHAR(message.getSource().c_str()));

			if (message.getSource().compare("antenna") != 0) {
				UE_LOG(LogTemp, Warning, TEXT("Transmitting message type %s"), UTF8_TO_TCHAR(message.getType().c_str()));

				messageListeners[i]->onMessage(message);
			}
		}

		if (message.getSource().compare("eyes") == 0
			&& message.getType().compare("player sighted") == 0
			&& message.getTargetInfo()->getTargetType().Compare("player") == 0) {

			mentalModel.addSighting(message.getTargetInfo());
			//UE_LOG(LogTemp, Warning, TEXT("CONTROLLER: set material to green"));

			sphere->SetMaterial(0, green);
			
		}
		else if (message.getSource().compare("eyes") == 0 
			&& message.getType().compare("player lost") == 0 
			&& message.getTargetInfo()->getTargetType().Compare("player") == 0) {
			mentalModel.removeSighting(message.getTargetInfo());
			//UE_LOG(LogTemp, Warning, TEXT("CONTROLLER: set material to red"));

			sphere->SetMaterial(0, red);
		}
	}

	/*if (mentalModel.canSee("player")) {
		sphere->SetMaterial(0, green);
	}
	else {
		sphere->SetMaterial(0, red);
	}*/

}

// Called to bind functionality to input
void ARobotController::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);

}

void ARobotController::submitMessage(RobotMessage message) {
	//UE_LOG(LogTemp, Warning, TEXT("Submitting message with type %s"), UTF8_TO_TCHAR(message.getType().c_str()));
	//UE_LOG(LogTemp, Warning, TEXT("Submitting message from source %s"), UTF8_TO_TCHAR(message.getSource().c_str()));
	messageQueue.push_back(message);
}

void ARobotController::registerListener(UAbstractRobotComponent * component) {
	messageListeners.push_back(component);
}

void ARobotController::attachMentalModel(ControllerMentalModel * model) {

}