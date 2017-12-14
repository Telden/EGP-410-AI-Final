#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Trackable.h"
#include <allegro5/allegro.h>
class GameMessage;

class InputManager : public Trackable
{
private:

	bool mKeyPressed = true;

	/* Key Bools */
	bool mForwardKeyDown = false;
	bool mBackwardsKeyDown = false;
	bool mLeftKeyDown = false;
	bool mRightKeyDown = false;
	bool mDebugKeyDown = false;
	bool mLeftClickDown = false;
	bool mRightClickDown = false;
	bool mMKeyDown = false;
	bool mOKeyDown = false;
	bool mPKeyDown = false;

public:
	InputManager();
	~InputManager();
	void checkInput();
	void checkDebugInput();
	bool init();
};
#endif // !INPUTMANAGER_H