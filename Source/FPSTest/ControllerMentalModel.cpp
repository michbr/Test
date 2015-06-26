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
		notifyListenersTargetFound(target);
	}
	else {
		if (targetSightings[target] == 0) {
			notifyListenersTargetFound(target);
		}
		targetSightings[target] = targetSightings[target] + 1;
	}
}

void ControllerMentalModel::removeSighting(UPointOfInterest * target) {
	if (targetSightings.count(target) == 0) {
		return;
	}
	else if (targetSightings[target] > 0)  {
		targetSightings[target] = targetSightings[target] - 1;
		if (targetSightings[target] == 0) {
			notifyListenersTargetLost(target);
		}
	}
}

bool ControllerMentalModel::canSee(UPointOfInterest * target) {
	return (targetSightings.count(target) > 0 && targetSightings[target] > 0);
}

void ControllerMentalModel::addUpdateListener(ModelUpdateListener * listener) {
	listeners.push_back(listener);
}

void ControllerMentalModel::notifyListenersTargetFound(UPointOfInterest * target) {
	for (int i = 0; i < listeners.size(); i++) {
		//UE_LOG(LogTemp, Warning, TEXT("MODEL: notify target found"));
		listeners[i]->notifySighting(target);
	}
}

void ControllerMentalModel::notifyListenersTargetLost(UPointOfInterest * target) {
	for (int i = 0; i < listeners.size(); i++) {
		listeners[i]->notifySightingLost(target);
	}
}

