#include "InputManager.h"
#include "Defines.h"
#include <sstream>
#include <stdio.h>
#include "GameMessageManager.h"
#include "GameMessage.h"
#include "Game.h"
#include  "Vector2D.h"

// Messages
#include "EndGameMessage.h"
#include "MovementMessage.h"
#include "ToggleDebugMessage.h"
#include "UpdateMouseUiMessage.h"
#include "SwitchMapMessage.h"
#include "CreatePickupMessage.h"


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
		mForwardKeyDown = true;
		pMessage = new MovementMessage('W', mForwardKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}
	if (al_key_down(&keyState, ALLEGRO_KEY_S) && !mBackwardsKeyDown)
	{
		mBackwardsKeyDown = true;
		pMessage = new MovementMessage('S', mBackwardsKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	if (al_key_down(&keyState, ALLEGRO_KEY_A) && !mLeftKeyDown)
	{
		mLeftKeyDown = true;
		pMessage = new MovementMessage('A', mLeftKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);

	}
	if (al_key_down(&keyState, ALLEGRO_KEY_D) && !mRightKeyDown)
	{
		mRightKeyDown = true;
		pMessage = new MovementMessage('D', mRightKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	if (al_key_down(&keyState, ALLEGRO_KEY_B) && !mDebugKeyDown)
	{
		mDebugKeyDown = true;
		pMessage = new ToggleDebugMessage();
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
		mBackwardsKeyDown = false;
		pMessage = new MovementMessage('S', mBackwardsKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	if (!al_key_down(&keyState, ALLEGRO_KEY_A) && mLeftKeyDown)
	{
		mLeftKeyDown = false;
		pMessage = new MovementMessage('A', mLeftKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);

	}
	else if (!al_key_down(&keyState, ALLEGRO_KEY_D) && mRightKeyDown)
	{
		mRightKeyDown = false;
		pMessage = new MovementMessage('D', mRightKeyDown);
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}
	if (!al_key_down(&keyState, ALLEGRO_KEY_B) && mDebugKeyDown)
	{
		mDebugKeyDown = false;
	}


}

void::InputManager::checkDebugInput()
{
	GameMessage* pMessage;
	//get current keyboard state
	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);
	//get mouse state
	ALLEGRO_MOUSE_STATE mouseState;
	al_get_mouse_state(&mouseState);

	//Get the mouse posision and send it to the graphics system to draw a node rectangle
	Vector2D pos(mouseState.x, mouseState.y);
	pMessage = new UpdateMouseUiMessage(pos);
	MESSAGE_MANAGER->addMessage(pMessage, 0);

	if (al_key_down(&keyState, ALLEGRO_KEY_M) && !mMKeyDown)
	{
		mMKeyDown = true;
		pMessage = new SwitchMapMessage();
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	if (al_key_down(&keyState, ALLEGRO_KEY_B) && !mDebugKeyDown)
	{
		mDebugKeyDown = true;
		pMessage = new ToggleDebugMessage();
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	if (al_key_down(&keyState, ALLEGRO_KEY_O) && !mOKeyDown)
	{
		mOKeyDown = true;
		pMessage = new CreatePickupMessage(pos, 20, 0, gpGame->getCurrentLevel());
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	if (al_key_down(&keyState, ALLEGRO_KEY_P) && !mPKeyDown)
	{
		mPKeyDown = true;
		pMessage = new CreatePickupMessage(pos, 20, 1, gpGame->getCurrentLevel());
		MESSAGE_MANAGER->addMessage(pMessage, 0);
	}

	/* When the key is released */
	if (!al_key_down(&keyState, ALLEGRO_KEY_B) && mDebugKeyDown)
	{
		mDebugKeyDown = false;
	}

	if (!al_key_down(&keyState, ALLEGRO_KEY_M) && mMKeyDown)
	{
		mMKeyDown = false;
	}
	
	if (!al_key_down(&keyState, ALLEGRO_KEY_O) && mOKeyDown)
	{
		mOKeyDown = false;
	}

	if (!al_key_down(&keyState, ALLEGRO_KEY_P) && mPKeyDown)
	{
		mPKeyDown = false;
	}
}