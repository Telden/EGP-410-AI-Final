#include "PlayerMovement.h"
#include "KinematicUnit.h"
#include "GameMessage.h"
#include "GraphicsSystem.h"
#include <math.h>



//Remove later
#include "Game.h"


/* Constructor */
PlayerMovement::PlayerMovement(KinematicUnit* pMover)
{
	mpMover = pMover;
}

Steering* PlayerMovement::getSteering()
{
	
	mLinear = 0;
	mAngular = previousAngle;
	
	//std::cout << mpMover->getOrientation() << "\n";


	if (mMoveForwards)
	{
		std::cout << "Moving forwards\n";
		
		mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity() * -1;

	}
	/* When move down key is pressed */
	else if (mMoveBackwards)
	{
		std::cout << "Moving backwards\n";
		
		mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity();
	}
	/* When move right key is pressed */
	if (mMoveRight)
	{
		std::cout << "Moving Right\n";
		mAngular = previousAngle = mpMover->getOrientation() - .1; 
		
	}
	/* When move left key is pressed */
	else if (mMoveLeft)
	{
		std::cout << "Moving left\n";
		mAngular = previousAngle = mpMover->getOrientation() + .1;
		

	}

	return this;
}

Vector2D PlayerMovement::calculateOrientationAsVector()
{
	Vector2D rotationVector;

	return rotationVector;
	
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
