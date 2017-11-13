#pragma once

#include "Event.h"

class ChangeDifficultyEvent : public Event
{
public:
	ChangeDifficultyEvent(int value, std::string name);
	~ChangeDifficultyEvent();

	int getValue() const { return mValue; }
	std::string getName() const { return mName; }

private:
	int mValue;
	std::string mName;
};