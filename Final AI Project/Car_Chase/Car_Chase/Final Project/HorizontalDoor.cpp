#include "HorizontalDoor.h"
#include "AnimationManager.h"
#include "GraphicsSystem.h"
#include "EventSystem.h"
#include "Event.h"
#include "SpecialDoorUnlockComponent.h"

HorizontalDoor::HorizontalDoor(int locX, int locY, int openDoorNum, int closedDoorNum,  int specialnum, bool isOpen, bool isSpecial)
{
	//Initialize the horizontal door
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(HORIZDOORANIMNAME));

	setLocX(locX);
	setLocY(locY);
	mOpenDoorSprite = openDoorNum;
	mClosedDoorSprite = closedDoorNum;
	mSpecialDoorSprite = specialnum;
	mIsOpen = isOpen;
	mIsSpecial = isSpecial;
	if (mIsSpecial) 
	{
		mpSpecialDoorUnlockComponent = new SpecialDoorUnlockComponent(this);
	}
}

HorizontalDoor::~HorizontalDoor()
{
	if (mIsSpecial)
	{
		delete mpSpecialDoorUnlockComponent;
	}
}

void HorizontalDoor::render()
{
	//If it's special use that specific door sprite
	if (mIsSpecial)
	{
		getGraphicsSystem()->drawSprite(getAnimation().getSprite(mSpecialDoorSprite), getLocX(), getLocY());
	}
	else
	{
		//If it's regular and open render the open door sprite
		if (mIsOpen)
		{
			getGraphicsSystem()->drawSprite(getAnimation().getSprite(mOpenDoorSprite), getLocX(), getLocY());
		}
		else //Render the closed door sprite
		{
			getGraphicsSystem()->drawSprite(getAnimation().getSprite(mClosedDoorSprite), getLocX(), getLocY());
		}
	}
	

}

void HorizontalDoor::update()
{

}

bool HorizontalDoor::getIsOpen()
{
	return mIsOpen;
}