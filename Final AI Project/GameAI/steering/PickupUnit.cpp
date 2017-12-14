#include "PickupUnit.h"
#include "Game.h"
#include "GraphicsSystem.h"
#include "UnitManager.h"
#include "Player.h"

#include "GameMessageManager.h"
#include "GameMessage.h"
#include "PlaySoundMessage.h"
#include "AddToScoreMessage.h"

#include "allegro5\allegro_primitives.h"

// mode is 0 for regular score, 1 for a powerup
PickupUnit::PickupUnit(Vector2D position, int radius, int mode, int level)
   :Kinematic(position, 0, 0, 0) // initializing velocity, orientation, and rotational velocity as 0
{
   mRadius = radius;
   mMode = mode;
   mLevel = level;
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
		 switch (mMode)
		 {
		 case 0:
			 pMessage = new AddToScoreMessage(100);
			 MESSAGE_MANAGER->addMessage(pMessage, 0);
          gpGame->setPlayerHasPickup(true);
			 break;
		 case 1:
			 //Powerup player;
          gpGame->setPlayerHasPowerup(true);
			 break;
		 }
			

		}

	}
	else
	{
		if (mRespawnTime > 0)
			mRespawnTime--;
		else
		{
			mActive = true;
			mRespawnTime = mResetRespawnTime;
		}
			
			
	}
	
}
void PickupUnit::draw()
{
	if(mActive && gpGame->getCurrentLevel() == mLevel)
   {
      if (mMode == 0)
      {
         al_draw_filled_circle(mPosition.getX(), mPosition.getY(), mRadius, al_map_rgb(255, 204, 0));
		   //gpGame->getGraphicsSystem()->drawCircle(mPosition, mRadius / 2);
      }
      else
      {
         al_draw_filled_circle(mPosition.getX(), mPosition.getY(), mRadius, al_map_rgb(204, 0, 255));
      }
   }
         
}

int PickupUnit::getMode()
{
   // 0 for regular score, 1 for a powerup
   return mMode;
}