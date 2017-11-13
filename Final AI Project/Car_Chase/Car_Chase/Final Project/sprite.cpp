#include "Sprite.h"
#include "GraphicsBuffer.h"

//Default Constructor
Sprite::Sprite()
{
	mp_SpriteBuffer = NULL;
	mLocX = 0;
	mLocY = 0;
	mSWidth = 0;
	mSHeight = 0;
}

//Overloaded constructor that points to a buffer object's file path, and takes custom location along with sprite widths and heights 
Sprite::Sprite(GraphicsBuffer &bufferObj, int locationX, int locationY, int width, int height)
{
	mp_SpriteBuffer = &bufferObj;
	mLocX = locationX;
	mLocY = locationY;
	mSWidth = width;
	mSHeight = height;
}

//Resets the pointer pointing to the graphics buffer object to NULL
Sprite::~Sprite()
{
	mp_SpriteBuffer = NULL;
}

//returns the custom location X
int Sprite::getLocX()
{
	return(mLocX);
}

//returns the custom location Y
int Sprite::getLocY()
{
	return(mLocY);
}

//Returns the sprite width
int Sprite::getWidth()
{
	return(mSWidth);
}

//returns the sprite height
int Sprite::getHeight()
{
	return (mSHeight);
}


GraphicsBuffer* Sprite::getBuffer()
{
	return mp_SpriteBuffer;
}
