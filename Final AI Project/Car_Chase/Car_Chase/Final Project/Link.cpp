#include "Link.h"
#include "LinkComponent.h"
#include "AnimationManager.h"
#include "Animation.h"
#include "Game.h"

Link::Link(int locX, int locY)
{

	setLocX(locX);
	setLocY(locY);

	mpLinkComponent = new LinkComponent(this, Game::getInstance()->getLinkHealth(), 4, 8, true, false);
}

//Constructor for loading from file
Link::Link(int locX, int locY, int numKeys, int numHealth, int maxHealth, std::string direction, bool bow)
{
	setLocX(locX);
	setLocY(locY);

	mpLinkComponent = new LinkComponent(this, numKeys, numHealth, maxHealth, direction, bow);
}

Link::~Link()
{
	delete mpLinkComponent;
}

void Link::render()
{
	mpLinkComponent->render();
}

void Link::update()
{
	mpLinkComponent->update();
}