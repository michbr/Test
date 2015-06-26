// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSTest.h"
#include "EventMessage.h"

using namespace std;

EventMessage::EventMessage(string messageType, UPointOfInterest * target) {
	type = messageType;
	targetInfo = target;
}

EventMessage::~EventMessage() {
}

string EventMessage::getType() {
	return type;
}

void EventMessage::setType(string messageType) {
	type = messageType;
}


UPointOfInterest * EventMessage::getTargetInfo() const {
	return targetInfo;
}

