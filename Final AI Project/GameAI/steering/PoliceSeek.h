#pragma once
#include "Steering.h"
#include "Vector2D.h"
#include <stack>

class KinematicUnit;
class Node;
class AStarPathfinder;
class PoliceSeek : public Steering
{
public:
	PoliceSeek(KinematicUnit* mover, KinematicUnit* target, int radius);
	PoliceSeek() {};
	Steering* getSteering();

private:
	int mRadius;
	KinematicUnit* mpTarget;
	KinematicUnit* mpMover;
	Vector2D mTarget;
	std::stack<Node*>mpNodeStack;
	AStarPathfinder* mpAStar;
};