#pragma once

#ifndef SWORD_H
#define SWORD_H

#include "Unit.h"


//#include "SwordComponent.h"

class Sword : public Unit
{
private:
	const std::string SWORDANIMNAME = "Sword";
	const int SWORUP = 0;
	const int SWORDDOWN = 1;
	const int SWORDRIGHT = 2;
	const int SWORDLEFT = 3;
	//SwordComponent* mpSwordComponent;

public:
	Sword();
	~Sword();

	void render();
	void update();
};

#endif