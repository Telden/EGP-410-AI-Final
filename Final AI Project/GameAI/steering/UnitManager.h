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
   PickupUnit* getPickupUnit(int index);

	Player* getPlayerUnit() { return mpPlayer; };
	int getNumOfWalls();
   int getNumOfWater() { return mpWater.size(); }
   int getNumOfPickUps() { return mpPickups.size(); }

	void addUnit(KinematicUnit* newUnit);
	void addWall(WallUnit* newUnit);
   void addWater(WallUnit* newUnit);
   void addPickup(PickupUnit* newUnit);
	
	/* Update Functions */
	void updateUnits(float time);
	void updateUI();
};
#endif 


//void SaveSettings();
//void createDynamicArriveUnit();
//void createDynamicSeekUnit();
//void createDynamicWanderSeekUnit();
//void createDynamicWanderFleeUnit();

//void createBoidUnit(Vector2D mousePos);
//void deleteUnit();

//void updateUnitValues(bool shouldIncrease, char currentSelection);

//std::vector<KinematicUnit*> getHoizontalWallList();
//std::vector<KinematicUnit*> getVerticalWallList();

//std::vector<KinematicUnit*> mpVerticalWalls;
//std::vector<KinematicUnit*> mpHorizontalWalls;

//Sprite* mpVerticalWallSprite;
//Sprite* mpHorizontalWallSprite;
//float mReactionRadius = 150.0f;
//float mAngularVelocity = 0.0f;
//float mEnemyVelocity = 180.0f;
//float mMaxAcceleration = 100.0f;
//bool mShouldUpdate = false;
//const int mINCREASE_VALUE = 1;

//const int DECAY_COEFFICIENT = 0.1;
//const int SLOW_RADIUS = 50;
//int separationRadius = 50;

//Weights
//float* mSepareationWeight;
//float* mCohesionWeight;
//float* mVelocityMatchingWeight;
//float* mAllignmentWeight;
//float* mWanderWeight;
//float* mWallAvoidanceWeight;
//float* mCollisionAvoidanceWeight;
//bool* mpWalls;
//const std::string UNIT_VALUES_FILEPATH = "UnitValues.txt";