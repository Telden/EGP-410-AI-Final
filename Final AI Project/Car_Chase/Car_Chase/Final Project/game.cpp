#include "Game.h"

#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
#include "BufferManager.h"
#include "AnimationManager.h"
#include "Animation.h"
#include "UnitManager.h"
#include "Link.h"
#include "AudioSystem.h"

//Game Specific
#include "UserInput.h"
#include "UserInterface.h"
#include "LevelManager.h"
#include "EndGameEvent.h"
#include <fstream>
#include <iostream>
#include "ChangeDifficultyEvent.h"

Game * Game::mp_GameInstance = nullptr;

Game::Game()
{

}

Game::~Game()
{
	cleanup();
}

//Initalize all of the game systems and objects
void Game::init()
{
	// Graphics System
	if (mp_GraphicsSystem == NULL)
	{
		mp_GraphicsSystem = new GraphicsSystem(WINDOW_SIZE_Y, WINDOW_SIZE_X, RENDER_SCALE);
		mp_GraphicsSystem->init();
	}
	
	//Load FilePaths
	loadData();


	// Graphics Buffer Manager
	if (mp_GraphicsBufferManager == NULL)
	{
		mp_GraphicsBufferManager = new GraphicsBufferManager();
		createBufferObject();
	}
	

	if (mp_AnimationManager == NULL)
	{
		// Animation Manager
		mp_AnimationManager = new AnimationManager();
		mp_AnimationManager->initAnimation(mp_GraphicsBufferManager);

	}

	// GUI
	if (mp_UserInterface == NULL)
	{
		mp_UserInterface = new UserInterface(mp_GraphicsSystem);
	}
	

	// Input system
	if (mp_Input == NULL)
	{
		mp_Input = new UserInput();
	}
	

	//Audio System
	AudioSystem::initInstance();

	// Add listeners
	gpEventSystem->addListener(LOAD_GAME_EVENT, this);
	gpEventSystem->addListener(LOAD_SAVE_EVENT, this);
	gpEventSystem->addListener(END_GAME_EVENT, this);
	
	

	
	if (mp_timer == NULL)
	{
		mp_timer = new Timer;
	}
	
}

//Load the filepaths into the game
void Game::loadData()
{
	ifstream inputF;
	inputF.open(DATA_PATH);

	// Load file paths
	getline(inputF, mLink_Attack_Path);
	getline(inputF, mLink_Walk_Path);
	getline(inputF, mSword_Path);
	getline(inputF, mTitle_Path);
	getline(inputF, mUI_Path);
	getline(inputF, mGameOver_Path);
	getline(inputF, mWinScreen_Path);
	getline(inputF, mMenuText_Path);
	inputF.close();
}

void Game::initInstance()
{
	mp_GameInstance = new Game;
}

void Game::deleteInstance()
{
	delete mp_GameInstance;
}

Game* Game::getInstance()
{
	SDL_assert(mp_GameInstance != nullptr);
	return mp_GameInstance;
}

// Clear out all of the pointers
void Game::cleanup()
{
	if (mp_GraphicsSystem != NULL)
	{
		delete mp_GraphicsSystem;
	}
	if (mp_GraphicsBufferManager != NULL)
	{
		delete mp_GraphicsBufferManager;
	}
	if (mp_timer != NULL)
	{
		delete mp_timer;
	}
	if (mp_UserInterface != NULL)
	{
		delete mp_UserInterface;
	}
	if (mp_LevelManager != NULL)
	{
		delete mp_LevelManager;
	}
	if (mp_Input != NULL)
	{
		delete mp_Input;
	}
	if (mp_AnimationManager != NULL)
	{
		delete mp_AnimationManager;
	}

	//Turn AudioSystem off
	AudioSystem::deleteInstance();
}

// Handle event calls
void Game::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == LOAD_GAME_EVENT)
	{
		std::cout << "Starting game\n";
		m_isStarted = true;
		mNewGame = true;
	}
	if (theEvent.getType() == LOAD_SAVE_EVENT)
	{
		std::cout << "Starting game\n";
		m_isStarted = true;
		mLoad = true;
	}
	else if (theEvent.getType() == LINK_DEATH_EVENT)
	{
		gameOver();
	}

	else if (theEvent.getType() == WIN_GAME_EVENT)
	{
		victoryScreen();
	}

	else if (theEvent.getType() == RESET_GAME_EVENT)
	{
		mReset = true;
	}

	else if (theEvent.getType() == END_GAME_EVENT)
	{
		m_escape = true;
	}

	else if (theEvent.getType() == CHANGE_DIFFICULTY_EVENT)
	{
		const ChangeDifficultyEvent& changeDifficultyEvent = static_cast<const ChangeDifficultyEvent&>(theEvent);

		mLinkHealth = 3;
		mLinkHealth += changeDifficultyEvent.getValue();

		if (changeDifficultyEvent.getName() == "Easy")
		{
			mCurrentDifficulty = 0;
		}
		else if (changeDifficultyEvent.getName() == "Medium")
		{
			mCurrentDifficulty = 1;
		}
		else if (changeDifficultyEvent.getName() == "Hard")
		{
			mCurrentDifficulty = 2;
		}
	}
}

