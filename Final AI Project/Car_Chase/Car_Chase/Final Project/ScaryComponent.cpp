#include "ScaryComponent.h"

ScaryComponent::ScaryComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
}

ScaryComponent::~ScaryComponent()
{

}

void ScaryComponent::update()
{
	// if Link collides with something that's scary, hurt him!
	if (Game::getInstance()->getLevelManager()->checkCollisionWithPlayer(mpMyUnit))
	{
		gpEventSystem->fireEvent(HURT_PLAYER_EVENT);
	}
}

void ScaryComponent::handleEvent(const Event& theEvent)
{

}