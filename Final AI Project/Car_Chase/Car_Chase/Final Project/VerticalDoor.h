#pragma once
#ifndef VERTICALDOOR_H
#define VERTICALDOOR_H

#include "Unit.h"

class SpecialDoorUnlockComponent;

class VerticalDoor :public Unit
{
	const std::string VERTDOORANIMNAME = "VerticalDoor";
	int mClosedDoorSprite;
	int mOpenDoorSprite;
	int mSpecialDoorSprite;
	bool mIsSpecial;
	bool mIsOpen;

	SpecialDoorUnlockComponent* mpSpecialDoorUnlockComponent;

public:
	VerticalDoor(int locX, int locY, int openDoorNum, int closedDoor, int sspecialDoorNum, bool isOpen, bool isSpecial);
	~VerticalDoor();

	int getClosedDoorSpite() { return mClosedDoorSprite; }
	int getOpenDoorSprite() { return mOpenDoorSprite; }
	int getSpecialDoorSprite() { return mSpecialDoorSprite; }

	bool getIsOpen();
	void setIsOpen(bool isOpen) { mIsOpen = isOpen; }
	bool getIsSpecial() { return mIsSpecial; }
	void render();
	void update();
};


#endif 
