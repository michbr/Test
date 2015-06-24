// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RobotAntenna.h"

using namespace std;

URobotAntenna::URobotAntenna() {
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	SetStaticMesh(SphereVisualAsset.Object);
	RelativeLocation = FVector(0.f, 0.f, 0.f);
}


void URobotAntenna::attachMentalModel(ControllerMentalModel * mentalModel) {
	componentController->attachMentalModel(mentalModel);
}

