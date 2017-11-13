#pragma once

#ifndef ENEMYSTALFOS_H
#define ENEMYSTALFOS_H

#include "Unit.h"
#include "StalfosComponent.h"
#include "RenderComponent.h"
#include "CanGetKilledComponent.h"
#include "ScaryComponent.h"
#include "DropComponent.h"

class EnemyStalfos : public Unit
{
	private:
		const std::string STALFOSANIMNAME = "Stalfos";
		bool mIsDropping;
		StalfosComponent* mpStalfosComponent;
		RenderComponent* mpRenderComponent;
		CanGetKilledComponent* mpCanGetKilledComponent;
		ScaryComponent* mpScaryComponent;
		DropComponent* mpDropComponent;

	public:
		EnemyStalfos(int locX, int locY, bool isDropping);
		~EnemyStalfos();

		bool getIsDropping() { return mIsDropping; }
		void render();
		void update();
};

#endif