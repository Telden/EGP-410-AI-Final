#pragma once

#ifndef AQUAMENTUS_H
#define AQUAMENTUS_H

#include "Unit.h"
#include "AquamentusComponent.h"
#include "RenderComponent.h"
#include "ScaryComponent.h"

class Aquamentus : public Unit
{
	private:
		const std::string AQUAMENTUSANIMNAME = "Dragon";
		AquamentusComponent* mpAquamentusComponent;
		RenderComponent* mpRenderComponent;
		ScaryComponent* mpScaryComponent;

	public:
		Aquamentus(int locX, int locY);
		~Aquamentus();

		void render();
		void update();
};

#endif