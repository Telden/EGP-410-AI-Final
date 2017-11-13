#pragma once

#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "Component.h"

class Unit;

class RenderComponent : public Component
{
private:
	// the unit this component refers to
	Unit* mpMyUnit;

public:
	RenderComponent(Unit* myUnit);
	~RenderComponent();

	void render();

	Unit* getMyUnit() { return mpMyUnit; }

	void handleEvent(const Event& theEvent);
};

#endif