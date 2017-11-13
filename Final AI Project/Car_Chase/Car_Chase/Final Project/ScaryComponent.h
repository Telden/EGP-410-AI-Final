#pragma once

#ifndef SCARYCOMPONENT_H
#define SCARYCOMPONENT_H

#include "Component.h"
#include "Animation.h"
#include <time.h>

class Unit;

class ScaryComponent : public Component
{
private:
	// the unit this component refers to
	Unit* mpMyUnit;

	// the direction Link is facing
	std::string mDirectionFacing;

	int mCounter = 0;
	int mMaxCounter = 32;

public:
	ScaryComponent(Unit* myUnit);
	~ScaryComponent();

	void update();

	void handleEvent(const Event& theEvent);
};

#endif