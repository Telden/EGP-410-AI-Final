#include "AquamentusComponent.h"
#include "Unit.h"
#include "GraphicsSystem.h"
#include "AnimationManager.h"
#include "Fireball.h"
#include "Game.h"
#include "LevelManager.h"

//Initialize the Aquamentus 
AquamentusComponent::AquamentusComponent(Unit* myUnit)
{
	mpMyUnit = myUnit;
	mHealth = mMaxHealth;

	mpFireball1 = new Fireball(-128, -128);
	mpFireball1->setAnimation(*mpMyUnit->getAnimationManager()->getAnimation("Fireball"));
	mpFireball2 = new Fireball(-128, -128);
	mpFireball2->setAnimation(*mpMyUnit->getAnimationManager()->getAnimation("Fireball"));
	mpFireball3 = new Fireball(-128, -128);
	mpFireball3->setAnimation(*mpMyUnit->getAnimationManager()->getAnimation("Fireball"));

	resetFireballs();
}

//Clean up the fireballs
AquamentusComponent::~AquamentusComponent()
{
	delete mpFireball1;
	delete mpFireball2;
	delete mpFireball3;
}

//Render the fireballs
void AquamentusComponent::render()
{
	mpFireball1->render();
	mpFireball2->render();
	mpFireball3->render();
}


void AquamentusComponent::update()
{
	//If the player hits the Aquamentus with a sword or arrow, damage it
	if (Game::getInstance()->getLevelManager()->checkCollisionWithSword(mpMyUnit) || Game::getInstance()->getLevelManager()->checkCollisionWithArrow(mpMyUnit))
	{
		if (!mJustHurt)
		{
			std::cout << "boss hit\n";
			gpEventSystem->fireEvent(PlayAudioEvent("BossHit"));
			mHealth--;
			mJustHurt = true;
		}
	}

	if (mJustHurt)
	{
		if (mHurtCounter < mMaxHurtCounter)
		{
			mHurtCounter++;
		}
		else
		{
			mJustHurt = false;
			mHurtCounter = 0;
		}
	}

	changeDirections();
	movement();
	moveFireballs();
	checkHealth();

	mpFireball1->update();
	mpFireball2->update();
	mpFireball3->update();
}

void AquamentusComponent::handleEvent(const Event& theEvent)
{

}

//Move the Aquamentus back and forth
void AquamentusComponent::changeDirections()
{
	if (mMovCounter < mMaxMovCounter)
	{
		mMovCounter++;
	}
	else
	{
		mMovingLeft = !mMovingLeft;
		mMovCounter = 0;
	}
}

//Aquamentus movement
void AquamentusComponent::movement()
{
	if (mMovingLeft)
	{
		mpMyUnit->setLocX(mpMyUnit->getLocX() - mMovementSpeed);
	}
	else
	{
		mpMyUnit->setLocX(mpMyUnit->getLocX() + mMovementSpeed);
	}
}

//Update and move the fireball posisions
void AquamentusComponent::moveFireballs()
{
	if (mShootCounter < mMaxShootCounter)
	{
		mpFireball1->setLocX(mpFireball1->getLocX() - 4);
		mpFireball2->setLocX(mpFireball2->getLocX() - 4);
		mpFireball3->setLocX(mpFireball3->getLocX() - 4);
		mShootCounter++;
	}
	else
	{
		mShootTopDown = !mShootTopDown;
		mShootCounter = 0;
		resetFireballs();
	}
}

//Reset the fireballs when they go far enough off the screen
void AquamentusComponent::resetFireballs()
{
	if (mShootTopDown)
	{
		std::cout << "reset to topdown\n";
		mpFireball1->setLocX(mpMyUnit->getLocX() - 128);
		mpFireball1->setLocY(mpMyUnit->getLocY() - 96);

		mpFireball2->setLocX(mpMyUnit->getLocX());
		mpFireball2->setLocY(mpMyUnit->getLocY() + 32);

		mpFireball3->setLocX(mpMyUnit->getLocX() + 128);
		mpFireball3->setLocY(mpMyUnit->getLocY() + 160);
	}
	else
	{
		std::cout << "reset to bottomup\n";
		mpFireball1->setLocX(mpMyUnit->getLocX() + 128);
		mpFireball1->setLocY(mpMyUnit->getLocY() - 96);

		mpFireball2->setLocX(mpMyUnit->getLocX());
		mpFireball2->setLocY(mpMyUnit->getLocY() + 32);

		mpFireball3->setLocX(mpMyUnit->getLocX() - 128);
		mpFireball3->setLocY(mpMyUnit->getLocY() + 160);
	}
}

//Check if the Aquamentus is dead
void AquamentusComponent::checkHealth()
{
	if (mHealth == 0)
	{
		gpEventSystem->fireEvent(PlayAudioEvent("BossDies"));
		gpEventSystem->fireEvent(BOSS_DEFEATED_EVENT);
		mpMyUnit->setIsActive(false);
	}
}