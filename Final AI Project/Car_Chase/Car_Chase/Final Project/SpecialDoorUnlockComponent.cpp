#include "SpecialDoorUnlockComponent.h"
#include "Unit.h"

SpecialDoorUnlockComponent::SpecialDoorUnlockComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
	gpEventSystem->addListener(BOSS_DEFEATED_EVENT, this);
}

SpecialDoorUnlockComponent::~SpecialDoorUnlockComponent()
{
	gpEventSystem->removeListenerFromAllEvents(this);
}

void SpecialDoorUnlockComponent::handleEvent(const Event& theEvent)
{
	// special closed doors (that can't be unlocked with a key) will be opened when Aquamentus is defeated
	if (theEvent.getType() == BOSS_DEFEATED_EVENT)
	{
		mpMyUnit->setIsActive(false);
		mpMyUnit->setLocX(-1000);
	}
}