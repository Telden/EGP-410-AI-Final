#pragma once

#ifndef PEAHATCOMPONENT_H
#define PEAHATCOMPONENT_H

#include "Component.h"
#include "Animation.h"
#include <time.h>

class Unit;
class EnemyStalfos;
class Animation;

class PeahatComponent : public Component
{
private:
	// the unit this component refers to
	Unit* mpMyUnit;

	// the direction the Stalfos is facing
	std::string mDirectionFacing;

	bool mMoveHorizontal;

public:
	PeahatComponent(Unit* myStalfos, bool moveHorizontal);
	~PeahatComponent();

	void update();

	void handleEvent(const Event& theEvent);
};

#endif