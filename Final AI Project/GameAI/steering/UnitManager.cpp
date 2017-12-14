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
#include "allegro5\allegro_primitives.h"
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

   // final game walls
   // overworld walls
      // top left
      mpWalls.push_back(new WallUnit(Vector2D(100, 100), Vector2D(462, 334), 0));
      // top right
      mpWalls.push_back(new WallUnit(Vector2D(562, 100), Vector2D(924, 334), 0));
      // bottom left
      mpWalls.push_back(new WallUnit(Vector2D(100, 424), Vector2D(462, 668), 0));
      // bottom right
      mpWalls.push_back(new WallUnit(Vector2D(562, 424), Vector2D(924, 668), 0));
   // underworld walls
      // top
      mpWalls.push_back(new WallUnit(Vector2D(0, 0), Vector2D(1024, 10), 1));
      // bottom
      mpWalls.push_back(new WallUnit(Vector2D(0, 758), Vector2D(1024, 768), 1));
      // left
      mpWalls.push_back(new WallUnit(Vector2D(0, 0), Vector2D(10, 768), 1));
      // right
      mpWalls.push_back(new WallUnit(Vector2D(1014, 0), Vector2D(1024, 768), 1));

   // final game water
   // overworld water
      // top left
      mpWater.push_back(new WallUnit(Vector2D(100, 100), Vector2D(462, 334), 1));
      // top right
      mpWater.push_back(new WallUnit(Vector2D(562, 100), Vector2D(924, 334), 1));
      // bottom left
      mpWater.push_back(new WallUnit(Vector2D(100, 424), Vector2D(462, 668), 1));
      // bottom right
      mpWater.push_back(new WallUnit(Vector2D(562, 424), Vector2D(924, 668), 1));
   // underworld water
      // top
      mpWater.push_back(new WallUnit(Vector2D(0, 0), Vector2D(1024, 10), 0));
      // bottom
      mpWater.push_back(new WallUnit(Vector2D(0, 758), Vector2D(1024, 768), 0));
      // left
      mpWater.push_back(new WallUnit(Vector2D(0, 0), Vector2D(10, 768), 0));
      // right
      mpWater.push_back(new WallUnit(Vector2D(1014, 0), Vector2D(1024, 768), 0));

   // final game doors
   // overworld doors
   WallUnit* pDoor = new WallUnit(Vector2D(480, 0), Vector2D(544, 20), 0);
   mpDoors.push_back(pDoor);
   pDoor = new WallUnit(Vector2D(480, 748), Vector2D(544, 768), 0);
   mpDoors.push_back(pDoor);
   // underworld doors
   pDoor = new WallUnit(Vector2D(480, 0), Vector2D(544, 20), 1);
   mpDoors.push_back(pDoor);
   pDoor = new WallUnit(Vector2D(480, 748), Vector2D(544, 768), 1);
   mpDoors.push_back(pDoor);

   // final player position
	Vector2D vel(0, 0);
	Vector2D pos(512, 512);
	mpPlayer = new Player(mpPlayerSprite, pos, 3.14, vel, 0, 180.0f, 100.0f);

   // final enemy position
	Vector2D nodePos = GRAPH->getNode(0)->getPosision();
	KinematicUnit* pUnit = new KinematicUnit(mpEnemySprite, nodePos, 3.14, vel, 0,  0, 144, 80);
	mpUnits.push_back(pUnit);

   PoliceSteering* pPoliceSteering = new PoliceSteering(pUnit);
   pUnit->setSteering(pPoliceSteering);

	pUnit = new KinematicUnit(mpEnemySprite, nodePos, 3.14, vel, 0, 0, 144, 80);
	mpUnits.push_back(pUnit);

   pPoliceSteering = new PoliceSteering(pUnit);
   pUnit->setSteering(pPoliceSteering);

	pUnit = NULL;
	pPoliceSteering = NULL;
	//pPoliceSeek = NULL;




	PickupUnit* pPickup = new PickupUnit(GRAPH->getNode(4)->getPosision(), 20, 0,  0);
	mpPickups.push_back(pPickup);

   pPickup = new PickupUnit(GRAPH->getNode(3)->getPosision(), 20, 1, 0);
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
      mpWalls[i]->draw(gpGame->getCurrentLevel(), 0);
   }

   // draw water
   for (unsigned int i = 0; i < mpWater.size(); i++)
   {
      mpWater[i]->draw(gpGame->getCurrentLevel(), 1);
   }

   // draw doors
   for (unsigned int i = 0; i < mpDoors.size(); i++)
   {
	   mpDoors[i]->draw(gpGame->getCurrentLevel(), 2);
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

   for (unsigned int i = 0; i < mpDoors.size(); i++)
   {
      delete mpDoors[i];
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