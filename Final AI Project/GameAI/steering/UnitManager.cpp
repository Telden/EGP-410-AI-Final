#include <time.h>  
#include <stdlib.h> 
#include "UnitManager.h"
#include "Game.h"
#include "Vector2D.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "KinematicUnit.h"
#include "GraphicsSystem.h"
#include "GameMessageManager.h"
#include "GameMessage.h"
#include "EndGameMessage.h"
#include "Steering.h"
#include "BlendedSteering.h"
#include "BehaviorandWeight.h"
#include "CollisionAvoidance.h"
#include "Cohesion.h"
#include "Separation.h"
#include "Allignment.h"
#include "VelocityMatching.h"
#include "WallDetection.h"
#include "KinematicWanderSteering.h"
#include "DynamicWanderAndSeek.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "WallUnit.h"
#include "PickupUnit.h"
#include "Graph.h"
#include "Node.h"
#include "WanderToNode.h"
#include "PoliceSteering.h"
#include "PoliceSeek.h"
#include "PoliceFlee.h"

// Message headers
#include "GameMessage.h"
#include "GameMessageManager.h"
#include "UpdateUnitUiMessage.h"

UnitManager::UnitManager()
{

	mpPlayerSprite = SPRITE_MANAGER->getSprite(PLAYER_ICON_SPRITE_ID);
	mpEnemySprite = SPRITE_MANAGER->getSprite(AI_ICON_SPRITE_ID);

   WallUnit* pWall = new WallUnit(Vector2D(450, 450), Vector2D(500, 500), 0);
   mpWalls.push_back(pWall);

   pWall = new WallUnit(Vector2D(650, 650), Vector2D(500, 500), 1);
   mpWalls.push_back(pWall);

   WallUnit* pDoor = new WallUnit(Vector2D(480, 0), Vector2D(544, 18), 0);
   mpDoors.push_back(pDoor);

   pDoor = new WallUnit(Vector2D(480, 768), Vector2D(544, 736), 0);
   mpDoors.push_back(pDoor);

   pDoor = new WallUnit(Vector2D(480, 0), Vector2D(544, 18), 1);
   mpDoors.push_back(pDoor);

   pDoor = new WallUnit(Vector2D(480, 768), Vector2D(544, 736), 1);
   mpDoors.push_back(pDoor);

  


  

	Vector2D vel(0, 0);
	Vector2D pos(180, 180);
	mpPlayer = new Player(mpPlayerSprite, pos, 3.14, vel, 0, 180.0f, 100.0f);

	Vector2D nodePos = GRAPH->getNode(0)->getPosision();
	KinematicUnit* pUnit = new KinematicUnit(mpEnemySprite, nodePos, 3.14, vel, 0,  0, 144, 80);
	mpUnits.push_back(pUnit);

	PoliceSteering* pPoliceSteering = new PoliceSteering(pUnit);
	pUnit->setSteering(pPoliceSteering);

	pUnit = new KinematicUnit(mpEnemySprite, nodePos, 3.14, vel, 0, 0, 144, 80);
	mpUnits.push_back(pUnit);

	PoliceFlee* pPoliceFlee = new PoliceFlee(pUnit, mpPlayer, 5);
	//PoliceSeek* pPoliceSeek = new PoliceSeek(pUnit, mpPlayer, 5);
	pUnit->setSteering(pPoliceFlee);

	pUnit = NULL;
	pPoliceSteering = NULL;
	//pPoliceSeek = NULL;




	PickupUnit* pPickup = new PickupUnit(GRAPH->getNode(4)->getPosision(), 20, 0,  0);
	mpPickups.push_back(pPickup);

	srand(time(NULL));
	
}

UnitManager::~UnitManager()
{
	cleanup();
}

void UnitManager::addUnit(KinematicUnit* newUnit)
{
	mpUnits.push_back(newUnit);
}

void UnitManager::addWall(WallUnit* newUnit)
{
	mpWalls.push_back(newUnit);
}

void UnitManager::addWater(WallUnit* newUnit)
{
   mpWater.push_back(newUnit);
}

void UnitManager::addPickup(PickupUnit* newUnit)
{
   mpPickups.push_back(newUnit);
}

/*Update the units with new steering values, get their steering, and draw them*/
void UnitManager::updateUnits(float time)
{

	mpPlayer->update(time);
	mpPlayer->draw(GRAPHICS_SYSTEM->getBackBuffer());


	// update and draw police
	for (unsigned int i = 0; i < mpUnits.size(); i++)
	{
		mpUnits[i]->update(time);
		mpUnits[i]->draw(GRAPHICS_SYSTEM->getBackBuffer());
	}

   // draw walls
   for (unsigned int i = 0; i < mpWalls.size(); i++)
   {
      mpWalls[i]->draw(gpGame->getCurrentLevel());
   }

   // draw water
   for (unsigned int i = 0; i < mpWater.size(); i++)
   {
      mpWater[i]->draw(gpGame->getCurrentLevel());
   }

   // draw doors
   for (unsigned int i = 0; i < mpDoors.size(); i++)
   {
	   mpDoors[i]->draw(gpGame->getCurrentLevel());
   }

   // draw consumables
   for (unsigned int i = 0; i < mpPickups.size(); i++)
   {
	   mpPickups[i]->update();
      mpPickups[i]->draw();
   }

}

/*Destroys the objects in the Unit manager's vectors*/
void UnitManager::cleanup()
{
   if (mpPlayer != NULL)
	   delete mpPlayer;
	
	for (unsigned int i = 0; i < mpUnits.size(); i++)
	{
		delete mpUnits[i];
	}

   for (unsigned int i = 0; i < mpWalls.size(); i++)
   {
      delete mpWalls[i];
   }

   for (unsigned int i = 0; i < mpWater.size(); i++)
   {
      delete mpWater[i];
   }

   for (unsigned int i = 0; i < mpPickups.size(); i++)
   {
      delete mpPickups[i];
   }
}

std::vector<KinematicUnit*> UnitManager::getUnitList()
{
	return mpUnits;
}

KinematicUnit* UnitManager::getKinematicUnit(int index)
{
	return mpUnits[index];
}

WallUnit* UnitManager::getWallUnit(int index)
{
	return mpWalls[index];
}

WallUnit* UnitManager::getWaterUnit(int index)
{
   return mpWater[index];
}

WallUnit* UnitManager::getDoorUnit(int index)
{
	return mpDoors[index];
}

PickupUnit* UnitManager::getPickupUnit(int index)
{
   return mpPickups[index];
}

int UnitManager::getNumOfWalls()
{
	return mpWalls.size();
}

//Create a pickup unit using the debugger
void UnitManager::createPickupUnit(Vector2D mousePos, int diameter, int mode, int level)
{
	PickupUnit* pPickup = new PickupUnit(mousePos, diameter, mode, level);
	mpPickups.push_back(pPickup);
}