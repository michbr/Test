// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbstractMentalModel.h"
#include "ControllerMentalModel.h"
#include <string>
#include <unordered_map>


/**
 * 
 */
class FPSTEST_API RobotMentalModel : public AbstractMentalModel {
private:
	ControllerMentalModel * zoneController;
	bool hasZoneController;

	std::unordered_map<UPointOfInterest *, bool> targetSightings;
public:
	void addSighting(UPointOfInterest * targetID) override;
	void removeSighting(UPointOfInterest * targetID) override;
	bool canSee(UPointOfInterest * targetID) override;
	void setZoneController(ControllerMentalModel * controller);
	RobotMentalModel();
	~RobotMentalModel();
};
