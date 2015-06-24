// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Event.h"
#include "RobotMentalModel.h"
#include "RobotMessage.h"

#include <list>
#include <vector>

#include "GameFramework/Pawn.h"
#include "Runtime/AIModule/Classes/Perception/PawnSensingComponent.h"

#include "RobotController.generated.h"

class UAbstractRobotComponent;

UCLASS()
class FPSTEST_API ARobotController : public APawn {
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent * sphere;

	std::list<RobotMessage> messageQueue;

	std::vector<UAbstractRobotComponent *> messageListeners;
	UPawnSensingComponent * sense;

	UMaterial * red;
	UMaterial * green;

	ControllerMentalModel mentalModel;

public:
	// Sets default values for this pawn's properties
	ARobotController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void PostInitializeComponents() override;

	void submitMessage(RobotMessage message);

	void registerListener(UAbstractRobotComponent * component);

	void attachMentalModel(ControllerMentalModel * model);

	UFUNCTION()
		void OnSeePawn(APawn *OtherPawn);

private:
	ControllerMentalModel * getMentalModel();

	void broadcastEvent(Event e);
};
