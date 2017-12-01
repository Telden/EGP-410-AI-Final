#pragma once
#include "GameMessage.h"

class UpdateUnitUiMessage : public GameMessage
{
private:
	float mReationRadius, mAngularVelocity, mEnemyVelocity, mCohesionWeight, mSeparationWeight, mAllignmentWeight;

public:
	UpdateUnitUiMessage(float reactionRadius, float angularVelocity, float enemyVelocity,  float cohesionWeight, float separationWeight,  float allignmentWeight);
	~UpdateUnitUiMessage();

	void process();

};