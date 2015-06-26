// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ModelUpdateListener.h"
#include "AbstractMentalModel.h"
#include <unordered_map>
#include <vector>

/**
 * 
 */
class FPSTEST_API ControllerMentalModel {
	std::unordered_map<UPointOfInterest *, int> targetSightings;
	std::vector <ModelUpdateListener *> listeners;

	void notifyListenersTargetFound(UPointOfInterest * target);
	void notifyListenersTargetLost(UPointOfInterest * target);
public:
	ControllerMentalModel();

	void addUpdateListener(ModelUpdateListener * listener);
	void addSighting(UPointOfInterest * targetID);
	void removeSighting(UPointOfInterest * targetID);
	bool canSee(UPointOfInterest * targetID);

	~ControllerMentalModel();
};
