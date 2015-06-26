// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PointOfInterest.h"
#include <string>

/**
 * 
 */
class FPSTEST_API EventMessage {

	std::string type;
	UPointOfInterest * targetInfo;

public:
	EventMessage();
	EventMessage(std::string messageType, UPointOfInterest * target);
	~EventMessage();

	std::string getType();
	void setType(std::string messageType);
	UPointOfInterest * getTargetInfo() const;
};
