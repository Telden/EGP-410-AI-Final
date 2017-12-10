#pragma once
#include "GameMessage.h"
#include "Vector2D.h"

class DeleteNodeMessage : public GameMessage
{
public:
	DeleteNodeMessage(Vector2D mousePos);
	~DeleteNodeMessage();

	void process();

private:
	Vector2D mMousePos;
};