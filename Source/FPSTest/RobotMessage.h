// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PointOfInterest.h"
#include <string>
/**
 * 
 */
class FPSTEST_API RobotMessage {
private:
	std::string source;
	std::string type;
	UPointOfInterest * targetInfo;
public:
	RobotMessage();
	RobotMessage(std::string src, std::string messageType, UPointOfInterest * tag);
	RobotMessage(const RobotMessage& a);
	std::string getSource() const;
	std::string getType() const;
	UPointOfInterest * getTargetInfo() const;
	~RobotMessage();
	RobotMessage & operator=(const RobotMessage & a);
};
