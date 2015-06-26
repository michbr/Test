// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RobotController.h"
#include "RobotMessage.h"
#include <string>
#include "AbstractRobotComponent.generated.h"

/**
*
*/
UCLASS(abstract)
class FPSTEST_API UAbstractRobotComponent : public UStaticMeshComponent {
	GENERATED_BODY()
protected:
	ARobotController * componentController;
public:
	//UAbstractRobotComponent3(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	UAbstractRobotComponent();
	virtual void InitializeComponent() override;
	virtual void onMessage(RobotMessage message);
};
