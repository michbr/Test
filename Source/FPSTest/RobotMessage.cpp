// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "RobotMessage.h"

using namespace std;

RobotMessage::RobotMessage(string src, string messageType, UPointOfInterest * tag) {
	source = src;
	type = messageType;
	targetInfo = tag;
}

RobotMessage::RobotMessage(const RobotMessage& a) {
	*this = a;
}


string RobotMessage::getSource() const {
	return source;
}

string RobotMessage::getType() const {
	return type;
}

UPointOfInterest * RobotMessage::getTargetInfo() const {
	return targetInfo;
}

RobotMessage::~RobotMessage() {
}

RobotMessage & RobotMessage::operator=(const RobotMessage & a) {
	source = a.getSource();
	type = a.getType();
	targetInfo = a.getTargetInfo();

	return *this;
}
