#include "Tile.h"
#include "AnimationManager.h"
#include "GraphicsSystem.h"

Tile::Tile(int locX, int locY, int animNum)
{
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(TILEANIMNAME));
	setLocX(locX);
	setLocY(locY);
	mSpriteNum = animNum;
}

Tile::~Tile()
{

}

void Tile::render()
{
	getGraphicsSystem()->drawSprite(getAnimation().getSprite(mSpriteNum), getLocX(), getLocY());
}

void Tile::update()
{

}