// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RobotAntenna.h"


URobotAntenna::URobotAntenna() {
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	SetStaticMesh(SphereVisualAsset.Object);
	RelativeLocation = FVector(0.f, 0.f, 0.f);


}

