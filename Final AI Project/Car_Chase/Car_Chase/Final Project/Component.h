#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include "Trackable.h"

#include "Event.h"
#include "EventSystem.h"
#include "EventListener.h"

#include "Game.h"
#include "LevelManager.h"
#include "PlayAudioEvent.h"

class Component : public EventListener
{
	private :

	public :
		Component() {};
		~Component() {};

		virtual void render() { std::cout << "component render" << std::endl; };
		virtual void update() { std::cout << "component update" << std::endl; };
		virtual bool getIsSolid() { return false; }
};

#endif