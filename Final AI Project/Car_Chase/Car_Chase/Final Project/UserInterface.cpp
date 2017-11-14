#include "UserInterface.h"
#include "GraphicsSystem.h"
#include "AnimationManager.h"
#include "EventSystem.h"
#include "Animation.h"
#include "Event.h"
#include "Game.h"


UserInterface::UserInterface( GraphicsSystem* gs)
{
	/*mp_GS = gs;
	mpUIAnim = Game::getInstance()->getAnimationManager()->getAnimation("UI");*/

}

UserInterface::~UserInterface()
{
	//gpEventSystem->removeListenerFromAllEvents(this);
}

void UserInterface::handleEvent(const Event& theEvent)
{
	/*if (theEvent.getType() == HURT_PLAYER_EVENT && mHurtWaitAmount == 0)
	{
		mNumHearts--;
		if(mMaxHearts > mNumEmptyHearts)
			mNumEmptyHearts++;
		mHurtWaitAmount = 120;
	}
	else if (theEvent.getType() == PICKUP_KEY_EVENT)
	{
		mNumKey++;
	}
	else if (theEvent.getType() == OPEN_DOOR_EVENT)
	{
		mNumKey--;
	}
	else if (theEvent.getType() == PICKUP_BOW_EVENT)
	{
		mCanBow = true;
	}
	else if (theEvent.getType() == RESET_GAME_EVENT)
	{
		mNumHearts = mMaxHearts;
		mNumEmptyHearts = 0;
		mNumKey = 0;
	}*/
}
void UserInterface::reset()
{
	
}

void UserInterface::update()
{
	/*if (mHurtWaitAmount > 0)
	{
		mHurtWaitAmount--;
	}*/
}

void UserInterface::render()
{
	//int i;

	//mp_GS->drawSprite(mpUIAnim->getSprite(0), 32, 704);
	//if (mCanBow)
	//{
	//	mp_GS->drawSprite(mpUIAnim->getSprite(2), 128, 704);
	//}
	//else
	//{
	//	mp_GS->drawSprite(mpUIAnim->getSprite(3), 128, 704);
	//}
	//for (i = 0; i < mNumHearts; i++)
	//{
	//	mp_GS->drawSprite(mpUIAnim->getSprite(5), 220 + (i * 32), 704);
	//}
	//for (int j = 0; j < mNumEmptyHearts; j++)
	//{
	//	if (i == 0)
	//	{
	//		mp_GS->drawSprite(mpUIAnim->getSprite(6), 220 + (j * 32), 704);
	//	}
	//	else 
	//	{
	//		mp_GS->drawSprite(mpUIAnim->getSprite(6), 220 + (i * 32), 704);
	//		i++;
	//	}
	//	
	//}
	//	

	//for (int i = 0; i < mNumKey; i++)
	//{
	//	mp_GS->drawSprite(mpUIAnim->getSprite(4), 220 + (i * 32), 764);
	//}
}

void UserInterface::updateMaxHealth()
{
	//mMaxHearts = Game::getInstance()->getLinkHealth();
	//mNumHearts = Game::getInstance()->getLinkCurrentHealth();
	//mNumEmptyHearts = mMaxHearts - mNumHearts;
	//mNumKey = Game::getInstance()->getLinkCurrentKeys();
}