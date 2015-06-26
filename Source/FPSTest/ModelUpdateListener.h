// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PointOfInterest.h"

/**
 * 
 */
class FPSTEST_API ModelUpdateListener {
public:
	ModelUpdateListener();
	~ModelUpdateListener();
	virtual void notifySighting(UPointOfInterest * target) = 0;
	virtual void notifySightingLost(UPointOfInterest * target) = 0;
};
