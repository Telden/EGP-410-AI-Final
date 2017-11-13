#include "RenderComponent.h"

#include "Unit.h"
#include "GraphicsSystem.h"

RenderComponent::RenderComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
}

RenderComponent::~RenderComponent()
{

}

void RenderComponent::render()
{
	// control all rendering here (except for special cases)
	mpMyUnit->getGraphicsSystem()->drawSprite(mpMyUnit->getAnimation().getSprite(mpMyUnit->getAnimation().getCurrentSprite()), mpMyUnit->getLocX(), mpMyUnit->getLocY());

	// update the animation, too!
	mpMyUnit->getAnimation().update();
}

void RenderComponent::handleEvent(const Event& theEvent)
{

}