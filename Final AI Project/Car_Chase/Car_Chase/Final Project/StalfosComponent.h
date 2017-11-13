#pragma once

#ifndef STALFOSCOMPONENT_H
#define STALFOSCOMPONENT_H

#include "Component.h"
#include "Animation.h"
#include <time.h>

class Unit;
class EnemyStalfos;
class Animation;

class StalfosComponent : public Component
{
private:
	// the unit this component refers to
	Unit* mpMyUnit;

	// the direction the Stalfos is facing
	std::string mDirectionFacing;

	int mCounter = 0;
	int mMaxCounter = 32;

	int mWaitCounter = 0, mMaxWaitCounter;
	bool mWaiting = false;

public:
	StalfosComponent(Unit* myStalfos, int waitTime);
	~StalfosComponent();

	void render();
	void update();

	void handleEvent(const Event& theEvent);
};

#endif