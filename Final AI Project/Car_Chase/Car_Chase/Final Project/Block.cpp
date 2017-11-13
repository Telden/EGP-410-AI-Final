#include "Block.h"
#include "AnimationManager.h"
#include "GraphicsSystem.h"
Block::Block(int locX, int locY, int animNum)
{
	setIsActive(true);
	setAnimation(*getAnimationManager()->getAnimation(BLOCKANIMNAME));
	setLocX(locX);
	setLocY(locY);
	mSpriteNum = animNum;
}

Block::~Block()
{

}

void Block::render()
{
	// no render component here so different types of blocks can be drawn
	getGraphicsSystem()->drawSprite(getAnimation().getSprite(mSpriteNum), getLocX(), getLocY());
}

void Block::update()
{

}