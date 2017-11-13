#include "Fireball.h"
#include "AnimationManager.h"
#include "RenderComponent.h"
#include "ScaryComponent.h"
#include "GraphicsSystem.h"

Fireball::Fireball(int locX, int locY)
{
	//Initialize the fireball
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(FIREBALLANIMNAME));
	mpRenderComponent = new RenderComponent(this);
	mpScaryComponent = new ScaryComponent(this);
	setLocX(locX);
	setLocY(locY);
}

//Clean up components
Fireball::~Fireball()
{
	delete mpScaryComponent;
	delete mpRenderComponent;
}

void Fireball::render()
{
	mpRenderComponent->render();
}

//Update the components
void Fireball::update()
{
	mpScaryComponent->update();
}