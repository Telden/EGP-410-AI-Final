#include "PlayAudioEvent.h"

PlayAudioEvent::PlayAudioEvent(std::string name)
	:Event(PLAY_AUDIO_EVENT)
	, mName(name)
{
}

PlayAudioEvent::~PlayAudioEvent()
{

}