// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include <list>
#include "RobotController.generated.h"

class URoboEyes3;
class URobotAntenna3;

UCLASS()
class FPSTEST_API ARobotController : public APawn {
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent * sphere;

	//UPROPERTY(VisibleAnywhere, Category = RoboComponents)
	//	URoboEyes3 * eyes;

	//UPROPERTY(VisibleAnywhere, Category = RoboComponents)
	//	URobotAntenna3 * antenna;

	std::list<std::string> messageQueue;

	UMaterial * red;
	UMaterial * green;

public:
	// Sets default values for this pawn's propertiesx
	ARobotController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void submitMessage(std::string message);
};
