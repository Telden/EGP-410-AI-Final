#pragma once

#ifndef PICKUPCOMPONENT_H
#define PICKUPCOMPONENT_H

#include "EventSystem.h"
#include "Component.h"

class Unit;

class PickupComponent : public Component
{
	private :
		Unit* mpMyUnit;
		std::string mTagID;

	public :
		PickupComponent(std::string tagID, Unit* myUnit);
		~PickupComponent();

		void update();
		void handleEvent(const Event& theEvent);
};

#endif