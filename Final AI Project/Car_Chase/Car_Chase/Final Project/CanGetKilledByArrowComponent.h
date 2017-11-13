#pragma once

#ifndef CANGETKILLEDBYARROWCOMPONENT_H
#define CANGETKILLEDBYARROWCOMPONENT_H

#include "Component.h"
#include "Animation.h"
#include <time.h>

class Unit;
class EnemyStalfos;
class Animation;

class CanGetKilledByArrowComponent : public Component
{
private:
	// the unit this component refers to
	Unit* mpMyUnit;

	// the direction Link is facing
	std::string mDirectionFacing;

	int mCounter = 0;
	int mMaxCounter = 32;

public:
	CanGetKilledByArrowComponent(Unit* myUnit);
	~CanGetKilledByArrowComponent();

	void render();
	void update();

	void handleEvent(const Event& theEvent);
};

#endif