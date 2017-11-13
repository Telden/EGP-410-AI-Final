#pragma once

#ifndef FIREBALL_H
#define FIREBALL_H

#include "Unit.h"

class ScaryComponent;
class RenderComponent;

class Fireball : public Unit
{
private:
	const std::string FIREBALLANIMNAME = "Fireball";

	ScaryComponent* mpScaryComponent;
	RenderComponent* mpRenderComponent;

public:
	Fireball(int locX, int locY);
	~Fireball();

	void render();
	void update();
};

#endif