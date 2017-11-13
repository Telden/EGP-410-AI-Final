#pragma once
#ifndef GRAPHICSBUFFER_H
#define GRAPHICSBUFFER_H

#include "Trackable.h"
#include "SDL_Lib.h"
#include <string>


class GraphicsBuffer: public Trackable
{
	friend class Game;
private:
	SDL_Texture* mpImage = NULL;
	//ALLEGRO_BITMAP* mp_image = NULL;
	int mHeight;
	int mWidth;

public:
	GraphicsBuffer();
	GraphicsBuffer(std::string FILE_PATH);
	~GraphicsBuffer();

	int getheight();
	int getWidth();
	//ALLEGRO_BITMAP* getBitmap();
	SDL_Texture* getTexture();

};

//voidaddSprite(Sprite *sprite);
//anim.addsprite(newsprite(gb, x, y, w, h));
//stl vector of sprites
#endif