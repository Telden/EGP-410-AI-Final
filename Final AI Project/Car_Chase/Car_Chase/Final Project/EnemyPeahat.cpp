#include "EnemyPeahat.h"
#include "AnimationManager.h"


EnemyPeahat::EnemyPeahat(int locX, int locY, bool moveHorizontal)
{
	//Initialize the Peahat
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(PEAHATANIMNAME));

	setLocX(locX);
	setLocY(locY);
	mMoveHorizontal = moveHorizontal;
	mpPeahatComponent = new PeahatComponent(this, mMoveHorizontal);
	mpRenderComponent = new RenderComponent(this);
	mpCanGetKilledByArrowComponent = new CanGetKilledByArrowComponent(this);
	mpScaryComponent = new ScaryComponent(this);
}


//Clean up the component
EnemyPeahat::~EnemyPeahat()
{
	delete mpPeahatComponent;
	delete mpRenderComponent;
	delete mpCanGetKilledByArrowComponent;
	delete mpScaryComponent;
}

void EnemyPeahat::render()
{
	mpRenderComponent->render();
}

//Update the components
void EnemyPeahat::update()
{
	mpPeahatComponent->update();
	mpScaryComponent->update();
	mpCanGetKilledByArrowComponent->update();
}