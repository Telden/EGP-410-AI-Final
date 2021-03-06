#pragma once

#include "Steering.h"
#include "CircleCollision.h"

class KinematicUnit;

class PlayerMovement :public Steering
{
public:
	PlayerMovement(KinematicUnit* pUnit);
	~PlayerMovement(){ mpMover = NULL; };

	virtual Steering* getSteering(); 
	Vector2D deceleratePlayer();

	void recieveMessage(char input, bool isPressed);

private:
	KinematicUnit* mpMover;
	bool mShouldCast = true;
	float previousAngle = 0;
	float mCurrentAcceleration = 0;
	float mAccelerationIncrease = 5;
	float mDeceleration = 1;

   CircleCollision mCol;

	/* Player Input Bools */
	bool mMoveForwards = false;
	bool mMoveBackwards = false;
	bool mMoveLeft = false;
	bool mMoveRight = false;
	float mMaxRotationalVelocity = 5;
	const int spriteWidthandHeight = 50;
	int mWallCooldown = 5;
};