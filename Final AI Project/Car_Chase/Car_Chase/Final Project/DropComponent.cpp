#include "DropComponent.h"
#include "Game.h"
#include "LevelManager.h"
#include "Level.h"
#include "Unit.h"
#include "Treasures.h"

DropComponent::DropComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
}

DropComponent::~DropComponent()
{

}

void DropComponent::update()
{
	//If the enemy dies, put a key into the level treasure array in at the possion of the dead unit
	if (!mpMyUnit->getIsActive())
	{
		std::cout << "AddingKey\n";
		Game::getInstance()->getLevelManager()->getCurrentLevel()->addTreasure(new Treasure("Key", mpMyUnit->getLocX(), mpMyUnit->getLocY(), 6));
	}
}

void DropComponent::handleEvent(const Event& theEvent)
{

}