//Run the title  screen and load the game depending on input
void Game::titleScreen()
{

	if (mReset)
	{
		mReset = false;
	}
	
	//Get the title animation
	Animation* tempAnim = mp_AnimationManager->getAnimation("Title");
	do
	{
		mp_timer->start();
		mp_Input->checkInput();
		mp_GraphicsSystem->drawSprite(tempAnim->getSprite(tempAnim->getCurrentSprite()), 0, 0);
		tempAnim->update();
		mp_GraphicsSystem->flip();
		mp_timer->sleepUntilElapsed(FRAME_RATE);
	} while (m_isStarted == false);

	if (mNewGame)
	{
		if (mp_LevelManager != NULL)
		{
			mp_LevelManager->resetLevels();
		}
		else
		{
			mp_LevelManager = new LevelManager(RENDER_SCALE);
			mp_LevelManager->initLevels();
		}
	}
	else
	{
		if (mp_LevelManager == NULL)
		{
			mp_LevelManager = new LevelManager(RENDER_SCALE);
			mp_LevelManager->loadSave();
		}
		else 
		{
			mp_LevelManager->reloadLevels();
		}
		
	}

	
	mp_UserInterface->updateMaxHealth();
	
	

	AudioSystem::getInstance()->dungeonMusic();
}

void Game::gameOver()
{
	m_isStarted = false;

	do
	{
		mp_timer->start();
		mp_Input->checkInput();
		mp_GraphicsSystem->drawBuffer(mp_GameOver, 0, 0);
		mp_GraphicsSystem->flip();
		mp_timer->sleepUntilElapsed(FRAME_RATE);

	} while (!mReset);

	AudioSystem::getInstance()->titleScreenMusic();
	titleScreen();
	
}

void Game::victoryScreen()
{
	m_isStarted = false;

	do
	{
		mp_timer->start();
		mp_Input->checkInput();
		mp_GraphicsSystem->drawBuffer(mp_WinScreen, 0, 0);
		mp_GraphicsSystem->flip();
		mp_timer->sleepUntilElapsed(FRAME_RATE);

	} while (!mReset);

	AudioSystem::getInstance()->titleScreenMusic();
	titleScreen();
}

void Game::gameLoop()
{
	do
	{
		mp_timer->start();

		mp_Input->checkInput();
		update();
		render();

		mp_timer->sleepUntilElapsed(FRAME_RATE);
	} while (!m_escape);
}

void Game::update()
{	
	//Update User interface
	mp_UserInterface->update();

	// update the unit behavior
	mp_LevelManager->update();
}

void Game::render()
{
	// draw the background
	mp_GraphicsSystem->drawBuffer(mp_DungeonBG, 0, 0);

	// render the unit behavior
	mp_LevelManager->render();

	//Render the Ui
	mp_UserInterface->render();

	// flip off the backbuffer
	mp_GraphicsSystem->flip();
}

//Load all of the graphics buffers into the graphics buffer manager
void Game::createBufferObject()
{
	SDL_assert(mp_GraphicsBufferManager != nullptr);

	// add the graphics buffers to the manager
	
	mp_GraphicsBufferManager->createBuffer("LinkAttack", mp_Link_Attack = new GraphicsBuffer(mLink_Attack_Path));
	mp_GraphicsBufferManager->createBuffer("LinkMove", mp_link_walk = new GraphicsBuffer(mLink_Walk_Path));
	mp_GraphicsBufferManager->createBuffer("Sword", mp_Sword = new GraphicsBuffer(mSword_Path));
	mp_GraphicsBufferManager->createBuffer("Title", mp_TitleScreen = new GraphicsBuffer(mTitle_Path));
	mp_GraphicsBufferManager->createBuffer("UI", mp_UI = new GraphicsBuffer(mUI_Path));
	mp_GraphicsBufferManager->createBuffer("GameOver", mp_GameOver = new GraphicsBuffer(mGameOver_Path));
	mp_GraphicsBufferManager->createBuffer("WinScreen", mp_WinScreen = new GraphicsBuffer(mWinScreen_Path));
	mp_GraphicsBufferManager->createBuffer("Menu Text", mp_MenuText = new GraphicsBuffer(mMenuText_Path));
}

int Game::getLinkCurrentHealth()
{
	return mp_LevelManager->getLink()->getCurrentHealth();
}

int Game::getLinkCurrentKeys()
{
	return mp_LevelManager->getLink()->getNumKeys();
}