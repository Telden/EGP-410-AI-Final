#include "KeseComponent.h"
#include "Unit.h"

KeseComponent::KeseComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;

	srand((unsigned int)time(NULL));

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

KeseComponent::~KeseComponent()
{

}

void KeseComponent::update()
{
	//Waits for the counter then changes direction
	if (mCounter == mMaxCounter)
	{
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

		mCounter = 0;
	}
	else
	{
		if (mDirectionFacing == "up")
		{
			if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, -1, 1) && !Game::getInstance()->getLevelManager()->checkCollisionWithDoors(mpMyUnit, -1, 1))
			{
				mpMyUnit->setLocX(mpMyUnit->getLocX() - 1);
				mpMyUnit->setLocY(mpMyUnit->getLocY() + 1);
			}
		}
		else if (mDirectionFacing == "down")
		{
			if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 1, -1) && !Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 1, -1))
			{
				mpMyUnit->setLocX(mpMyUnit->getLocX() + 1);
				mpMyUnit->setLocY(mpMyUnit->getLocY() - 1);
			}
		}
		else if (mDirectionFacing == "left")
		{
			if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, -1, -1) && !Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, -1, -1))
			{
				mpMyUnit->setLocX(mpMyUnit->getLocX() - 1);
				mpMyUnit->setLocY(mpMyUnit->getLocY() - 1);
			}
		}
		else if (mDirectionFacing == "right")
		{
			if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 1, 1) && !Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 1, 1))
			{
				mpMyUnit->setLocX(mpMyUnit->getLocX() + 1);
				mpMyUnit->setLocY(mpMyUnit->getLocY() + 1);
			}
		}

		mCounter++;
	}
}

void KeseComponent::handleEvent(const Event& theEvent)
{

}