#include "Game.h"
#include "UnitManager.h"
#include "CreatePickupMessage.h"

CreatePickupMessage::CreatePickupMessage(Vector2D mousePos, int diameter, int mode, int level) :GameMessage(CREATE_PICKUP_MESSAGE)
{
	mMousePos = mousePos;
	mDiameter = diameter;
	mMode = mode;
	mLevel = level;
}

void CreatePickupMessage::process()
{
	UNIT_MANAGER->createPickupUnit(mMousePos, mDiameter, mMode, mLevel);
}