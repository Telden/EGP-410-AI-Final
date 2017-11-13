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
	/* [ARROW] */
		/* 0: Up arrow || 1: Right Arrow || 2: Down Arrow || 3: Left Arrow */
	GraphicsBuffer* tempPath = mp_GBM->getBuffer("Arrow");

	Animation* tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	addAnimation("ArrowUp", tempAnim);

	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 16, 5, 16, 16));
	addAnimation("ArrowRight", tempAnim);

	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 32, 0, 16, 16));
	addAnimation("ArrowDown", tempAnim);

	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 48, 6, 16, 16));
	addAnimation("ArrowLeft", tempAnim);

	/* [DUNGEON BACKGROUND] */
	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*mp_GBM->getBuffer("DungeonBackground"), 0, 0, 240, 160));
	addAnimation("DungeonBackground", tempAnim);

	/* [HORIZONTAL DOORS] */
		/* 0: Right Open || 1: Left Open || 2: Right Closed || 3: Left Closed */
	tempAnim = new Animation(6, 0);
	tempPath = mp_GBM->getBuffer("HorizontalDoor");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 32, 20));
	tempAnim->addSprite(Sprite(*tempPath, 20, 0, 32, 20));
	tempAnim->addSprite(Sprite(*tempPath, 40, 0, 32, 20));
	tempAnim->addSprite(Sprite(*tempPath, 60, 0, 32, 20));
	tempAnim->addSprite(Sprite(*tempPath, 80, 0, 32, 20));
	tempAnim->addSprite(Sprite(*tempPath, 100, 0, 32, 20));
	addAnimation("HorizontalDoor", tempAnim);

	/* [VERTICAL DOORS] */
		/* 0: Top Open || 1: Bottom Open || 2: Top Closed || 3: Bottom Closed */
	tempAnim = new Animation(6, 0);
	tempPath = mp_GBM->getBuffer("VerticalDoor");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 20, 32));
	tempAnim->addSprite(Sprite(*tempPath, 32, 0, 20, 32));
	tempAnim->addSprite(Sprite(*tempPath, 64, 0, 20, 32));
	tempAnim->addSprite(Sprite(*tempPath, 96, 0, 20, 32));
	tempAnim->addSprite(Sprite(*tempPath, 128, 0, 20, 32));
	tempAnim->addSprite(Sprite(*tempPath, 160, 0, 20, 32));
	addAnimation("VerticalDoor", tempAnim);

	/* [DUNGEON TILES] */
		/* 0: Floor Tile || 1: Right-Facing Statue || 2: Left-Facing Statue || 3: Block || 4: Sand ||*/
	tempAnim = new Animation(8, 0);
	tempPath = mp_GBM->getBuffer("Tiles");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 32, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 48, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 64, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 80, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 96, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 112, 0, 16, 16));
	addAnimation("Tiles", tempAnim);

	/* [KESE] */
		/* 0: Open Wings || 1: Closed Wings */
	tempAnim = new Animation(2, 5);
	tempPath = mp_GBM->getBuffer("Kese");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 8, 16));
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 8, 16));
	addAnimation("Kese", tempAnim);

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

	/* [STALFOS] */
		/* 0: Left Foot || 1: Left Foot */
	tempAnim = new Animation(2, 20);
	tempPath = mp_GBM->getBuffer("Stalfos");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 16, 16));
	addAnimation("Stalfos", tempAnim);

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

	/* [TREASURES] */
		/*
		   0: Orange Triangle || 1: Blue Triangle 
		   2: Red Heart || 3: Blue Heart || 4: Half Heart || 5: Empty Heart
		   6: Key || 7: Bow 
		*/
	tempAnim = new Animation(8, 0);
	tempPath = mp_GBM->getBuffer("Treasures");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 32, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 48, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 64, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 80, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 96, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 112, 0, 16, 16));
	addAnimation("Treasures", tempAnim);

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

	//Gel Animation
	tempAnim = new Animation(2, 20);
	tempPath = mp_GBM->getBuffer("Gel");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 9, 8));
	tempAnim->addSprite(Sprite(*tempPath, 8, 0, 9, 8));
	addAnimation("Gel", tempAnim);

	//Dragon Animation
	tempAnim = new Animation(4, 20);
	tempPath = mp_GBM->getBuffer("Dragon");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 32, 24));
	tempAnim->addSprite(Sprite(*tempPath, 24, 0, 32, 24));
	tempAnim->addSprite(Sprite(*tempPath, 48, 0, 32, 24));
	tempAnim->addSprite(Sprite(*tempPath, 72, 0, 32, 24));
	addAnimation("Dragon", tempAnim);

	//FireBall Animation
	tempAnim = new Animation(2, 5);
	tempPath = mp_GBM->getBuffer("Fireball");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 10, 8));
	tempAnim->addSprite(Sprite(*tempPath, 8, 0, 10, 8));
	addAnimation("Fireball", tempAnim);

	//PeahatAnimaiton
	tempAnim = new Animation(2, 10);
	tempPath = mp_GBM->getBuffer("Peahat");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 16, 16));
	addAnimation("Peahat", tempAnim);

	//Papa Smurf animation
	tempAnim = new Animation(2, 10);
	tempPath = mp_GBM->getBuffer("PapaSmurf");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 48, 112));
	tempAnim->addSprite(Sprite(*tempPath, 112, 0, 48, 112));
	addAnimation("PapaSmurf", tempAnim);

	//Difficulty for the menu
	tempAnim = new Animation(3, 0);
	tempPath = mp_GBM->getBuffer("Difficulty");
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 23, 45));
	tempAnim->addSprite(Sprite(*tempPath, 45, 0, 23, 45));
	tempAnim->addSprite(Sprite(*tempPath, 90, 0, 23, 45));
	addAnimation("Difficulty", tempAnim);

	/*tempPath = mp_GBM->getBuffer("Sword");
	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 0, 0, 16, 16));
	addAnimation("SwordUp", tempAnim);

	tempAnim = new Animation(1, 0);
	tempAnim->addSprite(Sprite(*tempPath, 16, 0, 16, 16));
	addAnimation("SwordDown", tempAnim);*/

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