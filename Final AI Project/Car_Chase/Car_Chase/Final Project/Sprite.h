#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "Trackable.h"

class Sprite: public Trackable
{
	friend class GraphicsSystem;
	friend class GraphicsBuffer;

private:
	GraphicsBuffer* mp_SpriteBuffer = NULL;
	int mLocX;
	int mLocY;
	int mSWidth;
	int mSHeight;
public:
	Sprite();
	Sprite(GraphicsBuffer &bufferObj, int locationX, int locationY, int width, int height);
	~Sprite();
	
	
	int getLocX();
	int getLocY();
	int getWidth();
	int getHeight();
	GraphicsBuffer* getBuffer();

};


#endif