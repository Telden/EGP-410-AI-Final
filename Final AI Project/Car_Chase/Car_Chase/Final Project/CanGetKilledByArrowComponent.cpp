#include "CanGetKilledByArrowComponent.h"

#include "Game.h"
#include "LevelManager.h"
#include "Unit.h"

CanGetKilledByArrowComponent::CanGetKilledByArrowComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
}

CanGetKilledByArrowComponent::~CanGetKilledByArrowComponent()
{
	
}

void CanGetKilledByArrowComponent::render()
{

}

void CanGetKilledByArrowComponent::update()
{
	if (Game::getInstance()->getLevelManager()->checkCollisionWithArrow(mpMyUnit))
	{
		gpEventSystem->fireEvent(PlayAudioEvent("Enemy_Died"));
		mpMyUnit->setIsActive(false);
	}
}

void CanGetKilledByArrowComponent::handleEvent(const Event& theEvent)
{

}