#pragma once
#ifndef GAME_H 
#define GAME_H

#include "Trackable.h"
#include "Timer.h"
#include "EventSystem.h"
#include "EventListener.h"

class GraphicsBuffer;
class UserInterface;
class LevelManager;
class AnimationManager;
class UserInput;
class GraphicsSystem;
class GraphicsBufferManager;
class UnitManager;
class Link;

class Game : public EventListener 
{
	private:
		// the instance of Game
		static Game* mp_GameInstance;


		// Graphics Pointers
		GraphicsSystem* mp_GraphicsSystem;
		GraphicsBufferManager* mp_GraphicsBufferManager;

		// Sample Graphics Buffers
		GraphicsBuffer* mp_Arrow;
		GraphicsBuffer* mp_DungeonBG;
		GraphicsBuffer* mp_Door_Horizontal;
		GraphicsBuffer* mp_Door_Vertical;
		GraphicsBuffer* mp_Dungeon_Tiles;
		GraphicsBuffer* mp_Kese;
		GraphicsBuffer* mp_Link_Attack;
		GraphicsBuffer* mp_link_walk;
		GraphicsBuffer* mp_Stalfos;
		GraphicsBuffer* mp_Sword;
		GraphicsBuffer* mp_treasures;
		GraphicsBuffer* mp_PapaSmurf;
		GraphicsBuffer* mp_UI;
		GraphicsBuffer* mp_TitleScreen;
		GraphicsBuffer* mp_Dragon;
		GraphicsBuffer* mp_Gel;
		GraphicsBuffer* mp_Fireball;
		GraphicsBuffer* mp_GameOver;
		GraphicsBuffer* mp_WinScreen;
		GraphicsBuffer* mp_MenuText;
		GraphicsBuffer* mp_Peahat;
		GraphicsBuffer* mp_papaSmurf;
		GraphicsBuffer* mp_Difficulty;

		// Game Loop timer
		Timer* mp_timer;

		// Manager Pointers
		UserInterface* mp_UserInterface;
		LevelManager* mp_LevelManager;
		AnimationManager* mp_AnimationManager;
		UserInput* mp_Input;

		// Game Objects (Zelda)
		UnitManager* mp_UnitManager;
	
		// Data to initialize rest of systems and objects
		const std::string DATA_PATH = "Data/filepaths.txt";
		
		std::string mArrow_Path;
		std::string mDungeon_Background_Path;
		std::string mDungeon_Doors_Horizontal_Path;
		std::string mDungeon_Doors_Vertical_Path;
		std::string mDungeon_Tiles_Path;
		std::string mKese_Path;
		std::string mLink_Attack_Path;
		std::string mLink_Walk_Path;
		std::string mStalfos_Path;
		std::string mSword_Path;
		std::string mTreasures_Path;
		std::string mPapaSmurf_Path;
		std::string mTitle_Path;
		std::string mUI_Path;
		std::string mDragon_Path;
		std::string mGel_Path;
		std::string mFireball_Path;
		std::string mGameOver_Path;
		std::string mWinScreen_Path;
		std::string mMenuText_Path;
		std::string mPeahat_Path;
		std::string mDifficulty_Path;


		std::string mFONT_PATH;
	
		// Constant system numbers
		const int FONT_SIZE = 12;
		const int WINDOW_SIZE_X = 1000;
		const int WINDOW_SIZE_Y = 900;
		const double FRAME_RATE = 16.7;
		const int TOTAL_LEVELS = 17;
		const int RENDER_SCALE = 4;

		int mLinkHealth = 3;
		int mCurrentDifficulty = 1;
	
	public:
		// Game Initializers and destructors
		Game();
		~Game();
		void init();
		void loadData();
		void cleanup();

		// Instance Functions
		static void initInstance();
		static Game* getInstance();
		static void deleteInstance();

		// Game Loop functions
		void gameLoop();
		void update();
		void render();

		//Title Screen
		bool mNewGame = false;
		bool mLoad = false;
		bool m_isStarted = false;
		bool mReset = false;
		void titleScreen();

		//Lose screen
		void gameOver();

		//Win Screen
		void victoryScreen();

		// Initialize Pointer
		void createBufferObject();
	
		// Accessors
		GraphicsSystem* getGraphicsSystem() { return mp_GraphicsSystem; }
		GraphicsBufferManager* getBufferManager() { return mp_GraphicsBufferManager; }
		AnimationManager* getAnimationManager() { return mp_AnimationManager; }
		LevelManager* getLevelManager() { return mp_LevelManager; }
		int getLinkHealth() { return mLinkHealth; }
		int getLinkCurrentHealth();
		int getLinkCurrentKeys();
		// Listener Functions
		void handleEvent(const Event& theEvent);

		// Game Loop checkers
		bool m_escape = false;
		int m_winCondition;

		//Reset the game
		void reset();
};


#endif