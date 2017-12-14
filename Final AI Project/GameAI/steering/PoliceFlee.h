#pragma once
#include "Steering.h"

class KinematicUnit;
class Node;
class AStarPathfinder;
class Graph;
class StateMachine;

class PoliceFlee : public Steering
{
public:
	PoliceFlee(KinematicUnit* mover, KinematicUnit* target, int radius, StateMachine* machine, Steering* wander);
	PoliceFlee() {};
	Steering* getSteering();

private:
	int mRadius;
	KinematicUnit* mpTarget;
	KinematicUnit* mpMover;
	Graph* mpGraph;
	Node* mpCurrentTarget;
   StateMachine* mpStateMachine;
   Steering* mpWander;
   int mFleeTime = 30;
};