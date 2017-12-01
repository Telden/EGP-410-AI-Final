#pragma once
#include "GameMessage.h"

class MovementMessage:public GameMessage
{
public:
	MovementMessage(char input, bool isPressed);
	~MovementMessage();

	void process();

private:
	char mInput;
	bool mIsPressed;
	


	
};
