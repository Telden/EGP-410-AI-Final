#include "PeahatComponent.h"
#include "Unit.h"

PeahatComponent::PeahatComponent(Unit* myUnit, bool moveHorizontal)
{
	mpMyUnit = myUnit;
	mMoveHorizontal = moveHorizontal;
}

PeahatComponent::~PeahatComponent()
{
	
}

void PeahatComponent::update()
{
	// move horizontally
	if (mMoveHorizontal)
	{
		mpMyUnit->setLocX(mpMyUnit->getLocX() + 3);

		// screen wrap if the Peahat leaves the screen
		if (mpMyUnit->getLocX() < -64)
		{
			mpMyUnit->setLocX(1064);
		}
		if (mpMyUnit->getLocX() > 1064)
		{
			mpMyUnit->setLocX(-64);
		}
	}
	// move vertically
	else
	{
		mpMyUnit->setLocY(mpMyUnit->getLocY() + 3);

		// screen wrap if the Peahat leaves the screen
		if (mpMyUnit->getLocY() < -64)
		{
			mpMyUnit->setLocY(964);
		}
		if (mpMyUnit->getLocY() > 964)
		{
			mpMyUnit->setLocY(-64);
		}
	}
}

void PeahatComponent::handleEvent(const Event& theEvent)
{

}