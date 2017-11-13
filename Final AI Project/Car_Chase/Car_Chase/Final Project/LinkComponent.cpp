#include "LinkComponent.h"
#include "Unit.h"
#include "GraphicsSystem.h"
#include "AnimationManager.h"
#include "Event.h"


LinkComponent::LinkComponent(Unit* myUnit, int numHearts, int speedAKApixelsPerFrame, int arrowSpeed, bool canSword, bool canBow)
{
	// assigning the unit
	mpMyUnit = myUnit;

	// set the health
	mMaxHealth = numHearts;
	mCurrentHealth = numHearts;

	// set the movement speed, also known as the number of pixels to move Link per frame
	mMovementSpeed = speedAKApixelsPerFrame;
	mArrowSpeed = arrowSpeed;

	// set whether or not Link can use his abilities
	mCanSword = canSword;
	mCanBow = canBow;

	// set the direction is facing by default
	mDirectionFacing = "up";
	mDirectionArrow = "up";

	// making the sword and arrow
	mpSword = new Unit(-128, -128);
	mpArrow = new Unit(-128, -128);

	mpSword->setAnimation(*mpMyUnit->getAnimationManager()->getAnimation("SwordUp"));

	// why do I have to do this twice? units, plz
	mpSword->setLocX(-128);
	mpSword->setLocY(-128);
	mpArrow->setLocX(-128);
	mpArrow->setLocY(-128);

	// initialize Animation pointers
	mpUpMovement = Game::getInstance()->getAnimationManager()->getAnimation(LINKUPANIMNAME);
	mpDownMovement = Game::getInstance()->getAnimationManager()->getAnimation(LINKDOWNANIMNAME);
	mpLeftMovement = Game::getInstance()->getAnimationManager()->getAnimation(LINKLEFTANIMNAME);
	mpRightMovement = Game::getInstance()->getAnimationManager()->getAnimation(LINKRIGHTANIMNAME);
	mpCurrentAnimation = mpUpMovement;

	mpSwordUp = Game::getInstance()->getAnimationManager()->getAnimation(SWORDUPANIMNAME);
	mpSwordDown = Game::getInstance()->getAnimationManager()->getAnimation(SWORDDOWNANIMNAME);
	mpSwordLeft = Game::getInstance()->getAnimationManager()->getAnimation(SWORDLEFTANIMNAME);
	mpSwordRight = Game::getInstance()->getAnimationManager()->getAnimation(SWORDRIGHTANIMNAME);

	mpArrowUp = Game::getInstance()->getAnimationManager()->getAnimation(ARROWUPANIMNAME);
	mpArrowDown = Game::getInstance()->getAnimationManager()->getAnimation(ARROWDOWNANIMNAME);
	mpArrowLeft = Game::getInstance()->getAnimationManager()->getAnimation(ARROWLEFTANIMNAME);
	mpArrowRight = Game::getInstance()->getAnimationManager()->getAnimation(ARROWRIGHTANIMNAME);

	// set the Unit's current animation
	mpMyUnit->setAnimation(*mpCurrentAnimation);

	// add listeners
	gpEventSystem->addListener(MOVEMENT_EVENT_UP, this);
	gpEventSystem->addListener(MOVEMENT_EVENT_DOWN, this);
	gpEventSystem->addListener(MOVEMENT_EVENT_LEFT, this);
	gpEventSystem->addListener(MOVEMENT_EVENT_RIGHT, this);

	gpEventSystem->addListener(ATTACK_EVENT_PRIMARY, this);
	gpEventSystem->addListener(ATTACK_EVENT_SECONDARY, this);

	gpEventSystem->addListener(HURT_PLAYER_EVENT, this);
	gpEventSystem->addListener(PICKUP_KEY_EVENT, this);
	gpEventSystem->addListener(PICKUP_BOW_EVENT, this);
	gpEventSystem->addListener(RESET_GAME_EVENT, this);
	gpEventSystem->addListener(OPEN_DOOR_EVENT, this);
} 

