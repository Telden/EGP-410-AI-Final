#include "EnemyStalfos.h"
#include "AnimationManager.h"


EnemyStalfos::EnemyStalfos(int locX, int locY, bool isDropping)
{
	//Initialize the Stalfos 
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(STALFOSANIMNAME));

	setLocX(locX);
	setLocY(locY);
	mIsDropping = isDropping;
	mpStalfosComponent = new StalfosComponent(this, 0);
	mpRenderComponent = new RenderComponent(this);
	mpCanGetKilledComponent = new CanGetKilledComponent(this);
	mpScaryComponent = new ScaryComponent(this);
	if (mIsDropping)
		mpDropComponent = new DropComponent(this);
}

EnemyStalfos::~EnemyStalfos()
{
	delete mpStalfosComponent;
	delete mpRenderComponent;
	delete mpCanGetKilledComponent;
	delete mpScaryComponent;
	if (mIsDropping)
		delete mpDropComponent;
}

void EnemyStalfos::render()
{
	mpRenderComponent->render();
}

//update components
void EnemyStalfos::update()
{
	mpStalfosComponent->update();
	mpCanGetKilledComponent->update();
	mpScaryComponent->update();
	if (mIsDropping)
		mpDropComponent->update();
}