// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PointOfInterest.h"
#include <string>

/**
 * 
 */
class FPSTEST_API AbstractMentalModel
{
public:
	virtual void addSighting(UPointOfInterest * targetID) = 0;
	virtual void removeSighting(UPointOfInterest * targetID) = 0;
	virtual bool canSee(UPointOfInterest * targetID) = 0;
	AbstractMentalModel();
	~AbstractMentalModel();
};
