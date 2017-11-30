#include "EnemySteeringComponent.h"

EnemySteeringComponent::EnemySteeringComponent(Unit* mpMyUnit)
{
	mConnections.push_back(Vector2D(0, 1)); // wander to chase
	mConnections.push_back(Vector2D(1, 0)); // chase to wander

	mConnections.push_back(Vector2D(1, 2)); // chase to flee
	mConnections.push_back(Vector2D(2, 1)); // flee to chase

	mConnections.push_back(Vector2D(0, 2)); // wander to flee
	mConnections.push_back(Vector2D(2, 0)); // flee to wander

	mConnections.push_back(Vector2D(0, 3)); // wander to dead
	mConnections.push_back(Vector2D(1, 3)); // chase to dead
	mConnections.push_back(Vector2D(2, 3)); // flee to dead

	mConnections.push_back(Vector2D(3, 0)); // dead to wander, in case we need it

	mCurrentState = mStates.Wander;
}

EnemySteeringComponent::~EnemySteeringComponent()
{

}

void EnemySteeringComponent::update()
{
	switch (mCurrentState)
	{
		case 0:
		{
			Wander();
		}
		case 1:
		{
			Chase();
		}
		case 2:
		{
			Flee();
		}
		case 3:
		{
			Dead();
		}
		default:
		{
			// not a valid state
		}
	}
}

void EnemySteeringComponent::handleEvent(const Event& theEvent)
{

}

void EnemySteeringComponent::Wander()
{

}

void EnemySteeringComponent::Chase()
{

}

void EnemySteeringComponent::Flee()
{

}

void EnemySteeringComponent::Dead()
{
	// um...this object is dead
}