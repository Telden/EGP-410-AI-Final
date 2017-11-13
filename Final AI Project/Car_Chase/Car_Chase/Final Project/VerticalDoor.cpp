#include "VerticalDoor.h"
#include "AnimationManager.h"
#include "GraphicsSystem.h"
#include "SpecialDoorUnlockComponent.h"

VerticalDoor::VerticalDoor(int locX, int locY, int openDoorNum, int closedDoorNum, int specialDoorNum, bool isOpen, bool isSpecial)
{
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(VERTDOORANIMNAME));
	setLocX(locX);
	setLocY(locY);
	mOpenDoorSprite = openDoorNum;
	mClosedDoorSprite = closedDoorNum;
	mSpecialDoorSprite = specialDoorNum;
	mIsOpen = isOpen;
	mIsSpecial = isSpecial;
	if (mIsSpecial)
	{
		mpSpecialDoorUnlockComponent = new SpecialDoorUnlockComponent(this);
	}
}

VerticalDoor::~VerticalDoor()
{
	if (mIsSpecial)
	{
		delete mpSpecialDoorUnlockComponent;
	}
}

void VerticalDoor::render()
{
	if (mIsSpecial) // If it's special use the special door sprite
	{
		getGraphicsSystem()->drawSprite(getAnimation().getSprite(mSpecialDoorSprite), getLocX(), getLocY());
	}
	else
	{
		if (mIsOpen) // if its not special and is open render the open door sprite
			getGraphicsSystem()->drawSprite(getAnimation().getSprite(mOpenDoorSprite), getLocX(), getLocY());
		else //Render the closed door sprite
		{
			getGraphicsSystem()->drawSprite(getAnimation().getSprite(mClosedDoorSprite), getLocX(), getLocY());
		}
	}
	
}

void VerticalDoor::update()
{

}

bool VerticalDoor::getIsOpen()
{
	return mIsOpen;
}