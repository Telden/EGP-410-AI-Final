#include "EnemyKese.h"
#include "AnimationManager.h"
#include "GraphicsSystem.h"
#include "RenderComponent.h"
#include "CanGetKilledComponent.h"
#include "ScaryComponent.h"

EnemyKese::EnemyKese(int locX, int locY)
{
	//Initalize the Kese
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(KESEANIMNNAME));
	setLocX(locX);
	setLocY(locY);
	mpKeseComponent = new KeseComponent(this);
	mpRenderComponent = new RenderComponent(this);
	mpCanGetKilledComponent = new CanGetKilledComponent(this);
	mpScaryComponent = new ScaryComponent(this);
}

EnemyKese::~EnemyKese()
{
	//Clean up the components
	delete mpKeseComponent;
	delete mpRenderComponent;
	delete mpCanGetKilledComponent;
	delete mpScaryComponent;
}

void EnemyKese::render()
{
	mpRenderComponent->render();
}

void EnemyKese::update()
{
	//Update the components
	mpKeseComponent->update();
	mpCanGetKilledComponent->update();
	mpScaryComponent->update();
}