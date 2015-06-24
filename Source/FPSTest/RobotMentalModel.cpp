// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RobotMentalModel.h"

using namespace std;

RobotMentalModel::RobotMentalModel() {
	hasZoneController = false;
}

RobotMentalModel::~RobotMentalModel() {
}


void RobotMentalModel::addSighting(UPointOfInterest * targetID) {
	if (hasZoneController) {
		zoneController->addSighting(targetID);
	}
	targetSightings[targetID] = true;
}

void RobotMentalModel::removeSighting(UPointOfInterest * targetID) {
	if (hasZoneController) {
		zoneController->removeSighting(targetID);
	}
	targetSightings[targetID] = false;
}

void RobotMentalModel::setZoneController(ControllerMentalModel * controller) {
	zoneController = controller;
	hasZoneController = true;
}

bool RobotMentalModel::canSee(UPointOfInterest * targetID) {
	if (hasZoneController) {
		return (zoneController->canSee(targetID)) || (targetSightings.count(targetID) && targetSightings[targetID]);
	}
	return (targetSightings.count(targetID) && targetSightings[targetID]);
}
