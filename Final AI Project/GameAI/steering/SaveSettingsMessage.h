#pragma once
#include "GameMessage.h"

class SaveSettingsMessage : public GameMessage
{
public:
	SaveSettingsMessage();
	~SaveSettingsMessage() {};

	void process();
};