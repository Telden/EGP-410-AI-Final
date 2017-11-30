#ifndef ENEMYSTEERINGCOMPONENT_H
#define ENEMYSTEERINGCOMPONENT_H

#include "Component.h"
#include "Vector2D.h"

class EnemySteeringComponent : public Component
{
	private:
		Unit* mpMyUnit;

		enum mStates { Wander = 0, Chase = 1, Flee = 2, Dead = 3, Total};
		mStates mCurrentState;
		std::vector<Vector2D> mConnections;

	public:

		EnemySteeringComponent(Unit* myUnit);
		~EnemySteeringComponent();

		void update();
		void handleEvent(const Event& theEvent);

		void Wander();
		void Chase();
		void Flee();
		void Dead();
};

#endif