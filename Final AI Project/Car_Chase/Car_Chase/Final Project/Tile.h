#pragma once
#ifndef TILE_H
#define TILE_H

#include "Unit.h"

class WallComponent;

class Tile : public Unit
{
private:
	const std::string TILEANIMNAME = "Tiles";
	int mSpriteNum;
	WallComponent* mpWallComponent;

public:
	Tile(int locX, int LocY, int animNum);
	~Tile();

	void render();
	void update();

	int getSpriteNum() { return mSpriteNum; }
};


#endif