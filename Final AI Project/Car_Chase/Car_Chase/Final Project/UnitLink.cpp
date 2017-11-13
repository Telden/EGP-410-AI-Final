#include "UnitLink.h"

UnitLink::UnitLink(int numHearts, int speedAKApixelsPerFrame, bool canShield, bool canSword, bool canBow)
{
	// set the health
	mMaxHealth = numHearts;
	mCurrentHealth = numHearts;

	// set the movement speed, also known as the number of pixels to move Link per frame
	mMovementSpeed = speedAKApixelsPerFrame;

	// set whether or not Link can use his abilities
	mCanShield = canShield;
	mCanSword = canSword;
	mCanBow = canBow;

	// set the direction is facing by default
	mDirectionFacing = "up";
}

UnitLink::~UnitLink()
{

}


// if UnitLink is a child of Unit, it should be able to overload the original render and update functions
void UnitLink::render()
{

}

// if UnitLink is a child of Unit, it should be able to overload the original render and update functions
void UnitLink::update()
{
	if (mCurrentHealth <= 0)
	{
		gpEventSystem.fireEvent("LoseGameEvent");
	}
}

void UnitLink::handleEvent(const Event& theEvent)
{
	// if UnitLink is a child of Unit it should have a location
	if (theEvent.getType() == MOVEMENT_EVENT_UP)
	{
		setLocY(getLocY() - mMovementSpeed);
		mDirectionFacing = "up";
	}
	if (theEvent.getType() == MOVEMENT_EVENT_DOWN)
	{
		setLocY(getLocY() + mMovementSpeed);
		mDirectionFacing = "down";
	}
	if (theEvent.getType() == MOVEMENT_EVENT_LEFT)
	{
		setLocX(getLocX() - mMovementSpeed);
		mDirectionFacing = "left";
	}
	if (theEvent.getType() == MOVEMENT_EVENT_RIGHT)
	{
		setLocX(getLocX() + mMovementSpeed);
		mDirectionFacing = "right";
	}

	if (theEvent.getType() == ATTACK_EVENT_SWORD)
	{
		// fire event?
		//SpawnSword();
	}

	if (theEvent.getType() == ATTACK_EVENT_BOW)
	{
		// fire event?
		//SpawnArrow();
	}

	if (theEvent.GetType() == PLAYER_HIT)
	{
		mCurrentHealth--;
	}
}