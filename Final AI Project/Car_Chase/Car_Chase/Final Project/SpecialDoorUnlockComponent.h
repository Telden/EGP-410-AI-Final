#pragma once

#ifndef SPECIALDOORUNLOCKCOMPONENT_H
#define SPECIALDOORUNLOCKCOMPONENT_H

#include "Component.h"

#include "Timer.h"

class Unit;

class SpecialDoorUnlockComponent : public Component
{
private:
	// the unit this component refers to
	Unit* mpMyUnit;

public:
	SpecialDoorUnlockComponent(Unit* myUnit);
	~SpecialDoorUnlockComponent();

	void handleEvent(const Event& theEvent);

	Unit* getMyUnit() { return mpMyUnit; }
};

#endif