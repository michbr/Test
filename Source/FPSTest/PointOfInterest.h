// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PointOfInterest.generated.h"


UCLASS( ClassGroup=(AI), meta=(BlueprintSpawnableComponent) )
class FPSTEST_API UPointOfInterest : public USceneComponent {
	GENERATED_BODY()

	AActor * target;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
		FString targetType;

	// Sets default values for this component's properties
	UPointOfInterest();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	//	UTargetInfo2 * targetInformation;

	// Called when the game starts
	virtual void InitializeComponent() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
		
	//UTargetInfo2 * getTargetInfo();
	AActor * getTarget();
	FString getTargetType();

};
