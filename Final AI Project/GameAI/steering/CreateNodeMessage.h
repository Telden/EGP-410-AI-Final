#pragma once
#include "GameMessage.h"
#include "Vector2D.h"

class CreateNodeMessage : public GameMessage
{
public:
	CreateNodeMessage(Vector2D mousePos);
	~CreateNodeMessage();

	void process();
private:
	Vector2D mMousePos;
};