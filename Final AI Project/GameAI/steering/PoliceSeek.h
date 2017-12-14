#pragma once
#include "Steering.h"
#include "Vector2D.h"
#include <stack>
#include "AStarPathfinder.h"
class KinematicUnit;
class Node;
class StateMachine;
class Steering;

class PoliceSeek : public Steering
{
public:
	PoliceSeek(KinematicUnit* mover, KinematicUnit* target, int radius, StateMachine* machine, Steering* wander);
	PoliceSeek();
	Steering* getSteering();

private:
	int mRadius;
	KinematicUnit* mpTarget;
	KinematicUnit* mpMover;
	Vector2D mTarget;
	std::stack<Node*>mpNodeStack;
	AStarPathfinder mAStar;
   StateMachine* mpStateMachine;
   Steering* mpWander;
};