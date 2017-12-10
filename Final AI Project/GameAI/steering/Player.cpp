#include "PlayerMovement.h"
#include "Steering.h"
#include "Player.h"


Player::Player(Sprite *pSprite, const Vector2D &position, float orientation, const Vector2D &velocity, float rotationVel, float maxVelocity, float maxAcceleration)
	:KinematicUnit(pSprite, position, orientation, velocity, rotationVel, maxVelocity, maxAcceleration)
{
	mpPlayerMovement = new PlayerMovement(this);
	setSteering(mpPlayerMovement);
}

Player::~Player()
{
   if (mpPlayerMovement != NULL)
      delete mpPlayerMovement;
}