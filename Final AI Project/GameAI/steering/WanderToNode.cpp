#include "WanderToNode.h"
#include "KinematicUnit.h"
#include "Game.h"
#include "Graph.h"
#include "Node.h"
#include "Connection.h"
#include <math.h>
#include <vector>

WanderToNode::WanderToNode(KinematicUnit* pMover, Node* pCurrentNode, float radius)
{
	mpMover = pMover;
	mpGraphPtr = GRAPH;
	mpTargetNode = pCurrentNode;
	mArrivalRadius = radius;
}

Steering* WanderToNode::getSteering()
{
	float distance;
	std::vector<Connection*> potentialConnections;
	distance = sqrt(pow((mpCurrentNode->getPosision().getX() - mpMover->getPosition().getX()), 2) +
					pow((mpCurrentNode->getPosision().getY() - mpMover->getPosition().getY()), 2));
	if (distance < mArrivalRadius)
	{
		mpGraphPtr->getConnections(mpTargetNode->getId());
	}
				
}



