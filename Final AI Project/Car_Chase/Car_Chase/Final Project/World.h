#pragma once
#ifndef WORLD_H
#define WORLD_H
#include "AllegroLib.h"
#include "EventListener.h"
#include "Trackable.h"
#include "EventSystem.h"
#include "Event.h"

class SnakeManager;
class LevelManager;
class Food;
class PowerUp;
class PowerDown;
class UserInterface;
class GraphicsSystem;
//class World : public EventListener
//{
//public:
//	World();
//	~World();
//	void update();
//	void render();
//	void handleEvent(const Event& theEvent);
//	void checkCollisions();
//
//private:
//	SnakeManager* mp_SM;
//	LevelManager* mp_LM;
//	Food* mp_food;
//	PowerUp* mp_powerup;
//	PowerDown* mp_powerDown;
//	UserInterface* mp_UI;
//	GraphicsSystem* mp_GS;
//
//};



#endif