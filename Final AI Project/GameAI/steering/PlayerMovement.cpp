#include "PlayerMovement.h"
#include "KinematicUnit.h"
#include "GameMessage.h"
#include "GraphicsSystem.h"
#include "Game.h"
#include "UnitManager.h"
#include <math.h>
#include <vector>
#include "KinematicUnit.h"



//Remove later
#include "Game.h"


/* Constructor */
PlayerMovement::PlayerMovement(KinematicUnit* pMover)
{
	mpMover = pMover;
	
}

Steering* PlayerMovement::getSteering()
{
   bool test = mCol.circleOnBox(mpMover->getPosition(), 50);
   std::vector<KinematicUnit*> unitList;
   unitList = UNIT_MANAGER->getUnitList();

   if (test)
      std::cout << "player detecting wall - circ x rect" << std::endl;
	
   for (int i = 0; i < unitList.size(); i++)
   {
	 test = mCol.circleOnCircle(mpMover->getPosition(), spriteWidthandHeight, unitList[i]->getPosition(), spriteWidthandHeight);
   }
   
   if(test)
	   std::cout << "player detecting enemy - circ x circ" << std::endl;
   
	//mLinear = 0;
	mAngular = previousAngle;
	//std::cout << mCurrentAcceleration << "\n";
	
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
			printf("Moving right");
			mMoveRight = true;
		}		
		else
			mMoveRight = false;
		break;
	case 'A':
		if (isPressed)
		{
			printf("Moving left");
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
