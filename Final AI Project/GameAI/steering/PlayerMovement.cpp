#include "PlayerMovement.h"
#include "KinematicUnit.h"
#include "GameMessage.h"
#include "GraphicsSystem.h"
#include "Game.h"
#include "UnitManager.h"
#include <math.h>
#include <vector>
#include "KinematicUnit.h"
#include "Graph.h"
#include "Connection.h"
#include "Player.h"

#include "GameMessageManager.h"
#include "GameMessage.h"
#include "SwitchMapMessage.h"
#include "EndGameMessage.h"

//Remove later
#include "Game.h"


/* Constructor */
PlayerMovement::PlayerMovement(KinematicUnit* pMover)
{
	mpMover = pMover;
	
}

Steering* PlayerMovement::getSteering()
{
   // do our collision tests
   bool test = mCol.circleOnWall(mpMover->getPosition(), 20);
   bool doorTest = mCol.circleOnDoor(mpMover->getPosition(), 50);
   bool waterTest = mCol.circleOnWater(mpMover->getPosition(), 20);

   // check if we've collided with a door
   if (doorTest)
   {
	   std::vector<Connection*> connections = GRAPH->getConnections(UNIT_MANAGER->getPlayerUnit()->getLastNode()->getId()); 
	   for (unsigned int i = 0; i < connections.size(); i++)
	   {
		   if (connections[i]->getFromNode()->getLevel() != connections[i]->getToNode()->getLevel())
		   {
			   mpMover->setPosition(connections[i]->getToNode()->getPosision());
			   GameMessage* pMessage = new SwitchMapMessage();
			   MESSAGE_MANAGER->addMessage(pMessage, 0);
		   }
	   }
   }
	  
   std::vector<KinematicUnit*> unitList;
   unitList = UNIT_MANAGER->getUnitList();

   // check if we've collided with a wall
   if (test && mWallCooldown==0)
   {
      // we need a cooldown here or else the player will get stuck
	   //std::cout << "player detecting wall - circ x rect" << std::endl;
		mLinear = (mpMover->getOrientationAsVector() * mCurrentAcceleration)  *-1;
		mCurrentAcceleration *= -0.5;
		mWallCooldown = 5;
	   return this;
   }
   else
   {
	   if (mWallCooldown > 0)
		   mWallCooldown--;
   }
   
   // check collision with each water
   if (waterTest)
   {
      std::cout << "--- GAME OVER ---" << std::endl;
      GameMessage* pMessage = new EndGameMessage();
      MESSAGE_MANAGER->addMessage(pMessage, 0);
   }

   bool enemyTest = false;
   // check collision with each enemy
   for (unsigned int i = 0; i < unitList.size(); i++)
   {
	   if (unitList[i]->mCurrentLevel == gpGame->getCurrentLevel())
	   {
		   if (mCol.circleOnCircle(mpMover->getPosition(), spriteWidthandHeight, unitList[i]->getPosition(), spriteWidthandHeight))
            enemyTest = true;
	   }
   }

   // actually test to see if an enemy was detected
   if (enemyTest)
   {
      std::cout << "--- GAME OVER ---" << std::endl;
      GameMessage* pMessage = new EndGameMessage();
      MESSAGE_MANAGER->addMessage(pMessage, 0);
   }
   
   // the actual movement
	mAngular = previousAngle;
	if (mMoveBackwards || mMoveForwards || mMoveRight || mMoveLeft)
	{
		/* When move up key is pressed */
		if (mMoveForwards)
		{
			//std::cout << "Moving forwards\n";
			mCurrentAcceleration -= mAccelerationIncrease;
			//mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity() * -1;
			if (mCurrentAcceleration > (mpMover->getMaxVelocity() *-1))
				mLinear = mpMover->getOrientationAsVector() * mCurrentAcceleration;
			else
			{
				mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity() * -1;
				mCurrentAcceleration = mpMover->getMaxVelocity() * -1;
			}
				
		}
		/* When move down key is pressed */
		else if (mMoveBackwards)
		{
			//std::cout << "Moving backwards\n";
			mCurrentAcceleration += mAccelerationIncrease;
			//mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity();
			if (mCurrentAcceleration < mpMover->getMaxVelocity())
				mLinear = mpMover->getOrientationAsVector() * mCurrentAcceleration;
			else
			{
				mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity();
				mCurrentAcceleration = mpMover->getMaxVelocity();
			}
				
		}
		/* When move right key is pressed */
		if (mMoveRight)
		{
			
			//std::cout << "Moving Right\n";
			mAngular = previousAngle = mpMover->getOrientation() - .1;

			if ((mCurrentAcceleration > 0 || mCurrentAcceleration < 0) && !mMoveForwards || !mMoveForwards)
			{
				
				mLinear = deceleratePlayer();
			}
				
			

		}
		/* When move left key is pressed */
		else if (mMoveLeft)
		{
			//std::cout << "Moving left\n";
			mAngular = previousAngle = mpMover->getOrientation() + .1;
			if ((mCurrentAcceleration > 0 || mCurrentAcceleration < 0) && !mMoveForwards || !mMoveForwards)
			{

				mLinear = deceleratePlayer();
			}

		}
	}
	else
	{
		
		mLinear = deceleratePlayer();
	}
	


	return this;
}


Vector2D PlayerMovement::deceleratePlayer()
{
	if (mCurrentAcceleration < 0)
	{
		mCurrentAcceleration += mDeceleration;
		if (mCurrentAcceleration > 0)
			mCurrentAcceleration = 0;
	}

	else if (mCurrentAcceleration > 0)
	{
		mCurrentAcceleration -= mDeceleration;
		if (mCurrentAcceleration < 0)
			mCurrentAcceleration = 0;
	}

	return mpMover->getOrientationAsVector() * mCurrentAcceleration;
}




void PlayerMovement::recieveMessage(char input, bool isPressed)
{
	switch (input)
	{
	case 'W':
		if (isPressed)
			mMoveForwards = true;
		else
			mMoveForwards = false;
		break;
	case 'S':
		if (isPressed)
			mMoveBackwards = true;
		else
			mMoveBackwards = false;
		break;
	case 'D':
		if (isPressed)
		{
			//printf("Moving right");
			mMoveRight = true;
		}		
		else
			mMoveRight = false;
		break;
	case 'A':
		if (isPressed)
		{
			//printf("Moving left");
			mMoveLeft = true;
		}
			
		
		else
			mMoveLeft = false;
		break;
	default:
		std::cout << "Invalid input in player movement switch\n";

	}
/*
	void drawForwardLine()
	{

	}*/



}
