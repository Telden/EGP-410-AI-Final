#pragma once
#include "Steering.h"

class KinematicUnit;
class Node;
class AStarPathfinder;
class Graph;
class PoliceFlee : public Steering
{
public:
	PoliceFlee(KinematicUnit* mover, KinematicUnit* target, int radius);
	PoliceFlee() {};
	Steering* getSteering();

private:
	int mRadius;
	KinematicUnit* mpTarget;
	KinematicUnit* mpMover;
	Graph* mpGraph;
	Node* mpCurrentTarget;
};