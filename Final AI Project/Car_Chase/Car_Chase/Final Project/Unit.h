#pragma once

#ifndef UNIT_H
#define UNIT_H

#include "Trackable.h"


class GraphicsSystem;
class AnimationManager;

#include "Animation.h"

class Unit : public Trackable
{
	private :
		// LOCATION
		int mLocX, mLocY;

		// ANIMATION
		AnimationManager* mpAnimationManager;
		Animation mAnimation;

		// GRAPHICS SYSTEM
		GraphicsSystem* mp_GS;

		// IF THE OBJECT IS DESTUCTABLE, THIS COMES IN HANDY
		bool isActive;

		/*
		// ADD KINEMATIC UNIT THINGS HERE SUCH AS VELOCITY AND ACCELERATION
		Vector2D mCurVelocity;
		float mMaxVelocity;
		float mMaxAcceleration;
		float mOrientation;
		float mRotationalVelocity;
		*/

	public :
		Unit();
		Unit(int locX, int locY);
		~Unit();

		// ACCESSORS
		int getLocX() { return mLocX; }
		int getLocY() { return mLocY; }
		Animation& getAnimation() { return mAnimation; }
		AnimationManager* getAnimationManager() { return mpAnimationManager; }
		GraphicsSystem* getGraphicsSystem() { return mp_GS; }
		bool getIsActive() { return isActive; }
		/*
		Vector2D getCurVelocity() { return mCurVelocity; }
		float getMaxVelocity() { return mMaxVelocity; }
		float getMaxAcceleration() { return mMaxAcceleration; }
		float getOrienation() { return mOrientation; }
		float getRotationalVelocity() { return mRotationalVelocity; }
		*/

		// MUTATORS
		void setLocX(int newValue) { mLocX = newValue; }
		void setLocY(int newValue) { mLocY = newValue; }
		void setAnimation(Animation newValue) { mAnimation = newValue; }
		void setIsActive(bool newValue) { isActive = newValue; }
		/*
		void setCurVelocity(Vector2D newVal) { mCurVelocity = newVal; }
		void setMaxVelocity(float newVal) { mMaxVelocity = newVal; }
		void setMaxAcceleration(float newVal) { mMaxAcceleration = newVal; }
		void setOrienation(float newVal) { mOrientation = newVal; }
		void setRotationalVelocity(float newVal) { mRotationalVelocity = newVal; }
		*/

		// VIRTUAL FUNCTION
		virtual void render();
		virtual void update();
};

#endif