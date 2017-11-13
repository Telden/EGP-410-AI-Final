#pragma once

#ifndef AQUAMENTUSCOMPONENT_H
#define AQUAMENTUSCOMPONENT_H

#include "Component.h"
#include "Animation.h"
#include <time.h>

class Unit;
class EnemyStalfos;
class Animation;
class Fireball;

class AquamentusComponent : public Component
{
	private:
		// the unit this component refers to
		Unit* mpMyUnit;

		Fireball* mpFireball1;
		Fireball* mpFireball2;
		Fireball *mpFireball3;

		// the direction the Stalfos is facing
		std::string mDirectionFacing;

		int mHealth, mMaxHealth = 6;

		int mMovCounter = 0, mMaxMovCounter = 100;
		bool mMovingLeft = true;
		int mMovementSpeed = 1;
		int mShootCounter = 0, mMaxShootCounter = 300;
		bool mShootTopDown = true;
		int mHurtCounter = 0, mMaxHurtCounter = 60;
		bool mJustHurt = false;

	public:
		AquamentusComponent(Unit* myUnit);
		~AquamentusComponent();

		void render();
		void update();

		void changeDirections();
		void movement();
		void moveFireballs();
		void resetFireballs();
		void checkHealth();

		void handleEvent(const Event& theEvent);
};

#endif