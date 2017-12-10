#pragma once
#include "Steering.h"
#include "Vector2D.h"

class KinematicUnit;
class Graph;
class Node;

class WanderToNode : public Steering
{
public:
		WanderToNode(KinematicUnit* pMover, Node* pCurrentNode, float radius);
		~WanderToNode() {};

		virtual Steering* getSteering();

private:
	KinematicUnit* mpMover;
	float mArrivalRadius;
	Graph* mpGraphPtr;
	Node*  mpCurrentNode;
	Node*  mpTargetNode;
};