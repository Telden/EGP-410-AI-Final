#pragma once
#include "Kinematic.h"
#include "KinematicUnit.h"
class PlayerMovement;
class Sprite;
class Node;
class Graph;
class Player :public KinematicUnit
{
private:
	PlayerMovement* mpPlayerMovement;
	Node* mLastNode;
	//int mCurrentLevel  = 0;
	Graph* mpGraph;

public:
	Player(Sprite* pSprite, const Vector2D& position, float orientation, const Vector2D& velocity, float rotationVel, float maxVelocity = 1.0f, float maxAcceleration = 1.0f);
	~Player();
	PlayerMovement* getSteeringComponent() { return mpPlayerMovement; };
	Node* getLastNode() { return mLastNode; };
	void updateGridPosision();
	void switchMap();
	//int mCurrentLevel = 0;

};