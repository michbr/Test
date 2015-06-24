// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <list>
#include <unordered_map>

#include "PointOfInterest.h"
#include "AbstractRobotComponent.h"
#include "RoboEyes.generated.h"

/**
*
*/
UCLASS(ClassGroup = RobotComponents, meta = (BlueprintSpawnableComponent))
//UCLASS()
class FPSTEST_API URoboEyes : public UAbstractRobotComponent {
	GENERATED_BODY()

	bool playerSighted;
	std::list<UPointOfInterest *> targets;
	std::unordered_map<UPointOfInterest *, bool> targetMap;

public:
	URoboEyes();

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void InitializeComponent() override;

	bool canSeeTarget(UPointOfInterest * target);

	UFUNCTION()
		void OnSeePawn(APawn *OtherPawn);

};
