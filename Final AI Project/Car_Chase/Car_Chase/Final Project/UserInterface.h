#pragma once
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Trackable.h"
#include "EventListener.h"


class GraphicsSystem;
class Animation;

class UserInterface :public EventListener
{
private:
	GraphicsSystem* mp_GS;
	Animation* mpUIAnim;

	bool mCanBow = false;
	int mMaxHearts;
	int mNumHearts;
	int mNumEmptyHearts = 0;
	int mNumKey = 0;
	int mHurtWaitAmount = 120;

public:
	UserInterface(GraphicsSystem* gs);
	~UserInterface();

	void handleEvent(const Event& theEvent);
	void reset();
	void update();
	void render();

	void updateMaxHealth();
};

#endif