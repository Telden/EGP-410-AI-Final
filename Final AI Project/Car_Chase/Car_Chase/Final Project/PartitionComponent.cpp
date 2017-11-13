#include "PartitionComponent.h"
#include "Unit.h"

PartitionComponent::PartitionComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
}

PartitionComponent::~PartitionComponent()
{

}

void PartitionComponent::handleEvent(const Event& theEvent)
{

}

void PartitionComponent::update()
{

}