#include <stdio.h>
#include <assert.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include <sstream>
#include <fstream>
#include <iostream>

#include "Game.h"
#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
#include "GraphicsBufferManager.h"
#include "GameMessageManager.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "Timer.h"
#include "KinematicUnit.h"
#include "UnitManager.h"
#include "InputManager.h"
#include "UiManager.h"
#include "Graph.h"
#include "AudioManager.h"

Game* gpGame = NULL;

const int WIDTH = 1024; // /2 is 512
const int HEIGHT = 768; // /2 is 384

Game::Game()
	:mpGraphicsSystem(NULL)
	, mpGraphicsBufferManager(NULL)
	, mpSpriteManager(NULL)
	, mpUnitManager(NULL)
	, mpInputManager(NULL)
	, mpLoopTimer(NULL)
	, mpMasterTimer(NULL)
	, mShouldExit(false)
	, mpSample(NULL)
	, mBackgroundBufferID(INVALID_ID)
{
}

Game::~Game()
{
	cleanup();
}

bool Game::init()
{
	mShouldExit = false;

	//create Timers
	mpLoopTimer = new Timer;
	mpMasterTimer = new Timer;

	

	//startup allegro
	if (!al_init())
	{
		fprintf(stderr, "failed to initialize allegro!\n");
		return false;
	}

	//create and init GraphicsSystem
	mpGraphicsSystem = new GraphicsSystem();
	bool goodGraphics = mpGraphicsSystem->init(WIDTH, HEIGHT);
	if (!goodGraphics)
	{
		fprintf(stderr, "failed to initialize GraphicsSystem object!\n");
		return false;
	}

	mpGraphicsBufferManager = new GraphicsBufferManager();

	// Create Ui Manager and initialize allegro font
	mpUiManager = new UiManager();
	mpUiManager->init();

	mpSpriteManager = new SpriteManager();

	//startup a lot of allegro stuff

	//load image loader addon
	if (!al_init_image_addon())
	{
		fprintf(stderr, "image addon failed to load!\n");
		return false;
	}

	//install audio stuff
	if (!al_install_audio())
	{
		fprintf(stderr, "failed to initialize sound!\n");
		return false;
	}

	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return false;
	}

	if (!al_reserve_samples(8))
	{
		fprintf(stderr, "failed to reserve samples!\n");
		return false;
	}

	//show the mouse
	if (!al_hide_mouse_cursor(mpGraphicsSystem->getDisplay()))
	{
		printf("Mouse cursor not able to be hidden!\n");
		return false;
	}

	if (!al_init_primitives_addon())
	{
		printf("Primitives addon not added!\n");
		return false;
	}

	mpMessageManager = new GameMessageManager();

	//load buffers
	mBackgroundBufferID = mpGraphicsBufferManager->loadBuffer("wallpaper.bmp");
	mPlayerIconBufferID = mpGraphicsBufferManager->loadBuffer("arrow.bmp");
	mEnemyIconBufferID = mpGraphicsBufferManager->loadBuffer("enemy-arrow.bmp");
	mHorizontalWallID = mpGraphicsBufferManager->loadBuffer("Horizontal_Wall.bmp");
	mVerticalWallID = mpGraphicsBufferManager->loadBuffer("Vertical_Wall.bmp");

	//setup sprites
	GraphicsBuffer* pBackGroundBuffer = mpGraphicsBufferManager->getBuffer(mBackgroundBufferID);
	if (pBackGroundBuffer != NULL)
	{
		mpSpriteManager->createAndManageSprite(BACKGROUND_SPRITE_ID, pBackGroundBuffer, 0, 0, pBackGroundBuffer->getWidth(), pBackGroundBuffer->getHeight());
	}
	GraphicsBuffer* pPlayerBuffer = mpGraphicsBufferManager->getBuffer(mPlayerIconBufferID);
	Sprite* pArrowSprite = NULL;
	if (pPlayerBuffer != NULL)
	{
		pArrowSprite = mpSpriteManager->createAndManageSprite(PLAYER_ICON_SPRITE_ID, pPlayerBuffer, 0, 0, pPlayerBuffer->getWidth(), pPlayerBuffer->getHeight());
	}
	GraphicsBuffer* pAIBuffer = mpGraphicsBufferManager->getBuffer(mEnemyIconBufferID);
	Sprite* pEnemyArrow = NULL;
	if (pAIBuffer != NULL)
	{
		pEnemyArrow = mpSpriteManager->createAndManageSprite(AI_ICON_SPRITE_ID, pAIBuffer, 0, 0, pAIBuffer->getWidth(), pAIBuffer->getHeight());
	}
	GraphicsBuffer* pVerticalWallBuffer = mpGraphicsBufferManager->getBuffer(mVerticalWallID);
	Sprite* pVerticalWallSprite = NULL;
	if (pVerticalWallBuffer != NULL)
	{
		pVerticalWallSprite = mpSpriteManager->createAndManageSprite(VERTICAL_WALL_ID, pVerticalWallBuffer, 0, 0, pVerticalWallBuffer->getWidth(), pVerticalWallBuffer->getHeight());
	}
	GraphicsBuffer* pHorizontalWallBuffer = mpGraphicsBufferManager->getBuffer(mHorizontalWallID);
	Sprite* pHorizontalWallSprite = NULL;
	if (pHorizontalWallBuffer != NULL)
	{
		pHorizontalWallSprite = mpSpriteManager->createAndManageSprite(HORIZONTAL_WALL_ID , pHorizontalWallBuffer, 0, 0, pHorizontalWallBuffer->getWidth(), pHorizontalWallBuffer->getHeight());
	}

	mpGraph = new Graph();
	mpGraph->init();

	//Create UnitManager
	mpUnitManager = new UnitManager();
	mpInputManager = new InputManager();
	mpInputManager->init();


   // create the audio manager and then add the sounds and music
   mpAudioManager = new AudioManager();
   mpAudioManager->AddClip("splash", FX_PATH_SPLASH);
   mpAudioManager->AddClip("shine", FX_PATH_SHINE);
   mpAudioManager->AddClip("alarm", FX_PATH_ALARM);
   mpAudioManager->AddMusic(MUS_PATH);

   // player states
   mPlayerHasPickup = false;
   mPlayerHasPowerup = false;

   // get the high score from the file
   std::ifstream fin;
   fin.open(HIGH_SCORE_PATH);
   if (!fin)
   {
      std::cout << "Failed to open " << HIGH_SCORE_PATH << std::endl;
   }
   fin >> mHighScore;
   // prevent garbage from getting in the high score
   if (mHighScore < 0)
      mHighScore = 0;
   fin.close();
	return true;
}

