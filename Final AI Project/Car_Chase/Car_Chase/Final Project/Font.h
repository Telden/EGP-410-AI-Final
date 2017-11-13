#pragma once
#ifndef FONT_H
#define FONT_H


#include "Trackable.h"
#include "SDL_lib.h"
#include <string>
//#include "GraphicsSystem.h"

class Font: public Trackable
{
	friend class GraphicsSystem;

private:
	TTF_Font* mp_font = NULL;
	int m_fontSize;

public:
	Font();
	Font(std::string FILE_PATH, int size);
	~Font();
	int getSize();
	TTF_Font* getFont();
};


#endif