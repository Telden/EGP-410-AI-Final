#include "PlaySoundMessage.h"

#include "Game.h"
#include "AudioManager.h"

PlaySoundMessage::PlaySoundMessage(std::string soundName) : GameMessage(PLAY_SOUND_MESSAGE)
{
   mName = soundName;
}

PlaySoundMessage::~PlaySoundMessage()
{

}

void PlaySoundMessage::process()
{
   AUDIO_MANAGER->PlayClip(mName);
}