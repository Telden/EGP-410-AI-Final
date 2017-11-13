#include "Floor.h"

Floor::Floor()
{
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(FLOORANIMNAME));
}

Floor::~Floor()
{

}

void Floor::render()
{
	getGraphicsSystem()->drawSprite(getAnimation().getSprite(SPRITENUM), getLocX(), getLocY());
}

void Floor::update()
{

}