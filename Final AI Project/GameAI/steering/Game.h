#pragma once

#include "Trackable.h"
#include "PerformanceTracker.h"
#include "Defines.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <string>

class GraphicsSystem;
class GraphicsBuffer;
class GraphicsBufferManager;
class SpriteManager;
class KinematicUnit;
class GameMessageManager;
class Timer;
class UnitManager;
class InputManager;
class UiManager;
class Graph;
class AudioManager;

const IDType BACKGROUND_SPRITE_ID = 0;
const IDType PLAYER_ICON_SPRITE_ID = 1;
const IDType AI_ICON_SPRITE_ID = 2;
const IDType HORIZONTAL_WALL_ID = 3;
const IDType VERTICAL_WALL_ID = 4;

const std::string FX_PATH_SPLASH = "sound/sfxSplash.wav";
const std::string FX_PATH_SHINE = "sound/sfxShine.wav";
const std::string FX_PATH_ALARM = "sound/sfxAlarm.wav";
const std::string MUS_PATH = "sound/bgmMusic.wav";

const std::string HIGH_SCORE_PATH = "data/highscore.txt";

const float LOOP_TARGET_TIME = 33.3f;//how long should each frame of execution take? 30fps = 33.3ms/frame

class Game:public Trackable
{
public:
	Game();
	~Game();

	bool init();//returns true if no errors, false otherwise
	void cleanup();

	//game loop
	void beginLoop();
	void processLoop();
	bool endLoop();
	void endGame();

	inline GraphicsSystem* getGraphicsSystem() const { return mpGraphicsSystem; };
	inline GraphicsBufferManager* getGraphicsBufferManager() const { return mpGraphicsBufferManager; };
	inline SpriteManager* getSpriteManager() const { return mpSpriteManager; };
	inline UnitManager* getUnitManager()  const { return mpUnitManager; };
	inline UiManager* getUiManager() const { return mpUiManager; };
	inline GameMessageManager* getMessageManager() { return mpMessageManager; };
	inline Timer* getMasterTimer() const { return mpMasterTimer; };
	inline Graph* getGraph() const { return mpGraph; };
	inline double getCurrentTime() const { return mpMasterTimer->getElapsedTime(); };
   inline AudioManager* getAudioManager() const { return mpAudioManager; };
   inline int getCurrentLevel() const { return mCurrentLevel; };

   int getScore() { return mCurrentScore; }
   int getHighScore() { return mHighScore; }
   void setScore(int newVal) { mCurrentScore = newVal; }
   void setHighScore(int newVal) { mHighScore = newVal; }
   void switchMap();

	void toggleDebug();

   void setPlayerHasPowerup(bool newVal) { mPlayerHasPowerup = newVal; };
   void setPlayerHasPickup(bool newVal) { mPlayerHasPickup = newVal; };

   bool getPlayerHasPowerup() { return mPlayerHasPowerup; };
   bool getPlayerHasPickup() { return mPlayerHasPickup; };

private:
	GraphicsSystem* mpGraphicsSystem;
	GraphicsBufferManager* mpGraphicsBufferManager;
	SpriteManager* mpSpriteManager;
	GameMessageManager* mpMessageManager;
	UiManager* mpUiManager;
	Timer* mpLoopTimer;
	Timer* mpMasterTimer;
	UnitManager* mpUnitManager;
	InputManager* mpInputManager;
   AudioManager* mpAudioManager;
	bool mShouldExit;
	bool mShouldDebug = false;

	ALLEGRO_SAMPLE* mpSample;
	IDType mBackgroundBufferID;
	IDType mPlayerIconBufferID;
	IDType mEnemyIconBufferID;
	IDType mHorizontalWallID;
	IDType mVerticalWallID;

	int mCurrentLevel = 0;
   int mCurrentScore = 0;
   int mHighScore;

	Graph* mpGraph;

   bool mPlayerHasPickup = false;
   bool mPlayerHasPowerup = false;

};

float genRandomBinomial();//range -1:1 from "Artificial Intelligence for Games", Millington and Funge
float genRandomFloat();//range 0:1 from "Artificial Intelligence for Games", Millington and Funge

extern Game* gpGame;
extern PerformanceTracker* gpPerformanceTracker;

