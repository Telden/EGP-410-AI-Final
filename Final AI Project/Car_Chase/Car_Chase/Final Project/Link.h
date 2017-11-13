#pragma once

#ifndef UNITLINK_H
#define UNITLINK_H

#include "Unit.h"
#include "LinkComponent.h"

class Animation;

class Link : public Unit
{
	private :
		

		LinkComponent* mpLinkComponent;

	public :
		Link(int locX, int locY);
		Link(int locX, int locY, int numkeys, int numHealth, int maxHealth, std::string direction, bool bow );
		~Link();

		void render();
		void update();

		Unit* getSword() { return mpLinkComponent->getSword(); }
		Unit* getArrow() { return mpLinkComponent->getArrow(); }
		std::string getDirection() { return mpLinkComponent->getDirectionFacing(); }
		int getNumKeys() { return mpLinkComponent->getnumKeys(); }
		int getCurrentHealth() { return mpLinkComponent->getCurrentHealth(); }
		int getMaxHealth() { return mpLinkComponent->getMaxHealth(); }
		bool getBowBool() { return mpLinkComponent->getCanBow(); }

		void setNumKeys(int numKeys) { mpLinkComponent->setnumKeys(numKeys); }
		void setCurrentHealth(int numHealth) { mpLinkComponent->setMaxHealth(numHealth); }
		void setMaxHealth(int maxHealth) { mpLinkComponent->setMaxHealth(maxHealth); }
		void setcanBow(bool canBow) { mpLinkComponent->setCanBow(canBow); }
};

#endif