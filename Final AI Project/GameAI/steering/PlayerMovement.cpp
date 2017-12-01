#include "PlayerMovement.h"
#include "KinematicUnit.h"
#include "GameMessage.h"

//Remove later
#include "Game.h"


/* Constructor */
PlayerMovement::PlayerMovement(KinematicUnit* pMover)
{
	mpMover = pMover;
}

Steering* PlayerMovement::getSteering()
{
	//mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity();
	//mAngular = mpMover->getOrientation() + (genRandomBinomial() * 0.5);
	//return this;

	////mAngular = 0;
	////mLinear = 0;

	//mLinear = mpMover->getOrientationAsVector();
	/* When move up key is pressed */
	if (mMoveForwards)
	{
		//mLinear.normalize();
		mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity() * -1;
	}
	/* When move down key is pressed */
	else if (mMoveBackwards)
	{
		//mLinear.normalize();
		mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity();
	}
	/* When move right key is pressed */
	if (mMoveRight)
	{
		mAngular = mpMover->getOrientation() + (genRandomBinomial() * 0.5);
	}
	/* When move left key is pressed */
	else if (mMoveLeft)
	{
		
		mAngular = mpMover->getOrientation() + (genRandomBinomial() * 0.5);
	}

	return this;
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
}
