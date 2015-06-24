// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbstractRobotComponent.h"
#include "ControllerMentalModel.h"
#include "RobotAntenna.generated.h"

/**
*
*/
UCLASS(ClassGroup = RobotComponents, meta = (BlueprintSpawnableComponent))
class FPSTEST_API URobotAntenna : public UAbstractRobotComponent {
	GENERATED_BODY()

public:
	URobotAntenna();

	void attachMentalModel(ControllerMentalModel * mentalModel);
};
