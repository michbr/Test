// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "ControllerMentalModel.h"

using namespace std;

ControllerMentalModel::ControllerMentalModel() { 
}

ControllerMentalModel::~ControllerMentalModel() {
}

void ControllerMentalModel::addSighting(UPointOfInterest * target) {
	if (targetSightings.count(target) == 0) {
		targetSightings[target] = 1;
	}
	else {
		targetSightings[target] = targetSightings[target] + 1;
	}
}

void ControllerMentalModel::removeSighting(UPointOfInterest * target) {
	if (targetSightings.count(target) == 0) {
		return;
	}
	else if (targetSightings[target] < 0)  {
		targetSightings[target] = targetSightings[target] - 1;
	}
}

bool ControllerMentalModel::canSee(UPointOfInterest * target) {
	return (targetSightings.count(target) > 0 && targetSightings[target] > 0);
}
