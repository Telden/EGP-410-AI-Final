#pragma once

#include "Event.h"

class PlayAudioEvent : public Event
{
public:
	PlayAudioEvent(std::string name);
	~PlayAudioEvent();

	std::string getName() const { return mName; }

private:
	std::string mName;
};