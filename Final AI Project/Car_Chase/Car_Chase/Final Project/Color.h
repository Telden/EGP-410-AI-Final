#pragma once
#ifndef COLOR_H
#define COLOR_H

#include "Trackable.h"
#include "SDL_Lib.h"

 class Color: public Trackable
{
public:
	Uint8 mRed, mGreen, mBlue;

	Color();
	Color(Uint8 R, Uint8 G, Uint8 B);
	~Color();
};


#endif