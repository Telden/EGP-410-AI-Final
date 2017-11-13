#include "ChangeDifficultyEvent.h"

ChangeDifficultyEvent::ChangeDifficultyEvent(int value, std::string name)
	:Event(CHANGE_DIFFICULTY_EVENT)
	, mValue(value)
	, mName(name)
{
}

ChangeDifficultyEvent::~ChangeDifficultyEvent()
{

}