#include "Sword.h"
#include "AnimationManager.h"

Sword::Sword()
{
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(SWORDANIMNAME));
	//mpSwordComponent = new SwordComponent(this);
}

Sword::~Sword()
{
	//delete mpSwordComponent;
	/*
		std::string linktemp = getLinkDirection();
		if(linktemp == "up")
			getGraphicsSystem()->drawSprite(getAnimation().getSprite(SWORDUP), {linkX}, {linkY});
		else if (linktemp == "down")
			getGraphicsSystem()->drawSprite(getAnimation().getSprite(SWORDDOWN), {linkX}, {linkY});
		else if (linktemp == "left")
			getGraphicsSystem()->drawSprite(getAnimation().getSprite(SWORDLEFT), {linkX}, {linkY});
		else if (linktemp == "right")
			getGraphicsSystem()->drawSprite(getAnimation().getSprite(SWORDRIGHT), {linkX}, {linkY});
		else 
			std::cout << "An error has accured. No directional input to render link's sword\n";
	*/
}

void Sword::render()
{
	std::cout << "This is the virtual renderer\n";
}

void Sword::update()
{

}