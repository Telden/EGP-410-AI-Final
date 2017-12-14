#pragma once
#include "GameMessage.h"
#include "Vector2D.h"

class CreatePickupMessage : public GameMessage
{
private:
	Vector2D mMousePos;
	int mDiameter;
	int mMode;
	int mLevel;
public:
	CreatePickupMessage(Vector2D mousePos, int diameter, int mode, int level);
	~CreatePickupMessage() {};

	void process();

};