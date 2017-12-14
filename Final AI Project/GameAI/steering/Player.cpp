#include "PlayerMovement.h"
#include "Steering.h"
#include "Player.h"
#include "Game.h"
#include "Node.h"
#include "Graph.h"

Player::Player(Sprite *pSprite, const Vector2D &position, float orientation, const Vector2D &velocity, float rotationVel, float maxVelocity, float maxAcceleration)
	:KinematicUnit(pSprite, position, orientation, velocity, rotationVel, 0, maxVelocity, maxAcceleration)
{
	mpPlayerMovement = new PlayerMovement(this);
	setSteering(mpPlayerMovement);
	mpGraph = GRAPH;
	mLastNode = GRAPH->getNode(0);
}

Player::~Player()
{
   if (mpPlayerMovement != NULL)
      delete mpPlayerMovement;
}


void Player::switchMap()
{
	if (mCurrentLevel == 0)
		mCurrentLevel = 1;
	else if (mCurrentLevel == 1)
		mCurrentLevel = 0;
}