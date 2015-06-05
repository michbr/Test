// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "AbstractRobotComponent.h"

UAbstractRobotComponent::UAbstractRobotComponent() : UStaticMeshComponent(FObjectInitializer::Get()) {

}

void UAbstractRobotComponent::InitializeComponent() {
	Super::InitializeComponent();
	componentController = ((ARobotController *)AttachParent->GetAttachmentRootActor());
}