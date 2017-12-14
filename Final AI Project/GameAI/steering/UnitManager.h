#pragma once
#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include "Trackable.h"
#include <vector>

class Vector2D;
class Player;

class Sprite;
class KinematicUnit;
class WallUnit;
class PickupUnit;

class UnitManager : public Trackable
{
private:
	Player* mpPlayer;

	std::vector<KinematicUnit*> mpUnits;
	std::vector<WallUnit*> mpWalls;
   std::vector<WallUnit*> mpWater;
   std::vector<WallUnit*> mpDoors;
   std::vector<PickupUnit*> mpPickups;
	Sprite* mpEnemySprite;
	Sprite* mpPlayerSprite;

public:
	/* Constructor and Destructor */
	UnitManager();
	~UnitManager();
	void cleanup();

	/* Accessors */
	std::vector<KinematicUnit*> getUnitList(); 
	KinematicUnit* getKinematicUnit(int index);
	WallUnit* getWallUnit(int index);
	WallUnit* getWaterUnit(int index);
	WallUnit* getDoorUnit(int index);
    PickupUnit* getPickupUnit(int index);

	void createPickupUnit(Vector2D mousePos, int diameter, int mode, int level);

	Player* getPlayerUnit() { return mpPlayer; };
	int getNumOfWalls();
   int getNumOfWater() { return mpWater.size(); }
   int getNumOfPickUps() { return mpPickups.size(); }
   int getNumOfDoors() { return mpDoors.size(); }

	void addUnit(KinematicUnit* newUnit);
	void addWall(WallUnit* newUnit);
   void addWater(WallUnit* newUnit);
   void addPickup(PickupUnit* newUnit);
	
	/* Update Functions */
	void updateUnits(float time);
};
#endif 