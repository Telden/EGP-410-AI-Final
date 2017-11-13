#include "Unit.h"
#include "Game.h"
#include "GraphicsSystem.h"
#include "AnimationManager.h"

Unit::Unit()
{
	mp_GS = Game::getInstance()->getGraphicsSystem();
	mpAnimationManager = Game::getInstance()->getAnimationManager();
}

Unit::Unit(int locX, int locY)
{
	mp_GS = Game::getInstance()->getGraphicsSystem();
	mpAnimationManager = Game::getInstance()->getAnimationManager();
}

Unit::~Unit()
{

}

void Unit::render()
{
	;
}

void Unit::update()
{

}