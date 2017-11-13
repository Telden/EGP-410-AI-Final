#include "Aquamentus.h"
#include "AquamentusComponent.h"
#include "AnimationManager.h"

Aquamentus::Aquamentus(int locX, int locY)
{
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation("Dragon"));

	mpAquamentusComponent = new AquamentusComponent(this);
	mpRenderComponent = new RenderComponent(this);
	mpScaryComponent = new ScaryComponent(this);

	setLocX(700);
	setLocY(240);
}

Aquamentus::~Aquamentus()
{
	//Clean up component
	delete mpAquamentusComponent;
	delete mpRenderComponent;
	delete mpScaryComponent;
}

void Aquamentus::render()
{
	// Aquamentus doesn't render itself, it renders its fireballs
	mpAquamentusComponent->render();
	mpRenderComponent->render();
}

void Aquamentus::update()
{
	//call update on the components
	mpScaryComponent->update();
	mpAquamentusComponent->update();
}