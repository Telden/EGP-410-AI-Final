#include "VelocityMatching.h"
#include "KinematicUnit.h"
#include "Game.h"
#include "UnitManager.h"

VelocityMatching::VelocityMatching(KinematicUnit* pMover, float radius, int unitIndex)
{
	mpThisUnit = pMover;
	mpFlockmates = UNIT_MANAGER->getUnitList();
	mRadius = radius;
	mUnitIndex = unitIndex;
}

Steering* VelocityMatching::getSteering()
{
	mLinear = 0;
	mAngular = 0;
	Vector2D direction;
	float distance;
	int count = 0;
	for (int i = 1; i < UNIT_MANAGER->getUnitList().size(); i++)
	{


		distance = sqrt(pow(mpThisUnit->getPosition().getX() - UNIT_MANAGER->getKinematicUnit(i)->getPosition().getX(), 2.0f)
			+ pow(mpThisUnit->getPosition().getY() - UNIT_MANAGER->getKinematicUnit(i)->getPosition().getY(), 2.0f));

		if (distance < mRadius)
		{
			// Acceleration tries to get to the target velocity
			mLinear += UNIT_MANAGER->getKinematicUnit(i)->getVelocity() - mpThisUnit->getVelocity();
			//mLinear /= mTimeToTarget;
			
		}

		
		
	}

	
	// Check if the acceleration is too fast
	if (mLinear.getLength() > mpThisUnit->getMaxAcceleration())
	{
		mLinear.normalize();
		mLinear *= mpThisUnit->getMaxAcceleration();
	}


	// Output the steering
	return this;
}

