// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbstractRobotComponent.h"
#include "RoboEyes.generated.h"

/**
*
*/
UCLASS(ClassGroup = RobotComponents, meta = (BlueprintSpawnableComponent))
//UCLASS()
class FPSTEST_API URoboEyes : public UAbstractRobotComponent {
	GENERATED_BODY()

	bool isGreen;

	float seconds;

	UMaterial * red;
	UMaterial * green;
public:
	URoboEyes();

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool canSeePlayer();

};
