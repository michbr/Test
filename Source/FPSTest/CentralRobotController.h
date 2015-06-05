// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RobotController.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include <string>
#include "CentralRobotController.generated.h"

UCLASS()
class FPSTEST_API ACentralRobotController : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent * sphere;

	UPROPERTY(EditInstanceOnly, Category = Robots)
		TArray<ARobotController *> robots;
	
public:	
	// Sets default values for this actor's properties
	ACentralRobotController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void broadcastMessage(std::string message);
	
	
};
