#pragma once
#ifndef DROPCOMPONENT_H
#define DROPCOMPONENT_H

#include "Component.h"


class Unit;

class DropComponent : public Component
{
private:
	Unit* mpMyUnit;

public:

	DropComponent(Unit* myUnit);
	~DropComponent();

	void update();
	void handleEvent(const Event& theEvent);
};



#endif
