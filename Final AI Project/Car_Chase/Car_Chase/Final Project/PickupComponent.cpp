#include "PickupComponent.h"
#include "Unit.h"

PickupComponent::PickupComponent(std::string tagID, Unit* myUnit)
{

	mTagID = tagID;
	mpMyUnit = myUnit;
}

PickupComponent::~PickupComponent()
{
	
}

void PickupComponent::update()
{
	// delete mpMyUnit if a collision is detected between the player and mpMyUnit
	if (Game::getInstance()->getLevelManager()->checkCollisionWithPlayer(mpMyUnit))
	{
		// do something different based on this Unit's tag
		if (mTagID == "Key")
		{
			gpEventSystem->fireEvent(PlayAudioEvent("Key"));
			gpEventSystem->fireEvent(PICKUP_KEY_EVENT);
			mpMyUnit->setIsActive(false);
		}

		else if (mTagID == "Bow")
		{
			gpEventSystem->fireEvent(PlayAudioEvent("Fanfare"));
			gpEventSystem->fireEvent(PICKUP_BOW_EVENT);
			mpMyUnit->setIsActive(false);
		}

		else if (mTagID == "Triforce")
		{
			gpEventSystem->fireEvent(PlayAudioEvent("Fanfare"));
			gpEventSystem->fireEvent(WIN_GAME_EVENT);
			mpMyUnit->setIsActive(false);
		}
			
	}
}

void PickupComponent::handleEvent(const Event& theEvent)
{
	
}