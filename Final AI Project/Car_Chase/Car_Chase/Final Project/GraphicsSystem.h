#pragma once
#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include "Trackable.h"
#include "SDL_Lib.h"

#include <string>

class Font;
class Color;
class GraphicsBuffer;

class GraphicsSystem: public Trackable
{
	friend class Sprite;
	friend class Game;
private:
	SDL_Window *mpDisplay;
	SDL_Renderer *mpRenderer;
	//SDL_Renderer *mpBlackBG;
	//SDL_Surface *mpBackground;
	SDL_Texture *mpTexture;
	int mHeight;
	int mWidth;
	int mScalar;
public:
	GraphicsSystem();
	GraphicsSystem(int height, int width, int scalar);
	~GraphicsSystem();

	int init();
	void cleanup();

	int getHeight();
	int getWidth();
	SDL_Renderer* getRenderer();
	
	void drawSprite(Sprite spriteObj, int drawLocX, int drawLocY);
	void drawText(Font* fontObj, Color* colorObj, int messageX, int messageY, std::string textmessage);
	void drawBuffer(GraphicsBuffer* bufferObj, int drawLocX, int drawLocY);
	void fillBackground();

	void flip();
};


#endif