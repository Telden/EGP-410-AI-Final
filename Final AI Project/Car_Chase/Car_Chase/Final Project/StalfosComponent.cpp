#include "StalfosComponent.h"
#include "EnemyStalfos.h"
#include "Unit.h"

StalfosComponent::StalfosComponent(Unit* myStalfos, int waitTime)
{
	mpMyUnit = myStalfos;

	mMaxWaitCounter = waitTime;
	
	srand((unsigned int) time(NULL));

	// assign an initial direction to move in
	int seed = rand() % 4;
	switch (seed)
	{
		case 0:
		{
			mDirectionFacing = "up";
		}
		case 1:
		{
			mDirectionFacing = "down";
		}
		case 2:
		{
			mDirectionFacing = "left";
		}
		case 3:
		{
			mDirectionFacing = "right";
		}
	}
}

StalfosComponent::~StalfosComponent()
{

}

void StalfosComponent::render()
{

}

void StalfosComponent::update()
{
	if (!mWaiting)
	{
		if (mCounter == mMaxCounter)
		{
			// when it's time, pick a new direction to move in
			int seed = rand() % 4;
			switch (seed)
			{
				case 0:
				{
					mDirectionFacing = "up";
					break;
				}
				case 1:
				{
					mDirectionFacing = "down";
					break;
				}
				case 2:
				{
					mDirectionFacing = "left";
					break;
				}
				case 3:
				{
					mDirectionFacing = "right";
					break;
				}
			}
			mWaiting = true;
			mCounter = 0;
		}
		else
		{
			// based on the current direction, move that way
			// if a collision with a wall or door will occur while moving that way, don't!
			if (mDirectionFacing == "up")
			{
				if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 0, -2) && !Game::getInstance()->getLevelManager()->checkCollisionWithDoors(mpMyUnit, 0, -2))
				{
					mpMyUnit->setLocY(mpMyUnit->getLocY() - 2);
				}
			}
			else if (mDirectionFacing == "down")
			{
				if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 0, 2) && !Game::getInstance()->getLevelManager()->checkCollisionWithDoors(mpMyUnit, 0, 2))
				{
					mpMyUnit->setLocY(mpMyUnit->getLocY() + 2);
				}
			}
			else if (mDirectionFacing == "left")
			{
				if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, -2, 0) && !Game::getInstance()->getLevelManager()->checkCollisionWithDoors(mpMyUnit, -2, 0))
				{
					mpMyUnit->setLocX(mpMyUnit->getLocX() - 2);
				}
			}
			else if (mDirectionFacing == "right")
			{
				if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 2, 0) && !Game::getInstance()->getLevelManager()->checkCollisionWithDoors(mpMyUnit, 2, 0))
				{
					mpMyUnit->setLocX(mpMyUnit->getLocX() + 2);
				}
			}

			mCounter++;
		}
	}
	else
	{
		// if applicable, wait and then move again (this is used with Gels, not Stalfos)
		if (mWaitCounter < mMaxWaitCounter)
		{
			mWaitCounter++;
		}
		else
		{
			mWaitCounter = 0;
			mWaiting = false;
		}
	}
}

void StalfosComponent::handleEvent(const Event& theEvent)
{

}