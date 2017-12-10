#pragma once
#include "GameMessage.h"

class UpdateMouseUiMessage : public GameMessage
{
private:
	Vector2D mMousePos;
	
public:
	UpdateMouseUiMessage(Vector2D);
	~UpdateMouseUiMessage();

	void process();
};