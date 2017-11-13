#include "Treasures.h"
#include "AnimationManager.h"
#include "GraphicsSystem.h"
#include "PickupComponent.h"

Treasure::Treasure(std::string tagID, int locX, int locY, int animNum)
{
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(TREASUREANIMNAME));
	mpPickupComponent = new PickupComponent(tagID, this);
	mTag = tagID;
	setLocX(locX);
	setLocY(locY);
	mSpriteNum = animNum;
}

Treasure::~Treasure()
{
	delete mpPickupComponent;
}

void Treasure::render()
{
	getGraphicsSystem()->drawSprite(getAnimation().getSprite(mSpriteNum), getLocX(), getLocY());
}

void Treasure::update()
{
	mpPickupComponent->update();
}