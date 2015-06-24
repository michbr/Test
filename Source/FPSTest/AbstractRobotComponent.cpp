// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "AbstractRobotComponent.h"

UAbstractRobotComponent::UAbstractRobotComponent() : UStaticMeshComponent(FObjectInitializer::Get()) {
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UAbstractRobotComponent::InitializeComponent() {
	Super::InitializeComponent(	);
	componentController = ((ARobotController *)AttachParent->GetAttachmentRootActor());
	/*TArray<ARobotController *> Comps;
	AttachParent->GetAttachmentRootActor()->GetComponents(Comps);
	if (Comps.Num() > 0) {
		ARobotController* FoundComp = Comps[0];
		
		//do stuff with FoundComp
	}*/
}

void UAbstractRobotComponent::onMessage(RobotMessage message) {
}