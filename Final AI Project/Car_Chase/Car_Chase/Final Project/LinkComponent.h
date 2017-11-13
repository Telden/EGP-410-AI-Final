#pragma once

#ifndef LINKCOMPONENT_H
#define LINKCOMPONENT_H

#include "Component.h"
#include "Animation.h"

class Unit;
class Animation;

class LinkComponent : public Component
{
	private :
		// the unit this component refers to
		Unit* mpMyUnit;

		// Link's sword and arrow
		Unit* mpSword;
		Unit* mpArrow;
		 
		// timers for sword and arrow
		int mFramesToWaitForSword = 20;
		int mFrameCounter = 0;

		// if Link is stuck using his sword or not
		bool mIsAttacking;

		// if Link has just been hit
		bool mJustHurt;
		int mHurtCount = 0, mMaxHurtCount = 120;

		// the direction Link was facing when Link fired the arrow
		std::string mDirectionArrow;

		// if Link has just fired an arrow
		bool mJustFired;

		// bools for whether or not Link can use his abilities
		bool mCanSword, mCanBow;
		//Keys
		int mNumKeys = 0;
		// health
		int mMaxHealth, mCurrentHealth;

		// the movement speed
		int mMovementSpeed, mArrowSpeed;
		
		// the direction Link is facing
		std::string mDirectionFacing;

		//Links Movement Animation
		Animation* mpUpMovement;
		Animation* mpDownMovement;
		Animation* mpLeftMovement; 
		Animation* mpRightMovement;
		Animation* mpCurrentAnimation;

		Animation* mpSwordUp;
		Animation* mpSwordDown;
		Animation* mpSwordLeft;
		Animation* mpSwordRight;

		Animation* mpArrowUp;
		Animation* mpArrowDown;
		Animation* mpArrowLeft;
		Animation* mpArrowRight;

		//Animation Namepaths
		const std::string LINKUPANIMNAME = "LinkMoveUp";
		const std::string LINKDOWNANIMNAME = "LinkMoveDown";
		const std::string LINKLEFTANIMNAME = "LinkMoveLeft";
		const std::string LINKRIGHTANIMNAME = "LinkMoveRight";

		const std::string SWORDUPANIMNAME = "SwordUp";
		const std::string SWORDDOWNANIMNAME = "SwordDown";
		const std::string SWORDLEFTANIMNAME = "SwordLeft";
		const std::string SWORDRIGHTANIMNAME = "SwordRight";

		const std::string ARROWUPANIMNAME = "ArrowUp";
		const std::string ARROWDOWNANIMNAME = "ArrowDown";
		const std::string ARROWLEFTANIMNAME = "ArrowLeft";
		const std::string ARROWRIGHTANIMNAME = "ArrowRight";

	public :
		LinkComponent(Unit* myUnit, int numHearts, int speedAKApixelsPerFrame, int arrowSpeed, bool canSword, bool canBow);
		LinkComponent(Unit* myUnit, int numKey, int currentHearts, int maxHearts, std::string direction, bool canBow);
		~LinkComponent();

		bool getCanSword() { return mCanSword; }
		bool getCanBow() { return mCanBow; }
		int getMaxHealth() { return mMaxHealth; }
		int getCurrentHealth() { return mCurrentHealth; }
		int getMovementSpeed() { return mMovementSpeed; }
		int getnumKeys() { return mNumKeys; }

		void render();
		void update();

		void handleEvent(const Event& theEvent);

		void resetSword();
		void resetBow();
		void useDoors();

		Unit* getMyUnit() { return mpMyUnit; }
		Unit* getSword() { return mpSword; }
		Unit* getArrow() { return mpArrow; }

		void setnumKeys(int numKeys) { mNumKeys = numKeys; }
		void setCurrentKey(int currentHealth) { mCurrentHealth = currentHealth; }
		void setMaxHealth(int maxHealth) { mMaxHealth = maxHealth; }
		void setCanBow(bool canBow) { mCanBow = canBow; }
		std::string getDirectionFacing() { return mDirectionFacing; }
};

#endif