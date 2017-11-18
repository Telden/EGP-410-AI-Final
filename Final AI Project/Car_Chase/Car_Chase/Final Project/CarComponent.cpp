#include "CarComponent.h"
#include "Unit.h"

CarComponent::CarComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
}

CarComponent::~CarComponent()
{

}

void CarComponent::update()
{
	
}

void CarComponent::handleEvent(const Event& theEvent)
{

}