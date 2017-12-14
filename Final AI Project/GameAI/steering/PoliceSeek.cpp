#include "PoliceSeek.h"
#include "Game.h"
#include "KinematicUnit.h"
#include "UnitManager.h"
#include "Player.h"
#include "Node.h"
#include "AStarPathfinder.h"

PoliceSeek::PoliceSeek(KinematicUnit* mover, KinematicUnit* target, int radius)
{
	mpMover = mover;
	mpTarget = target;
	mRadius = radius;
}

Steering* PoliceSeek::getSteering()
{
	if (mpTarget->mCurrentLevel == mpMover->mCurrentLevel)
	{
		if (mpNodeStack.empty() && mpTarget->getLastNode()->getPosision() != NULL)
		{
			mpAStar = new AStarPathfinder();
			mpNodeStack = mpAStar->findPath(mpMover->getLastNode(), mpTarget->getLastNode());
			//printf("Be happy");
		}
		else
		{
			float distance;
			distance = sqrt(pow((mpNodeStack.top()->getPosision().getX() - mpMover->getPosition().getX()), 2) +
				pow((mpNodeStack.top()->getPosision().getY() - mpMover->getPosition().getY()), 2));
			mLinear = mpNodeStack.top()->getPosision() - mpMover->getPosition();
			mLinear.normalize();
			mLinear *= mpMover->getMaxVelocity();
			mAngular = 0;
			if (mpNodeStack.top()->getLevel() != mpMover->mCurrentLevel)
				mpMover->mCurrentLevel = mpNodeStack.top()->getLevel();
			if (distance < mRadius)
				mpNodeStack.pop();
		
		}
		
	
		
	}
	return this;

}