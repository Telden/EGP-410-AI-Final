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
	Graph* mpGraph;
	bool mIsSuperPowered = true;

public:
	Player(Sprite* pSprite, const Vector2D& position, float orientation, const Vector2D& velocity, float rotationVel, float maxVelocity = 1.0f, float maxAcceleration = 1.0f);
	~Player();
	PlayerMovement* getSteeringComponent() { return mpPlayerMovement; };
	bool getIsSuperPowered() { return  mIsSuperPowered; };
	void switchMap();
	

};