LinkComponent::LinkComponent(Unit* myUnit, int numKey, int currentHearts, int maxHearts, std::string direction, bool canBow)
{
	mpMyUnit = myUnit;
	mNumKeys = numKey;
	mCurrentHealth = currentHearts;
	mMaxHealth = maxHearts;
	mMovementSpeed = 4;
	mArrowSpeed = 8;
	mDirectionFacing = direction;

	mDirectionArrow = "up";

	// making the sword and arrow
	mpSword = new Unit(-128, -128);
	mpArrow = new Unit(-128, -128);

	mpSword->setAnimation(*mpMyUnit->getAnimationManager()->getAnimation("SwordUp"));

	// why do I have to do this twice? units, plz
	mpSword->setLocX(-128);
	mpSword->setLocY(-128);
	mpArrow->setLocX(-128);
	mpArrow->setLocY(-128);

	// initialize Animation pointers
	mpUpMovement = Game::getInstance()->getAnimationManager()->getAnimation(LINKUPANIMNAME);
	mpDownMovement = Game::getInstance()->getAnimationManager()->getAnimation(LINKDOWNANIMNAME);
	mpLeftMovement = Game::getInstance()->getAnimationManager()->getAnimation(LINKLEFTANIMNAME);
	mpRightMovement = Game::getInstance()->getAnimationManager()->getAnimation(LINKRIGHTANIMNAME);
	mpCurrentAnimation = mpUpMovement;

	mpSwordUp = Game::getInstance()->getAnimationManager()->getAnimation(SWORDUPANIMNAME);
	mpSwordDown = Game::getInstance()->getAnimationManager()->getAnimation(SWORDDOWNANIMNAME);
	mpSwordLeft = Game::getInstance()->getAnimationManager()->getAnimation(SWORDLEFTANIMNAME);
	mpSwordRight = Game::getInstance()->getAnimationManager()->getAnimation(SWORDRIGHTANIMNAME);

	mpArrowUp = Game::getInstance()->getAnimationManager()->getAnimation(ARROWUPANIMNAME);
	mpArrowDown = Game::getInstance()->getAnimationManager()->getAnimation(ARROWDOWNANIMNAME);
	mpArrowLeft = Game::getInstance()->getAnimationManager()->getAnimation(ARROWLEFTANIMNAME);
	mpArrowRight = Game::getInstance()->getAnimationManager()->getAnimation(ARROWRIGHTANIMNAME);

	// set the Unit's current animation
	mpMyUnit->setAnimation(*mpCurrentAnimation);

	// add listeners
	gpEventSystem->addListener(MOVEMENT_EVENT_UP, this);
	gpEventSystem->addListener(MOVEMENT_EVENT_DOWN, this);
	gpEventSystem->addListener(MOVEMENT_EVENT_LEFT, this);
	gpEventSystem->addListener(MOVEMENT_EVENT_RIGHT, this);

	gpEventSystem->addListener(ATTACK_EVENT_PRIMARY, this);
	gpEventSystem->addListener(ATTACK_EVENT_SECONDARY, this);

	gpEventSystem->addListener(HURT_PLAYER_EVENT, this);
	gpEventSystem->addListener(PICKUP_KEY_EVENT, this);
	gpEventSystem->addListener(PICKUP_BOW_EVENT, this);
	gpEventSystem->addListener(RESET_GAME_EVENT, this);
	gpEventSystem->addListener(OPEN_DOOR_EVENT, this);
}

LinkComponent::~LinkComponent()
{
	delete mpSword;
	delete mpArrow;

	gpEventSystem->removeListenerFromAllEvents(this);
}

void LinkComponent::render()
{
	// render the sword
	mpMyUnit->getGraphicsSystem()->drawSprite(mpSword->getAnimation().getSprite(mpSword->getAnimation().getCurrentSprite()), mpSword->getLocX(), mpSword->getLocY());

	// render the arrow
	mpMyUnit->getGraphicsSystem()->drawSprite(mpArrow->getAnimation().getSprite(mpArrow->getAnimation().getCurrentSprite()), mpArrow->getLocX(), mpArrow->getLocY());

	// render the current animation
	mpMyUnit->getGraphicsSystem()->drawSprite(mpCurrentAnimation->getSprite(mpCurrentAnimation->getCurrentSprite()), mpMyUnit->getLocX(), mpMyUnit->getLocY());

	// rendering Link, set the current animation depending on the current direction
	if (!mIsAttacking)
	{
		// walk/idle animations
		if (mDirectionFacing == "up")
		{
			mpCurrentAnimation = mpUpMovement;
		}
		if (mDirectionFacing == "down")
		{
			mpCurrentAnimation = mpDownMovement;
		}
		if (mDirectionFacing == "left")
		{
			mpCurrentAnimation = mpLeftMovement;
		}
		if (mDirectionFacing == "right")
		{
			mpCurrentAnimation = mpRightMovement;
		}
	}
	else
	{
		// attack animations
		if (mDirectionFacing == "up")
		{
			mpCurrentAnimation = mpMyUnit->getAnimationManager()->getAnimation("LinkAttackUp");
		}
		if (mDirectionFacing == "down")
		{
			mpCurrentAnimation = mpMyUnit->getAnimationManager()->getAnimation("LinkAttackDown");
		}
		if (mDirectionFacing == "left")
		{
			mpCurrentAnimation = mpMyUnit->getAnimationManager()->getAnimation("LinkAttackLeft");
		}
		if (mDirectionFacing == "right")
		{
			mpCurrentAnimation = mpMyUnit->getAnimationManager()->getAnimation("LinkAttackRight");
		}
	}
}

