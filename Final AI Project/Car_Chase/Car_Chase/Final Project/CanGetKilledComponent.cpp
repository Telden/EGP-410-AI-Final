#include "CanGetKilledComponent.h"

#include "Game.h"
#include "LevelManager.h"
#include "Unit.h"

CanGetKilledComponent::CanGetKilledComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
}

CanGetKilledComponent::~CanGetKilledComponent()
{
	
}

void CanGetKilledComponent::render()
{

}

void CanGetKilledComponent::update()
{
	if (Game::getInstance()->getLevelManager()->checkCollisionWithSword(mpMyUnit))
	{
		gpEventSystem->fireEvent(PlayAudioEvent("Enemy_Died"));
		mpMyUnit->setIsActive(false);
	}

	if (Game::getInstance()->getLevelManager()->checkCollisionWithArrow(mpMyUnit))
	{
		gpEventSystem->fireEvent(PlayAudioEvent("Enemy_Died"));
		mpMyUnit->setIsActive(false);
	}
}

void CanGetKilledComponent::handleEvent(const Event& theEvent)
{

}