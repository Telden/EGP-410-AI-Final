#ifndef CARCOMPONENT_H
#define CARCOMPONENT_H

#include "Component.h"

class Unit;
class EnemyStalfos;
class Animation;

class CarComponent : public Component
{
private:
	// the unit this component refers to
	Unit* mpMyUnit;

public:
	CarComponent(Unit* myUnit);
	~CarComponent();

	void update();

	void handleEvent(const Event& theEvent);
};

#endif