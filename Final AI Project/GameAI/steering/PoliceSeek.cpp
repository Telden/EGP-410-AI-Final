#include "PoliceSeek.h"
#include "Game.h"
#include "KinematicUnit.h"
#include "UnitManager.h"
#include "Player.h"
#include "Node.h"
#include "AStarPathfinder.h"
#include "StateMachine.h"

PoliceSeek::PoliceSeek(KinematicUnit* mover, KinematicUnit* target, int radius, StateMachine* stateMachine, Steering* wander)
{
	mpMover = mover;
	mpTarget = target;
	mRadius = radius;
   mpStateMachine = stateMachine;
   mpWander = wander;
}

Steering* PoliceSeek::getSteering()
{
	if (UNIT_MANAGER->getPlayerUnit()->mCurrentLevel == mpMover->mCurrentLevel)
	{
		if (mpNodeStack.empty() && UNIT_MANAGER->getPlayerUnit()->getLastNode()->getPosision() != NULL)
		{
			mpNodeStack = mAStar.findPath(mpMover->getLastNode(), UNIT_MANAGER->getPlayerUnit()->getLastNode());
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

         if (mpNodeStack.empty())
         {
            gpGame->setPlayerHasPickup(false);
            mpStateMachine->changeCurrentState(mpWander);
         }
		
		}
	}
	return this;

}