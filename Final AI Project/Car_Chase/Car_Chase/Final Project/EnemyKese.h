#pragma once

#ifndef ENEMYKESE_H
#define ENEMYKESE_H

#include "Unit.h"
#include "KeseComponent.h"

class RenderComponent;
class ScaryComponent;
class CanGetKilledComponent; 

class EnemyKese : public Unit
{
	private :
		const std::string KESEANIMNNAME = "Kese";
		KeseComponent* mpKeseComponent;
		RenderComponent* mpRenderComponent;
		ScaryComponent* mpScaryComponent;
		CanGetKilledComponent* mpCanGetKilledComponent;

	public :
		EnemyKese(int locX, int locY);
		~EnemyKese();

		void render();
		void update();
};

#endif