#include "Game.h"
#include "GameMessageManager.h"
#include "UpdateUnitUiMessage.h"
#include "UiManager.h"

UpdateUnitUiMessage::UpdateUnitUiMessage(float reactionRadius, float angularVelocity, float enemyVelocity, float cohesionWeight, float separationWeight, float allignmentWeight) 
	: GameMessage(UPDATE_UNIT_UI_MESSAGE)
{
	mReationRadius = reactionRadius;
	mAngularVelocity = angularVelocity;
	mEnemyVelocity = enemyVelocity;
	mCohesionWeight = cohesionWeight;
	mSeparationWeight = separationWeight;
	mAllignmentWeight = allignmentWeight;
}

UpdateUnitUiMessage::~UpdateUnitUiMessage()
{

}

void UpdateUnitUiMessage::process()
{
	UI_MANAGER->updateUnitUiInformation(mReationRadius, mAngularVelocity, mEnemyVelocity, mCohesionWeight, mSeparationWeight, mAllignmentWeight);
}