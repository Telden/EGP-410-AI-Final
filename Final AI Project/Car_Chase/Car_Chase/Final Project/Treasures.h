#pragma once
#ifndef TREASURES_H
#define TREASURES_H

#include "Unit.h"
class PickupComponent;

class Treasure : public Unit
{
private:
	const std::string TREASUREANIMNAME = "Treasures";
	int mSpriteNum;
	std::string mTag;
	PickupComponent* mpPickupComponent;

public:
	Treasure(std::string tagID, int locX, int LocY, int animNum);
	~Treasure();

	int getSpriteNum() { return mSpriteNum; }
	std::string getTag() { return mTag; }
	void render();
	void update();
};



#endif