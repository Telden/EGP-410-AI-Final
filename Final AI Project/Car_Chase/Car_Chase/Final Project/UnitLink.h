#pragma once

#ifndef UNITLINK_H
#define UNITLINK_H

#include "Unit.h"

class UnitLink : public Unit
{
	private :
		bool mCanShield, mCanSword, mCanBow;
		int mMaxHealth, mCurrentHealth;
		int mMovementSpeed;
		std::string mDirectionFacing;

	public :
		UnitLink(int numHearts, int speedAKApixelsPerFrame, bool canShield, bool canSword, bool canBow)
		~UnitLink();

		bool getCanShield() { return mCanShield; }
		bool getCanSword() { return mCanSword; }
		bool getCanBow() { return mCanBow; }
		int getMaxHealth() { return mMaxHealth; }
		int getCurrentHealth() { return mCurrentHealth; }
		int getMovementSpeed() { return mMovementSpeed; }

		void render();
		void update();

		void handleEvent(const Event& theEvent);
};

#endif