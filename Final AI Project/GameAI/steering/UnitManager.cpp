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

// Message headers
#include "GameMessage.h"
#include "GameMessageManager.h"
#include "UpdateUnitUiMessage.h"

UnitManager::UnitManager()
{
	mpEnemySprite = SPRITE_MANAGER->getSprite(AI_ICON_SPRITE_ID);

	Vector2D vel(1.0f, 1.0f);
	Vector2D pos(0, 0);
	mpPlayer = new Player(mpEnemySprite, pos, 1, vel, 0, 180.0f, 100.0f);


	srand(time(NULL)); //Need to move this out of here

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

/*Update the units with new steering values, get their steering, and draw them*/
void UnitManager::updateUnits(float time)
{

	mpPlayer->update(time);
	mpPlayer->draw(GRAPHICS_SYSTEM->getBackBuffer());


	/* Update Police Cars */
	/*for (int i = 0; i < mpUnits.size(); i++)
	{
	
		mpUnits[i]->update(time);
		mpUnits[i]->draw(GRAPHICS_SYSTEM->getBackBuffer());

	}*/

	
	/*	if (mShouldUpdate)
	{
	mpUnits[i]->setRotationalVelocity(mAngularVelocity);
	mpUnits[i]->setMaxVelocity(mEnemyVelocity);
	mpUnits[i]->getSteering()->setRadius(mReactionRadius);
	}*/
	/*if (mShouldUpdate)
		mShouldUpdate = false;*/

	
}

/*Destroys the objects in the Unit manager's vectors*/
void UnitManager::cleanup()
{

	
	for (int i = 0; i < mpUnits.size(); i++)
	{
		delete mpUnits[i];

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

int UnitManager::getNumOfWalls()
{
	return mpWalls.size();
}

/* Updates values on the debug UI*/
void UnitManager::updateUI()
{
	//GameMessage* pMessage = new UpdateUnitUiMessage(mReactionRadius, mAngularVelocity, mEnemyVelocity, *mCohesionWeight, *mSepareationWeight, *mAllignmentWeight);
	//MESSAGE_MANAGER->addMessage(pMessage, 0);
}








/*Recieves messages from the input manager and adjusts the selected unit attribute*/
//void UnitManager::updateUnitValues(bool shouldIncrease, char currentSelection)
//{
//	
//	if (shouldIncrease)
//	{
//
//		// increase selected value
//		switch (currentSelection)
//		{
//		case 'V':
//			//Increase velocity
//			printf("increaseing enemy velocity");
//			mEnemyVelocity += mINCREASE_VALUE;
//			mShouldUpdate = true;
//			break;
//		case 'R':
//			//increase reaction radius
//			printf("increaseing reaction radius");
//			mReactionRadius += mINCREASE_VALUE;
//			mShouldUpdate = true;
//			break;
//		case 'G':
//			//Increase angular velocity
//			printf("increaseing angular velocity");
//			mAngularVelocity += mINCREASE_VALUE;
//			mShouldUpdate = true;
//			break;
//		case 'C':
//			//Increase cohesion weight
//			mCohesionWeight += mINCREASE_VALUE;
//			break;
//		case 'S':
//			//Increase separation weight
//			mSepareationWeight += mINCREASE_VALUE;
//			break;
//		case 'A':
//			//increase allignment weight
//			mAllignmentWeight += mINCREASE_VALUE;
//			break;
//		case 'W':
//			//increase allignment weight
//			*mpWalls = true;
//			break;
//		default:
//			printf("Something went wrong in the increasing value switch of the change unit value message");
//		}
//
//	}
//	else
//	{
//		// decrease selected value
//		switch (currentSelection)
//		{
//		case 'V':
//			// decrease velocity
//			mEnemyVelocity -= mINCREASE_VALUE;
//			mShouldUpdate = true;
//			break;
//		case 'R':
//			// decrease reaction radius
//			mReactionRadius -= mINCREASE_VALUE;
//			mShouldUpdate = true;
//			break;
//		case 'G':
//			// decrease angular velocity
//			mAngularVelocity -= mINCREASE_VALUE;
//			mShouldUpdate = true;
//			break;
//			// decrease cohesion weight
//		case 'C':
//			mCohesionWeight -= mINCREASE_VALUE;
//			break;
//			// decrease separation weight
//		case 'S':
//			mSepareationWeight -= mINCREASE_VALUE;
//			break;
//			// decrease allignment weight
//		case 'A':
//			mAllignmentWeight -= mINCREASE_VALUE;
//			break;
//		case 'W':
//			//increase allignment weight
//			*mpWalls = false;
//			break;
//		default:
//			printf("Something went wrong in the decreaseing value switch of the change unit value message");
//		}
//	}
//}

//void UnitManager::SaveSettings()
//{
//	std::ofstream oFile;
//	oFile.open(UNIT_VALUES_FILEPATH);
//
//	if (oFile.is_open())
//	{
//		oFile << mReactionRadius << "\n";
//		oFile << mAngularVelocity << "\n";
//		oFile << mEnemyVelocity << "\n";
//		oFile << mMaxAcceleration << "\n";
//		oFile << *mSepareationWeight << "\n";
//		oFile << *mCohesionWeight << "\n";
//		oFile << *mVelocityMatchingWeight << "\n";
//		oFile << *mAllignmentWeight << "\n";
//		oFile << *mWanderWeight << "\n";
//		oFile << *mWallAvoidanceWeight << "\n";
//		oFile << *mCollisionAvoidanceWeight << "\n";
//	}
//
//	oFile.close();
//	printf("Saved Successfully");
//}




//void UnitManager::createDynamicArriveUnit()
//{
//	Vector2D mPos = mpUnits[0]->getPosition();
//	mPos.setX(mPos.getX() + 200);
//	Vector2D vel(0.0f, 0.0f);
//	KinematicUnit* mpAIUnit = new KinematicUnit(mpEnemySprite, mPos, 1, vel, mAngularVelocity, mEnemyVelocity, mMaxAcceleration);
//	mpAIUnit->dynamicArrive(&*mpUnits[0]);
//	addUnit(mpAIUnit);
//	mpAIUnit = NULL;
//}
//
//void UnitManager::createDynamicSeekUnit()
//{
//	Vector2D mPos = mpUnits[0]->getPosition();
//	mPos.setX(mPos.getX() - 100);
//	Vector2D vel(0.0f, 0.0f);
//	KinematicUnit* mpAIUnit = new KinematicUnit(mpEnemySprite, mPos, 1, vel, mAngularVelocity, mEnemyVelocity, mMaxAcceleration);
//	mpAIUnit->dynamicSeek(mpUnits[0]);
//	addUnit(mpAIUnit);
//	mpAIUnit = NULL;
//}
//
//void UnitManager::createDynamicWanderSeekUnit()
//{
//	Vector2D mPos = mpUnits[0]->getPosition();
//	mPos.setX(mPos.getX() - 200);
//	Vector2D vel(0.0f, 0.0f);
//	KinematicUnit* mpAIUnit = new KinematicUnit(mpEnemySprite, mPos, 1, vel, mAngularVelocity, mEnemyVelocity, mMaxAcceleration);
//	mpAIUnit->dynamicWanderandSeek(mpUnits[0], mReactionRadius);
//	//BlendedSteering* pBlendedSteering = mpAIUnit->blendedSteering(mpAIUnit);
//	//BehaviorAndWeight* pBAW = new BehaviorAndWeight(mpAIUnit->dynamicWanderandSeek(mpUnits[0], mReactionRadius), 0.05f);
//	//pBlendedSteering->addBehaviorAndWeight(pBAW);
//	//pBAW = new BehaviorAndWeight(mpAIUnit->collisionAvoidance(mpAIUnit, mReactionRadius), 2.0f);
//	//pBlendedSteering->addBehaviorAndWeight(pBAW);
//	 
//	addUnit(mpAIUnit);
//	mpAIUnit = NULL;
//	//pBlendedSteering = NULL;
//	//pBAW = NULL;
//}
//
//void UnitManager::createDynamicWanderFleeUnit()
//{
//	Vector2D mPos = mpUnits[0]->getPosition();
//	mPos.setX(mPos.getX() - 100);
//	Vector2D vel(0.0f, 0.0f);
//	KinematicUnit* mpAIUnit = new KinematicUnit(mpEnemySprite, mPos, 1, vel, mAngularVelocity, mEnemyVelocity, mMaxAcceleration);
//	mpAIUnit->dynamicWanderandFlee(mpUnits[0], mReactionRadius);
//	//BlendedSteering* pBlendedSteering = mpAIUnit->blendedSteering(mpAIUnit);
//	//BehaviorAndWeight* pBAW = new BehaviorAndWeight(mpAIUnit->dynamicWanderandFlee(mpUnits[0], mReactionRadius), 0.05f);
//	//pBlendedSteering->addBehaviorAndWeight(pBAW);
//	//pBAW = new BehaviorAndWeight(mpAIUnit->collisionAvoidance(mpAIUnit, mReactionRadius), 2.0f);
//	//pBlendedSteering->addBehaviorAndWeight(pBAW);
//	addUnit(mpAIUnit);
//	mpAIUnit = NULL;
//}