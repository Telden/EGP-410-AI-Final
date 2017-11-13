#pragma once
#ifndef HORIZONTALDOOR_H
#define HORIZONTALDOOR_H

#include "Unit.h"

class SpecialDoorUnlockComponent;

class HorizontalDoor : public Unit
{
	private:
		const std::string HORIZDOORANIMNAME = "HorizontalDoor";

		int mClosedDoorSprite;
		int mOpenDoorSprite;
		int mSpecialDoorSprite;
		bool mIsSpecial;
		bool mIsOpen;

		SpecialDoorUnlockComponent* mpSpecialDoorUnlockComponent;

	public:
		HorizontalDoor(int locX, int locY, int openDoorNum, int closedDoorNum, int specialDoorNum, bool isOpen, bool isSpecial);
		~HorizontalDoor();

		int getClosedDoorSpite() { return mClosedDoorSprite; }
		int getOpenDoorSprite() { return mOpenDoorSprite; }
		int getSpecialDoorSprite() { return mSpecialDoorSprite; }

		void setIsOpen(bool isOpen) { mIsOpen = isOpen; }
		bool getIsOpen();
		bool getIsSpecial() { return mIsSpecial; }
		void render();
		void update();
};
#endif