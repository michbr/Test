// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RoboEyes.generated.h"

UCLASS()
class FPSTEST_API ARoboEyes : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class UStaticMeshComponent* cone;

		bool isGreen;

		float seconds;

		UMaterial * red;
		UMaterial * green;

	
public:	
	// Sets default values for this actor's properties
	ARoboEyes();

	bool canSeePlayer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