void LinkComponent::update()
{
	//UpdateUIEvent(bool mCanSword, bool mCanBow, int mCurrentHealth, int mKeys)

	// update the current animation
	mpMyUnit->setAnimation(*mpCurrentAnimation);

	// collision with doors
	useDoors();

	// move the arrow based on the current arrow direction
	if (mDirectionArrow == "up")
	{
		mpArrow->setLocY(mpArrow->getLocY() - mArrowSpeed);
		mpArrow->setAnimation(*mpArrowUp);
	}
	if (mDirectionArrow == "down")
	{
		mpArrow->setLocY(mpArrow->getLocY() + mArrowSpeed);
		mpArrow->setAnimation(*mpArrowDown);
	}
	if (mDirectionArrow == "left")
	{
		mpArrow->setLocX(mpArrow->getLocX() - mArrowSpeed);
		mpArrow->setAnimation(*mpArrowLeft);
	}
	if (mDirectionArrow == "right")
	{
		mpArrow->setLocX(mpArrow->getLocX() + mArrowSpeed);
		mpArrow->setAnimation(*mpArrowRight);
	}

	if (mIsAttacking)
	{
		resetSword();
	}
	resetBow();

	// direction of the sword
	if (mDirectionFacing == "up")
	{
		mpSword->setAnimation(*mpSwordUp);
	}
	if (mDirectionFacing == "down")
	{
		mpSword->setAnimation(*mpSwordDown);
	}
	if (mDirectionFacing == "left")
	{
		mpSword->setAnimation(*mpSwordLeft);
	}
	if (mDirectionFacing == "right")
	{
		mpSword->setAnimation(*mpSwordRight);
	}

	// temporary invicibility
	if (mJustHurt)
	{
		if (mHurtCount < mMaxHurtCount)
		{
			mHurtCount++;
		}
		else
		{
			mHurtCount = 0;
			mJustHurt = false;
		}
	}
}

