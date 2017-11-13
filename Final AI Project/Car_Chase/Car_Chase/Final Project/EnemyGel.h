#pragma once
#ifndef ENEMY_GEL_H
#define ENEMY_GEL_H

#include "Unit.h"
#include "RenderComponent.h"
#include "StalfosComponent.h"
#include "CanGetKilledComponent.h"
#include "ScaryComponent.h"

class EnemyGel : public Unit
{
private:
	const std::string GELANIMNAME = "Gel";
	StalfosComponent* mpStalfosComponent;
	RenderComponent* mpRenderComponent;
	CanGetKilledComponent* mpCanGetKilledComponent;
	ScaryComponent* mpScaryComponent;

public:
	EnemyGel(int locX, int locY);
	~EnemyGel();

	void render();
	void update();
};


#endif 