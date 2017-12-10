#include "WanderToNode.h"
#include "KinematicUnit.h"
#include "Game.h"
#include "Graph.h"
#include "Node.h"
#include "Connection.h"
#include <math.h>
#include <vector>
#include <ctime>

WanderToNode::WanderToNode(KinematicUnit* pMover, Node* pCurrentNode, float radius)
{
	mpMover = pMover;
	mpGraphPtr = GRAPH;
	mpTargetNode = pCurrentNode;
	mpCurrentNode = mpTargetNode;
	mArrivalRadius = radius;

}

Steering* WanderToNode::getSteering()
{
	float distance;
	int seed;
	
	std::vector<Connection*> potentialConnections;
	distance = sqrt(pow((mpTargetNode->getPosision().getX() - mpMover->getPosition().getX()), 2) +
					pow((mpTargetNode->getPosision().getY() - mpMover->getPosition().getY()), 2));

	if (distance < mArrivalRadius)
	{
		potentialConnections = mpGraphPtr->getConnections(mpTargetNode->getId());
		for (int i = 0; i < potentialConnections.size(); i++)
		{
			std::cout << "Possible connections: " << potentialConnections[i]->getToNode()->getId() << std::endl;
		}
		seed = rand() % potentialConnections.size();
		mpCurrentNode = mpTargetNode;
		mpTargetNode = potentialConnections[seed]->getToNode();
		std::cout << "Chosen Target: " << mpTargetNode->getId();
	}

	mLinear = mpTargetNode->getPosision() - mpMover->getPosition();
	mLinear.normalize();
	mLinear *= mpMover->getMaxVelocity();
	mAngular = 0;
				
	return this;
}



