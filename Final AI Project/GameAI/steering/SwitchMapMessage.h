#pragma once
#include "GameMessage.h"

class SwitchMapMessage : public GameMessage
{
public:
	SwitchMapMessage();
	~SwitchMapMessage() {};

	void process();
};