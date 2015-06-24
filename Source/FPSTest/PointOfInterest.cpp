// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "PointOfInterest.h"


// Sets default values for this component's properties
UPointOfInterest::UPointOfInterest() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
	/*targetInformation = ConstructObject<UTargetInfo2>(UTargetInfo2::StaticClass());
	targetInformation->setTargetID("player");
	targetInformation->setTarget(GetAttachmentRootActor());*/
	target = GetAttachmentRootActor();
	//targetInformation->setTarget()
	//ConstructorHelpers::FObjectFinder<UTargetInfo2> SphereVisualAsset(TEXT("/Script/FPSTest.TargetInfo2"));
	/*if (SphereVisualAsset.Succeeded()) {
		targetInformation = SphereVisualAsset.Object;
		targetInformation->setTargetID("player");
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("CLASS NOT FOUND"));

	}*/

	//SetStaticMesh(SphereVisualAsset.Object);
	//

	// ...
}


// Called when the game starts
void UPointOfInterest::InitializeComponent() {
	Super::InitializeComponent();
	
}


// Called every frame
void UPointOfInterest::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) {
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

}

AActor * UPointOfInterest::getTarget() {
	return target;
}

FString UPointOfInterest::getTargetType() {
	return targetType;
}


