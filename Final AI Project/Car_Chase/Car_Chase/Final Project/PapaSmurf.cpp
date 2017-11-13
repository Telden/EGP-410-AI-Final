#include "PapaSmurf.h"
#include "Game.h"
#include "RenderComponent.h"
#include "AnimationManager.h"

PapaSmurf::PapaSmurf(int locX, int locY)
{
	setAnimation(*getAnimationManager()->getAnimation(SMURFANINNAME));

	mpRenderComponent = new RenderComponent(this);
	setIsActive(true);
	setLocX(locX);
	setLocY(locY);
}

PapaSmurf::~PapaSmurf()
{
	delete mpRenderComponent;
}

void PapaSmurf::render()
{
	mpRenderComponent->render();
}
