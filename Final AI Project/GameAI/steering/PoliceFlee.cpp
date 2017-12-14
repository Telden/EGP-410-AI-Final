#include "PoliceFlee.h"
#include "Game.h"
#include "KinematicUnit.h"
#include "UnitManager.h"
#include "Player.h"
#include "Node.h"
#include "AStarPathfinder.h"
#include "Connection.h"
#include "Graph.h"

PoliceFlee::PoliceFlee(KinematicUnit* mover, KinematicUnit* target, int radius)
{
	mpMover = mover;
	mpTarget = target;
	mRadius = radius;
	mpGraph = GRAPH;
	mpCurrentTarget = NULL;
}

Steering* PoliceFlee::getSteering()
{
	
			if (mpCurrentTarget == NULL)
			{
				float distance;
				std::vector<Connection*> potentialConnections;
				distance = sqrt(pow((mpMover->getLastNode()->getPosision().getX() - mpMover->getPosition().getX()), 2) +
					pow((mpMover->getLastNode()->getPosision().getY() - mpMover->getPosition().getY()), 2));
				if (distance < mRadius)
				{
					int shortestDistance = 99999;
					potentialConnections = mpGraph->getConnections(mpMover->getLastNode()->getId());
					if (potentialConnections.size() != 0)
					{
						for (unsigned int i = 0; i < potentialConnections.size(); i++)
						{
							distance = sqrt(pow((potentialConnections[i]->getToNode()->getPosision().getX() - mpTarget->getPosition().getX()), 2) +
								pow((potentialConnections[i]->getToNode()->getPosision().getY() - mpTarget->getPosition().getY()), 2));
							if (distance < shortestDistance)
							{
								shortestDistance = distance;
								mpCurrentTarget = potentialConnections[i]->getToNode();

							}
						}
					}
				}

				else
				{
					mLinear = mpMover->getLastNode()->getPosision() - mpMover->getPosition();
					mLinear.normalize();
					mLinear *= mpMover->getMaxVelocity();
					mAngular = 0;
				}
			}
			else
			{
				float distance;
				std::vector<Connection*> potentialConnections;
				distance = sqrt(pow((mpCurrentTarget->getPosision().getX() - mpMover->getPosition().getX()), 2) +
					pow((mpCurrentTarget->getPosision().getY() - mpMover->getPosition().getY()), 2));
				if (distance < mRadius)
				{
					int longestDistance = 0;
					potentialConnections = mpGraph->getConnections(mpMover->getLastNode()->getId());
					if (potentialConnections.size() != 0)
					{
						for (unsigned int i = 0; i < potentialConnections.size(); i++)
						{
							distance = sqrt(pow((potentialConnections[i]->getToNode()->getPosision().getX() - mpTarget->getPosition().getX()), 2) +
								pow((potentialConnections[i]->getToNode()->getPosision().getY() - mpTarget->getPosition().getY()), 2));
							if (distance > longestDistance)
							{
								longestDistance = distance;
								mpCurrentTarget = potentialConnections[i]->getToNode();

							}
						}
					}
				}


				if (mpCurrentTarget->getLevel() != mpMover->mCurrentLevel)
					mpMover->mCurrentLevel = mpCurrentTarget->getLevel();
				mLinear = mpCurrentTarget->getPosision() - mpMover->getPosition();
				mLinear.normalize();
				mLinear *= mpMover->getMaxVelocity();
				mAngular = 0;
			}

	return this;

}