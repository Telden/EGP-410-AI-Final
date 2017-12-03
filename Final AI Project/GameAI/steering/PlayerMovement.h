#pragma once

#include "Steering.h"

class KinematicUnit;

class PlayerMovement :public Steering
{
public:
	PlayerMovement(KinematicUnit* pUnit);
	~PlayerMovement(){};

	virtual Steering* getSteering(); 
	Vector2D calculateOrientationAsVector();


	void recieveMessage(char input, bool isPressed);

private:
	KinematicUnit* mpMover;
	bool mShouldCast = true;
	float previousAngle = 0;

	/* Player Input Bools */
	bool mMoveForwards = false;
	bool mMoveBackwards = false;
	bool mMoveLeft = false;
	bool mMoveRight = false;
	float mMaxRotationalVelocity = 5;
};