#include "UserInput.h"
#include "EventSystem.h"
#include "Event.h"
#include "Game.h"

//Events
#include "MovementEventDown.h"
#include "MovementEventLeft.h"
#include "MovementEventRight.h"
#include "MovementEventUp.h"
#include "ChangeDifficultyEvent.h"

UserInput::UserInput()
{

}

UserInput::~UserInput()
{

}

void UserInput::checkInput()
{
	SDL_PumpEvents();
//https://wiki.libsdl.org/SDL_GetKeyboardState
//https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.html
	/* 
		SOME OF THE FOLLOWING CODE STRUCTURE CAN BE FOUND ON https://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinputkeyboard.html. THE STRUCTURE USED WAS 
		THE ABILITY TO READ ONLY ONE INPUT IN WHEN THE PLAYER PRESSES A BUTTON SO THE GAME IS NOT SPAMMED WITH ONE MESSAGE FOR THE NUMBER OF FRAMES PRESSED.
		WE DO NOT TAKE CREDIT FOR THIS STRUCTURE, AND ALL OWNERSHIP OF THE CODE STRUCTURE IS TO THE AUTHOR OF THE SDL2 DOCUMENTATION. 
	*/

	mEVENT = SDL_GetKeyboardState(NULL);

	while (SDL_PollEvent(&event))
	{
		switch (event.type) 
		{
		case SDL_KEYDOWN:
		{
				if (mEVENT[SDL_SCANCODE_X])
			{
				//continue
				if (!m_isStarted)
				{
					gpEventSystem->fireEvent(LOAD_GAME_EVENT);
					m_isStarted = true;
				}
				
			}
			else if (mEVENT[SDL_SCANCODE_Z])
			{
				
				//load save
				if (!m_isStarted)
				{
					std::cout << "Z pressed\n";
					gpEventSystem->fireEvent(LOAD_SAVE_EVENT);
					m_isStarted = true;
				}
				else
				{
					gpEventSystem->fireEvent(ATTACK_EVENT_PRIMARY);
				}
			}
			else if (mEVENT[SDL_SCANCODE_SPACE])
			{
				if (m_isStarted && !mGameOver)
				{
					std::cout << "Resetting\n";
					m_isStarted = false;
					gpEventSystem->fireEvent(RESET_GAME_EVENT);
				}
			}
			else if (mEVENT[SDL_SCANCODE_M])
				{
				gpEventSystem->fireEvent(STOP_MUSIC_EVENT);
				}
			/*else if (mEVENT[SDL_SCANCODE_R])
			{
				gpEventSystem->fireEvent(SAVE_GAME_EVENT);
			}
			break;*/
		}


		case SDL_KEYUP:
			break;

		default:
			break;
		}
	}

	if (mEVENT[SDL_SCANCODE_ESCAPE])
	{
		std::cout << "Escape Key\n";
		gpEventSystem->fireEvent(END_GAME_EVENT);
	}
	if (mEVENT[SDL_SCANCODE_LEFT])
	{
		//std::cout << "Left\n";
		gpEventSystem->fireEvent(MOVEMENT_EVENT_LEFT);
	}
	if (mEVENT[SDL_SCANCODE_RIGHT])
	{
		//std::cout << "Right\n";
		gpEventSystem->fireEvent(MOVEMENT_EVENT_RIGHT);
	}
	if (mEVENT[SDL_SCANCODE_UP])
	{
		//std::cout << "Up\n";
		gpEventSystem->fireEvent(MOVEMENT_EVENT_UP);
	}
	if (mEVENT[SDL_SCANCODE_DOWN])
	{
		//std::cout << "Down\n";
		gpEventSystem->fireEvent(MOVEMENT_EVENT_DOWN);
	}
	
	//if (mEVENT[SDL_SCANCODE_X])
	//{
	//	//std::cout << "Secondary Attack\n";
	//	gpEventSystem->fireEvent(ATTACK_EVENT_SECONDARY);
	//}

	if (mEVENT[SDL_SCANCODE_X])
	{
		//std::cout << "Secondary Attack\n";
		gpEventSystem->fireEvent(ATTACK_EVENT_SECONDARY);
	}
	



}



