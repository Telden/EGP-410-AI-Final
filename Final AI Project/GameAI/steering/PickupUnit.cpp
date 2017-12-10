#include "PickupUnit.h"
#include "Game.h"
#include "GraphicsSystem.h"

// mode is 0 for regular score, 1 for a powerup
PickupUnit::PickupUnit(Vector2D position, int radius, int mode)
   :Kinematic(position, 0, 0, 0) // initializing velocity, orientation, and rotational velocity as 0
{
   mRadius = radius;
   mMode = mode;
}

PickupUnit::~PickupUnit()
{

}

void PickupUnit::draw()
{
   gpGame->getGraphicsSystem()->drawCircle(mPosition, mRadius / 2);
}

int PickupUnit::getMode()
{
   // 0 for regular score, 1 for a powerup
   return mMode;
}