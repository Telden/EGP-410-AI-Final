#include "PickupUnit.h"
#include "Game.h"
#include "GraphicsSystem.h"
#include "UnitManager.h"
#include "Player.h"

#include "GameMessageManager.h"
#include "GameMessage.h"
#include "PlaySoundMessage.h"
#include "AddToScoreMessage.h"

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


void PickupUnit::update()
{
   GameMessage* pMessage;

	if (mActive)
	{
		float distance;
		KinematicUnit*  playerObj = UNIT_MANAGER->getPlayerUnit();
		distance = sqrt(pow((playerObj->getPosition().getX() - this->getKinematicPosition().getX()), 2) +
			pow((playerObj->getPosition().getY() - this->getKinematicPosition().getY()), 2));

		if (distance < mRadius)
		{
			//pickup the unit
         
			mActive = false;
         pMessage = new PlaySoundMessage("shine");
         MESSAGE_MANAGER->addMessage(pMessage, 0);

         pMessage = new AddToScoreMessage(100);
         MESSAGE_MANAGER->addMessage(pMessage, 0);
		}

	}
	
}
void PickupUnit::draw()
{
	if(mActive)
		gpGame->getGraphicsSystem()->drawCircle(mPosition, mRadius / 2);
}

int PickupUnit::getMode()
{
   // 0 for regular score, 1 for a powerup
   return mMode;
}