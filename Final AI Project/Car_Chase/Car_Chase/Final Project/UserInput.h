#pragma once
#ifndef USERINPUT_H
#define USERINPUT_H
#include "Trackable.h"
#include "SDL_lib.h"

class UserInput : public Trackable
{
public:
	UserInput();
	~UserInput();
	void checkInput();
	
private:
	const Uint8* mEVENT;
	SDL_Event event;
	bool mIspressed;
	int switchcooldown = 30;
	bool m_isStarted = false;
	bool mGameOver = false;
	
};
#endif