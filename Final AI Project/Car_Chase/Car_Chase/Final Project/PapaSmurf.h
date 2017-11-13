#pragma once
#ifndef PAPASMURF_H
#define PAPASMURF_H

#include "Unit.h"
class RenderComponent;

class PapaSmurf : public Unit
{
private:
	const std::string SMURFANINNAME = "PapaSmurf";
	RenderComponent* mpRenderComponent;

public:
	PapaSmurf(int locX, int locY);
	~PapaSmurf();

	void render();
};


#endif