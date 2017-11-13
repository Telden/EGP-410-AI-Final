#pragma once
#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "EventListener.h"
#include "Trackable.h"
#include "Level.h"
//#include "UnitManager.h"
#include <map>
#include <string>

typedef std::string LevelKey;

class Link;

class LevelManager : public EventListener
{
	private:

		const std::string LOADFILEPATH = "Save/SaveData.txt";
		// MAP OF LEVELS
		std::map<LevelKey, Level*> mpLevels;
		Link* mpLink;

		void loadSaveLevel(Level* levelObj, std::string level);

		// LEVEL
		int m_currentLevel = 0;
		int m_total_levels;
		int mCurrentLevel = 25;

		// GRID
		const int TOTAL_ROWS = 9;
		const int TOTAL_COLUMNS = 14;
		const int GRID_SIZE = 16;
		const int BG_COMPENSATION = 8;
		int mGridSizeWithScalar, mCompensationWithScalar;
		int mScalar;

	public:
		// CONSTRUCTORS
		LevelManager(int scalar);
		~LevelManager();

		//LOAD LEVELS
		void initLevels();
		void loadSave();
		
		//GET LINK 
		Link* getLink() { return mpLink; }
		// UPDATE
		void update();
		void render();

		// EVENT SYSTEM
		void handleEvent(const Event& theEvent);

		// MAP
		void addLevel(std::string key, Level* newLevel);
		Level* getCurrentLevel();
		void clearList();
		int getTotalLevels();

		// COLLISION
		bool checkCollisionWithWalls(Unit* check, int distanceX, int distanceY);
		bool checkCollisionWithDoors(Unit* check, int distanceX, int distanceY);
		bool checkCollisionWithSword(Unit* check);
		bool checkCollisionWithArrow(Unit* check);
		bool checkCollisionWithPlayer(Unit* check);

		//SAVE GAME
		void saveGame();

		//RESET LEVELS
		void resetLevels();
		void reloadLevels();
};
#endif
