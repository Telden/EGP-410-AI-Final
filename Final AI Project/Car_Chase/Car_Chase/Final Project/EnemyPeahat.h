#pragma once

#ifndef ENEMYPEAHAT_H
#define ENEMYPEAHAT_H

#include "Unit.h"
#include "PeahatComponent.h"
#include "RenderComponent.h"
#include "CanGetKilledByArrowComponent.h"
#include "ScaryComponent.h"
#include "DropComponent.h"

class EnemyPeahat : public Unit
{
private:
	const std::string PEAHATANIMNAME = "Peahat";
	bool mMoveHorizontal;
	PeahatComponent* mpPeahatComponent;
	RenderComponent* mpRenderComponent;
	CanGetKilledByArrowComponent* mpCanGetKilledByArrowComponent;
	ScaryComponent* mpScaryComponent;

public:
	EnemyPeahat(int locX, int locY, bool moveHorizontal);
	~EnemyPeahat();
	
	bool getMoveHorizontal() { return mMoveHorizontal; }
	void render();
	void update();
};

#endif