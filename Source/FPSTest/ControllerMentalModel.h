// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbstractMentalModel.h"
#include <unordered_map>

/**
 * 
 */
class FPSTEST_API ControllerMentalModel : AbstractMentalModel {
	std::unordered_map<UPointOfInterest *, int> targetSightings;
public:
	void addSighting(UPointOfInterest * targetID) override;
	void removeSighting(UPointOfInterest * targetID) override;
	bool canSee(UPointOfInterest * targetID) override;
	ControllerMentalModel();

	~ControllerMentalModel();
};
