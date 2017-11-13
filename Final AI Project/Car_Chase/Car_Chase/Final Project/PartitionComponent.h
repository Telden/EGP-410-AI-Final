#pragma once
#ifndef PARTITIONCOMPONENT_H
#define PARTITIONCOMPONENT_H

#include "Component.h"

class Unit;

class PartitionComponent : public Component
{

private:
	int mCurrentQuadrent;
	Unit* mpMyUnit;

public:
	PartitionComponent(Unit* myUnit);
	~PartitionComponent();

	void update();
	void checkCollisionsOnGrid();
	void handleEvent(const Event& theEvent);

};

#endif