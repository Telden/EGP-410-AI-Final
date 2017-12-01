#include "Game.h"
#include "BlendedSteering.h"
#include "WallDetection.h"
#include "KinematicUnit.h"

BlendedSteering::BlendedSteering(KinematicUnit* pUnit,  bool* walls)
{
	mpUnit = pUnit;
	mpWallBool = walls;
}

BlendedSteering::~BlendedSteering()
{
	for (int i = 0; i < mpBehaviors.size(); i++)
	{
		delete mpBehaviors[i];
	}
}

void BlendedSteering::addBehaviorAndWeight(BehaviorAndWeight* nBAW)
{
	mpBehaviors.push_back(nBAW);
}

Steering* BlendedSteering::getSteering()
{
//	WallDetection tmpDetection(mpUnit);
//	if (*mpWallBool)
//		printf("True");
//	else
//		printf("false");
//	if (tmpDetection.getDetection() && *mpWallBool)
//	{
//		//printf("Detected wall");
//		mpUnit->setVelocity(mpUnit->getVelocity() * -1);
//		mLinear *= -1;
//		mpUnit->setNewOrientation();
//		return this;
//	}
//	else
//	{
		mLinear = 0;
		mAngular = 0;
		//Steering* pSteering = new Steering();
		for (int i = 0; i < mpBehaviors.size(); i++)
		{
			mLinear += mpBehaviors[i]->mBehavior->getSteering()->getLinear() * mpBehaviors[i]->getWight();
			mAngular += mpBehaviors[i]->mBehavior->getSteering()->getAngular() *  mpBehaviors[i]->getWight();
		}


		checkMaxSpeed(mLinear, mpUnit->getMaxAcceleration());
		mAngular = max(mAngular, MAX_WANDER_ROTATION);

		//checkMaxRotation(mAngular, MAX_WANDER_ROTATION);
		return this;
	//}
	
	
	
}

void BlendedSteering::checkMaxSpeed(Vector2D& linear, float maximum)
{
	if (linear.getX() > maximum )
		linear.setX(maximum);
	if(linear.getX() < (maximum*-1))
		linear.setX(maximum * -1);
	if (linear.getY() > maximum )
		linear.setY(maximum);
	if(linear.getX() < (maximum*-1))
		linear.setY(maximum* -1);
	


}

//void BlendedSteering::checkMaxRotation(float& angular, float maximum)
//{
//	if (angular > maximum)
//		angular = maximum;
//}