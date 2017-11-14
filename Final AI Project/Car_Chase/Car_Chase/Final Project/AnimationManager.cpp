#include "AnimationManager.h"
#include "Animation.h"
#include "GraphicsBuffer.h"
#include "BufferManager.h"
#include "Sprite.h"

/*--------------------------------------------------------------------*/
// MOST FUNCTIONS HERE WRITTEN BY PROFESSOR DEAN LAWSON
// SPECIFICALLY THE SYNTAX USED TO CREATE AND MANIPULATE MAPS
/*--------------------------------------------------------------------*/

AnimationManager::AnimationManager()
{

}

AnimationManager::~AnimationManager()
{
	clearList();
}

void AnimationManager::initAnimation(GraphicsBufferManager* mp_GBM)
{
	GraphicsBuffer* tempPath;
	Animation* tempAnim;
	
	/* [LINK ATTACK] */
		/* 0: Down || 1: Up || 2: Left || 3: Right */
	tempPath = mp_GBM->getBuffer("LinkAttack");

	tempAnim = new Animation(1, 30);
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	addAnimation("LinkAttackDown", tempAnim);

	tempAnim = new Animation(1, 30);
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 16, 16));
	addAnimation("LinkAttackUp", tempAnim);

	tempAnim = new Animation(1, 30);
	tempAnim->addSprite(Sprite(*tempPath, 32, 0, 16, 16));
	addAnimation("LinkAttackLeft", tempAnim);

	tempAnim = new Animation(1, 30);
	tempAnim->addSprite(Sprite(*tempPath, 48, 0, 16, 16));
	addAnimation("LinkAttackRight", tempAnim);

	/* [LINK MOVEMENT] */
		/* 
		   0: Down Left Foot || 1: Down Right Foot
		   2: Up Left Foot || 3: Up Right Foot
		   4: Left Idle || 5: Left Moving
		   6: Right Idle || 6: Right Moving 
		*/
	tempPath = mp_GBM->getBuffer("LinkMove");
	tempAnim = new Animation(2, 10);
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 16, 16));
	addAnimation("LinkMoveDown", tempAnim);

	tempAnim = new Animation(2, 10);
	tempAnim->addSprite(Sprite(*tempPath, 32, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 48, 0, 16, 16));
	addAnimation("LinkMoveUp", tempAnim);

	tempAnim = new Animation(2, 10);
	tempAnim->addSprite(Sprite(*tempPath, 64, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 80, 0, 16, 16));
	addAnimation("LinkMoveLeft", tempAnim);

	tempAnim = new Animation(2, 10);
	tempAnim->addSprite(Sprite(*tempPath, 96, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 112, 0, 16, 16));
	addAnimation("LinkMoveRight", tempAnim);

	/* [SWORD] */
		/* 0: Up || 1: Down || 2: Right || 3: Left*/
	tempPath = mp_GBM->getBuffer("Sword");
	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	addAnimation("SwordUp", tempAnim);

	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 16, 16));
	addAnimation("SwordDown", tempAnim);
	
	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 32, 0, 16, 16));
	addAnimation("SwordRight", tempAnim);

	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 48, 0, 16, 16));
	addAnimation("SwordLeft", tempAnim);

	
	//Title Animation
	tempAnim = new Animation(4, 15);
	tempPath = mp_GBM->getBuffer("Title");
	tempAnim->addSprite(Sprite(*tempPath, 3, 4, 240, 256));
	tempAnim->addSprite(Sprite(*tempPath, 262, 4, 240, 256));
	tempAnim->addSprite(Sprite(*tempPath, 3, 247, 240, 256));
	tempAnim->addSprite(Sprite(*tempPath, 262, 247, 240, 256));
	addAnimation("Title", tempAnim);

	/* [UI ELEMENTS] */
		/*
			0: Sword Slot || 1: Empty Sword Slot
			2: Bow Slot   || 3: Empty Bow Slot
			4: Key		  || 5: Full Heart  || 6: Empty Heart
		*/
	tempAnim = new Animation(7, 0);
	tempPath = mp_GBM->getBuffer("UI");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 29, 17));
	tempAnim->addSprite(Sprite(*tempPath, 17, 0, 29, 17));
	tempAnim->addSprite(Sprite(*tempPath, 34, 0, 29, 17));
	tempAnim->addSprite(Sprite(*tempPath, 51, 0, 29, 17));
	tempAnim->addSprite(Sprite(*tempPath, 68, 0, 8, 8));
	tempAnim->addSprite(Sprite(*tempPath, 85, 0, 8, 8));
	tempAnim->addSprite(Sprite(*tempPath, 102, 0, 8, 8));
	addAnimation("UI", tempAnim);


	//Nullify local pointers
	tempPath = NULL;
	tempAnim = NULL;
}

void AnimationManager::addAnimation(std::string name, Animation* newAnimation)
{
	mpAnimations.insert(std::pair<AnimationKey, Animation*>(name, newAnimation));
}

void AnimationManager::removeAnimation(const AnimationKey& key)
{
	std::map<AnimationKey, Animation*>::iterator iter = mpAnimations.find(key);

	if (iter != mpAnimations.end())
	{
		delete iter->second;
		mpAnimations.erase(iter);
	}
}

Animation* AnimationManager::getAnimation(const AnimationKey& key)
{
	std::map<AnimationKey, Animation*>::const_iterator iter = mpAnimations.find(key);

	if (iter != mpAnimations.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}

void AnimationManager::updateAnimations()
{
	std::map<AnimationKey, Animation*>::const_iterator iter;

	for (iter = mpAnimations.begin(); iter != mpAnimations.end(); ++iter)
	{
		iter->second->update();
	}
}

void AnimationManager::clearList()
{
	std::map<AnimationKey, Animation*>::iterator iter;

	for (iter = mpAnimations.begin(); iter != mpAnimations.end(); ++iter)
	{
		Animation* pTmpBuffer = iter->second;
		delete pTmpBuffer;
	}

	mpAnimations.clear();
}