void Game::cleanup()
{
   // output the high score to the file
   std::ofstream fout;
   fout.open(HIGH_SCORE_PATH);
   if (!fout)
   {
      std::cout << "Failed to open " << HIGH_SCORE_PATH << std::endl;
   }
   if (mCurrentScore > mHighScore)
   {
      std::cout << "Congratulations! " << mHighScore << " is your new high score!" << std::endl;
      fout << mCurrentScore;
   }
   fout.close();

	//Delete Unit Manager
	delete mpUnitManager;

	//Delete Input manager
	delete mpInputManager;

	//delete the timers
	delete mpLoopTimer;
	mpLoopTimer = NULL;
	delete mpMasterTimer;
	mpMasterTimer = NULL;

	//delete the graphics system
	delete mpGraphicsSystem;
	mpGraphicsSystem = NULL;

	delete mpGraphicsBufferManager;
	mpGraphicsBufferManager = NULL;
	delete mpSpriteManager;
	mpSpriteManager = NULL;
	delete mpMessageManager;
	mpMessageManager = NULL;
	delete mpUiManager;
	mpUiManager = NULL;
	delete mpGraph;
	mpGraph = NULL;
	al_destroy_sample(mpSample);
	mpSample = NULL;

   delete mpAudioManager;
   mpAudioManager = NULL;

	//shutdown components
	al_uninstall_audio();
	al_shutdown_image_addon();
	al_shutdown_font_addon();
	al_shutdown_ttf_addon();
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_shutdown_primitives_addon();

}

void Game::beginLoop()
{
	mpLoopTimer->start();
}

void Game::processLoop()
{
	
	//draw background
	Sprite* pBackgroundSprite = mpSpriteManager->getSprite(BACKGROUND_SPRITE_ID);
	pBackgroundSprite->draw(*(mpGraphicsSystem->getBackBuffer()), 0, 0);

	//If in debug mode draw debug elements
	if (mShouldDebug)
	{
		mpGraph->renderGraph();
		mpInputManager->checkDebugInput();
	}
	//else
	{
		mpUnitManager->updateUnits(LOOP_TARGET_TIME / 1000.0f);
		mpInputManager->checkInput();
		mpUiManager->update(mCurrentScore);
	}

	
	//mpUnitManager->updateUI();
	
	
	mpMessageManager->processMessagesForThisframe();

	GRAPHICS_SYSTEM->swap();


}

bool Game::endLoop()
{
	//mpMasterTimer->start();
	mpLoopTimer->sleepUntilElapsed(LOOP_TARGET_TIME);
	return mShouldExit;
}

float genRandomBinomial()
{
	return genRandomFloat() - genRandomFloat();
}

float genRandomFloat()
{
	float r = (float)rand() / (float)RAND_MAX;
	return r;
}

void Game::endGame()
{
	mShouldExit = true;
}

void Game::toggleDebug()
{
	if (mShouldDebug)
		mShouldDebug = false;
	else
		mShouldDebug = true;
}

void  Game::switchMap()
{
	if (mCurrentLevel == 0)
		mCurrentLevel = 1;
	else if (mCurrentLevel == 1)
		mCurrentLevel = 0;
}