void LinkComponent::handleEvent(const Event& theEvent)
{
	// using the sword
	if (theEvent.getType() == ATTACK_EVENT_PRIMARY)
	{
		gpEventSystem->fireEvent(PlayAudioEvent("Attack"));

		mIsAttacking = true;

		if (mDirectionFacing == "up")
		{
			mpSword->setLocX(mpMyUnit->getLocX() - 8);
			mpSword->setLocY(mpMyUnit->getLocY() - 48);
		}
		if (mDirectionFacing == "down")
		{
			mpSword->setLocX(mpMyUnit->getLocX() + 8);
			mpSword->setLocY(mpMyUnit->getLocY() + 48);
		}
		if (mDirectionFacing == "left")
		{
			mpSword->setLocX(mpMyUnit->getLocX() - 48);
			mpSword->setLocY(mpMyUnit->getLocY() + 8);
		}
		if (mDirectionFacing == "right")
		{
			mpSword->setLocX(mpMyUnit->getLocX() + 48);
			mpSword->setLocY(mpMyUnit->getLocY() + 8);
		}
		mpCurrentAnimation->update();
		
	}

	if (!mIsAttacking)
	{
		// movement
		if (theEvent.getType() == MOVEMENT_EVENT_UP)
		{
			mDirectionFacing = "up";
			if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 0, -1 * mMovementSpeed))
			{
				mpMyUnit->setLocY(mpMyUnit->getLocY() - mMovementSpeed);
			}
			mpCurrentAnimation->update();
		}
		if (theEvent.getType() == MOVEMENT_EVENT_DOWN)
		{
			mDirectionFacing = "down";
			if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, 0, mMovementSpeed))
			{
				mpMyUnit->setLocY(mpMyUnit->getLocY() + mMovementSpeed);
			}
			mpCurrentAnimation->update();
		}
		if (theEvent.getType() == MOVEMENT_EVENT_LEFT)
		{
			mDirectionFacing = "left";
			if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, -1 * mMovementSpeed, 0))
			{
				mpMyUnit->setLocX(mpMyUnit->getLocX() - mMovementSpeed);
			}
			mpCurrentAnimation->update();
		}
		if (theEvent.getType() == MOVEMENT_EVENT_RIGHT)
		{
			mDirectionFacing = "right";
			if (!Game::getInstance()->getLevelManager()->checkCollisionWithWalls(mpMyUnit, mMovementSpeed, 0))
			{
				mpMyUnit->setLocX(mpMyUnit->getLocX() + mMovementSpeed);
			}
			mpCurrentAnimation->update();
		}
	}

	// using the bow
	if (theEvent.getType() == ATTACK_EVENT_SECONDARY && mCanBow)
	{
		// only fire the bow if one is not already being fired
		if (!mJustFired)
		{
			mDirectionArrow = mDirectionFacing;
			mpArrow->setLocX(mpMyUnit->getLocX());
			mpArrow->setLocY(mpMyUnit->getLocY());
			mJustFired = true;
		}
	}

	// getting hurt
	if (theEvent.getType() == HURT_PLAYER_EVENT)
	{
		if (!mJustHurt)
		{
			//AudioSystem::getInstance()->playSound("Link_Hurt");
			gpEventSystem->fireEvent(PlayAudioEvent("Link_Hurt"));
			std::cout << "hit\n";
			mCurrentHealth--;
			mJustHurt = true;
		}
		if (mCurrentHealth == 0)
		{
			//AudioSystem::getInstance()->playSound("Link_Died");
			gpEventSystem->fireEvent(PlayAudioEvent("Link_Died"));
			gpEventSystem->fireEvent(STOP_MUSIC_EVENT);
			gpEventSystem->fireEvent(LINK_DEATH_EVENT);
		}
	}
	 
	// pick up a key
	if (theEvent.getType() == PICKUP_KEY_EVENT)
	{
		mNumKeys++;
	}

	// collect the bow
	else if (theEvent.getType() == PICKUP_BOW_EVENT)
	{
		mCanBow = true;
	}

	// reset the game
	else if (theEvent.getType() == RESET_GAME_EVENT)
	{
		mCurrentHealth = mMaxHealth;
		mNumKeys = 0;
	}

	// open a door
	if (theEvent.getType() == OPEN_DOOR_EVENT)
	{
		mNumKeys--;
	}
}

void LinkComponent::useDoors()
{
	//Checking For Doors
	if (Game::getInstance()->getLevelManager()->checkCollisionWithDoors(mpMyUnit, mpMyUnit->getLocX(), mpMyUnit->getLocY()))
	{
		// set Link's position carefull so he doesn't end up in walls
		if (mpMyUnit->getLocX() < 80)
		{
			gpEventSystem->fireEvent(LOAD_LEFT_LEVEL);
			mpMyUnit->setLocX(800); mpMyUnit->setLocY(288);
		}

		if (mpMyUnit->getLocX() > 860)
		{
			gpEventSystem->fireEvent(LOAD_RIGHT_LEVEL);
			mpMyUnit->setLocX(96); mpMyUnit->setLocY(288);
		}

		if (mpMyUnit->getLocY() > 530)
		{
			gpEventSystem->fireEvent(LOAD_LOWER_LEVEL);
			mpMyUnit->setLocX(436); mpMyUnit->setLocY(96);
		}

		if (mpMyUnit->getLocY() < 70)
		{
			gpEventSystem->fireEvent(LOAD_UPPER_LEVEL);
			mpMyUnit->setLocX(436); mpMyUnit->setLocY(520);
		}

	}
}

void LinkComponent::resetSword()
{
	// make Link stop attacking
	if (mIsAttacking)
	{
		mFrameCounter++;

		if (mFrameCounter >= mFramesToWaitForSword)
		{
			mIsAttacking = false;

			mpSword->setLocX(-64);
			mpSword->setLocY(-64);

			mFrameCounter = 0;
		}
	}
}

void LinkComponent::resetBow()
{
	// call this when the arrow leaves the screen
	if (mpArrow->getLocX() < 0 || mpArrow->getLocX() > 1000 || mpArrow->getLocY() < 0 || mpArrow->getLocY() > 900)
	{
		mpArrow->setLocX(-128);
		mpArrow->setLocY(-128);
		mJustFired = false;
	}
}