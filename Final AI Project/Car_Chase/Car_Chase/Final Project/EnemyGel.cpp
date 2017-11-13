#include "EnemyGel.h"
#include "AnimationManager.h"

EnemyGel::EnemyGel(int locX, int locY)
{
	//Initialize the the gel and is components
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(GELANIMNAME));

	setLocX(locX);
	setLocY(locY);

	mpStalfosComponent = new StalfosComponent(this, 32);
	mpRenderComponent = new RenderComponent(this);
	mpCanGetKilledComponent = new CanGetKilledComponent(this);
	mpScaryComponent = new ScaryComponent(this);
}

EnemyGel::~EnemyGel()
{
	//Clean up component
	delete mpStalfosComponent;
	delete mpRenderComponent;
	delete mpCanGetKilledComponent;
	delete mpScaryComponent;
}

void EnemyGel::render()
{
	mpRenderComponent->render();
}

void EnemyGel::update()
{
	//Update components
	mpStalfosComponent->update();
	mpCanGetKilledComponent->update();
	mpScaryComponent->update();
}