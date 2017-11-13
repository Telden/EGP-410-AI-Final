#pragma once

#ifndef KESECOMPONENT_H
#define KESECOMPONENT_H

#include "Component.h"
#include "Animation.h"
#include <time.h>

class Unit;
class EnemyStalfos;
class Animation;

class KeseComponent : public Component
{
	private:
		// the unit this component refers to
		Unit* mpMyUnit;

		// the direction the Kese is facing
		std::string mDirectionFacing;

		int mCounter = 0;
		int mMaxCounter = 32;

	public:
		KeseComponent(Unit* myUnit);
		~KeseComponent();

		void update();

		void handleEvent(const Event& theEvent);
};

#endif