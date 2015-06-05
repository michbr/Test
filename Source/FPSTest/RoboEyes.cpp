// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RoboEyes.h"

URoboEyes::URoboEyes() {
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	SetStaticMesh(SphereVisualAsset.Object);
	RelativeLocation = FVector(0.f, 0.f, 0.f);

	ConstructorHelpers::FObjectFinder <UMaterial>Material_Green(TEXT("Material'/Game/AutoDoor/progressBarGreen.progressBarGreen'"));
	ConstructorHelpers::FObjectFinder <UMaterial>Material_Red(TEXT("Material'/Game/AutoDoor/progressBarRed.progressBarRed'"));

	red = Material_Red.Object;
	green = Material_Green.Object;
	isGreen = false;
	seconds = 0;

	//SetMaterial(0, red);

}

// Called every frame
void URoboEyes::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UE_LOG(LogTemp, Warning, TEXT("roboEyesTickexecute"));

	if (canSeePlayer()) {
		componentController->submitMessage("player sighted");
		//SetMaterial(0, green);
	}
	else {
		componentController->submitMessage("player lost");
		//SetMaterial(0, red);
	}
}

bool URoboEyes::canSeePlayer() {
	UWorld * world = GetWorld();
	FVector dir = world->GetFirstPlayerController()->GetCharacter()->GetActorLocation();// GetActorLocation();

	FHitResult hit;
	world->LineTraceSingle(hit, this->RelativeLocation + this->AttachParent->GetAttachmentRootActor()->GetActorLocation(), dir, FCollisionQueryParams(true),
		FCollisionObjectQueryParams(
		ECC_TO_BITFIELD(ECollisionChannel::ECC_Pawn)
		| ECC_TO_BITFIELD(ECollisionChannel::ECC_Visibility)
		| ECC_TO_BITFIELD(ECollisionChannel::ECC_WorldStatic)
		| ECC_TO_BITFIELD(ECollisionChannel::ECC_WorldDynamic)
		| ECC_TO_BITFIELD(ECollisionChannel::ECC_PhysicsBody)));

	return hit.GetActor() == world->GetFirstPlayerController()->GetCharacter();
}


