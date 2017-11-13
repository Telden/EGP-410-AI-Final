#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include "Unit.h"

class Block : public Unit
{
private:
	const std::string BLOCKANIMNAME = "Tiles";
	int mSpriteNum;

public:
	Block(int locX, int LocY, int animNum);
	~Block();
	
	void render();
	void update();

	int getSpriteNum() { return mSpriteNum; }
};


#endif