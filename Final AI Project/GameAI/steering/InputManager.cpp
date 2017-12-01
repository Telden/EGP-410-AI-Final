#include "InputManager.h"
#include "Defines.h"
#include <sstream>
#include <stdio.h>
#include "GameMessageManager.h"
#include "GameMessage.h"
#include "Game.h"

// Messages
#include "EndGameMessage.h"
#include "MovementMessage.h"



InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

bool InputManager::init()
{
	if (!al_install_keyboard())
	{
		printf("Keyboard not installed!\n");
		return false;
	}

	if (!al_install_mouse())
	{
		printf("Mouse not installed!\n");
		return false;
	}

	return true;
}


void InputManager::checkInput()
{
	GameMessage* pMessage;
	//get current keyboard state
	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);

	//if escape key was down then exit the loop
	if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
	{
		pMessage = new EndGameMessage();
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	/* Movement Key Inputs (If pressed) */
	if (al_key_down(&keyState, ALLEGRO_KEY_W) && !mForwardKeyDown)
	{
		//printf("W Key\n");
		mForwardKeyDown = true;
		pMessage = new MovementMessage('W', mForwardKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}
	if (al_key_down(&keyState, ALLEGRO_KEY_S) && !mBackwardsKeyDown)
	{
		//printf("S Key\n");
		mBackwardsKeyDown = true;
		pMessage = new MovementMessage('S', mBackwardsKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	if (al_key_down(&keyState, ALLEGRO_KEY_A) && !mLeftKeyDown)
	{
		//printf("A Key\n");
		mLeftKeyDown = true;
		pMessage = new MovementMessage('A', mLeftKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);

	}
	if (al_key_down(&keyState, ALLEGRO_KEY_D) && !mRightKeyDown)
	{
		//printf("D Key");
		mRightKeyDown = true;
		pMessage = new MovementMessage('A', mRightKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}


	/* When a movement key is released */

	if (!al_key_down(&keyState, ALLEGRO_KEY_W) && mForwardKeyDown)
	{
		
		mForwardKeyDown = false;
		pMessage = new MovementMessage('W', mForwardKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}
	else if (!al_key_down(&keyState, ALLEGRO_KEY_S) && mBackwardsKeyDown)
	{
		printf("S Key Released\n");
		mBackwardsKeyDown = false;
		pMessage = new MovementMessage('S', mBackwardsKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	if (!al_key_down(&keyState, ALLEGRO_KEY_A) && mLeftKeyDown)
	{
		printf("A Key Released\n");
		mLeftKeyDown = false;
		pMessage = new MovementMessage('A', mLeftKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);

	}
	else if (!al_key_down(&keyState, ALLEGRO_KEY_D) && mRightKeyDown)
	{
		printf("D Key Released\n");
		mRightKeyDown = false;
		pMessage = new MovementMessage('A', mRightKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}
}