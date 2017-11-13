#include "AudioSystem.h"
#include "EventSystem.h"
#include "Event.h"
#include <iostream>
#include <string>
#include <fstream>

#include "PlayAudioEvent.h"

////https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.html  <- this has everyting needed for this class
//http://noproblo.dayjo.org/ZeldaSounds/
AudioSystem* AudioSystem::mpAudioInstance = nullptr;

AudioSystem::AudioSystem()
{
	std::ifstream inputF;
	std::string temp;

	//Sound Events
	gpEventSystem->addListener(OPEN_DOOR_EVENT, this);
	gpEventSystem->addListener(PLAY_AUDIO_EVENT, this);
	gpEventSystem->addListener(STOP_MUSIC_EVENT, this);


	//Initialize Audio
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		std::cout << "Audio failed to initialize\n";
	}
	
	Mix_Init(MIX_INIT_MP3);

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		std::cout << "Audio channel failed to initialize\n";
	}
	//Set up channels
	Mix_AllocateChannels(16);

	//Load audio files
	inputF.open(AUDIO_PATH);
	{
		getline(inputF, temp);
		const char* DoorPath = temp.c_str();
		Mix_Chunk* sample = Mix_LoadWAV(DoorPath);
		addAudio("Door Unlock", sample);

		getline(inputF, temp);
		const char* EnemyDeathPath = temp.c_str();
		sample = Mix_LoadWAV(EnemyDeathPath);
		addAudio("Enemy_Died", sample);

		getline(inputF, temp);
		const char* EnemyHitPath = temp.c_str();
		sample = Mix_LoadWAV(EnemyHitPath);
		addAudio("Enemy Hit", sample);

		getline(inputF, temp);
		const char* FanfarePath = temp.c_str();
		sample = Mix_LoadWAV(FanfarePath);
		addAudio("Fanfare", sample);
		
		getline(inputF, temp);
		const char* keyPath = temp.c_str();
		sample = Mix_LoadWAV(keyPath);
		addAudio("Key", sample);

		getline(inputF, temp);
		const char* LinkDiePath = temp.c_str();
		sample = Mix_LoadWAV(LinkDiePath);
		addAudio("Link_Died", sample);

		getline(inputF, temp);
		const char* LinkHurtPath = temp.c_str();
		sample = Mix_LoadWAV(LinkHurtPath);
		addAudio("Link_Hurt", sample);

		getline(inputF, temp);
		const char* SecretPath = temp.c_str();
		sample = Mix_LoadWAV(SecretPath);
		addAudio("Secret", sample);


		getline(inputF, temp);
		const char* AttackPath = temp.c_str();
		sample = Mix_LoadWAV(AttackPath);
		addAudio("Attack", sample);

		getline(inputF, temp);
		const char* ClappingPath = temp.c_str();
		sample = Mix_LoadWAV(ClappingPath);
		addAudio("Clapping", sample);

		getline(inputF, temp);
		const char* BossHitPath = temp.c_str();
		sample = Mix_LoadWAV(BossHitPath);
		addAudio("BossHit", sample);

		getline(inputF, temp);
		const char* BossDiesPath = temp.c_str();
		sample = Mix_LoadWAV(BossDiesPath);
		addAudio("BossDies", sample);

		getline(inputF, temp);
		const char* dungeonPath = temp.c_str();
		std::cout << dungeonPath << std::endl;
		mpDungeonMusic = Mix_LoadMUS(dungeonPath);

		getline(inputF, temp);
		const char* titlePath = temp.c_str();
		std::cout << titlePath << std::endl;
		mpTitleMusic = Mix_LoadMUS(titlePath);
	
		
	}
	inputF.close();

	//Start up the title Screen Music
	titleScreenMusic();

}

//clear all music and sound files and close the audio system
AudioSystem::~AudioSystem()
{
	
	clear();
	Mix_CloseAudio();
}

//Non-Lazy initialization
void AudioSystem::initInstance()
{
	mpAudioInstance = new AudioSystem;
}

//Clean up the audioSystem
void AudioSystem::deleteInstance()
{
	delete mpAudioInstance;
}

//Getting the audio system instance
AudioSystem* AudioSystem::getInstance()
{
	SDL_assert(mpAudioInstance != nullptr);
	return mpAudioInstance;
}

//Add sound effects 
void AudioSystem::addAudio(std::string key, Mix_Chunk* newAudio)
{
	mpAudio.insert(std::pair<AudioKey, Mix_Chunk*>(key, newAudio));
}

//Get a audio sound
Mix_Chunk* AudioSystem::getAudio(const AudioKey& key)
{
	std::map<AudioKey, Mix_Chunk*>::iterator iter = mpAudio.find(key);
	if (iter != mpAudio.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}

//Clean up all of the music and sound clips
void AudioSystem::clear()
{
	Mix_FreeMusic(mpDungeonMusic);
	Mix_FreeMusic(mpTitleMusic);

	std::map<AudioKey, Mix_Chunk*>::iterator iter;
	for (iter = mpAudio.begin(); iter != mpAudio.end(); ++iter)
	{
		Mix_FreeChunk(iter->second);
	}
	mpAudio.clear();
}

//Play a specific sound
void AudioSystem::playSound(std::string soundName)
{
	if (Mix_PlayChannel(-1, getAudio(soundName), 0) < 0)
	{
		std::cout << "Audio " << soundName << "could not be played\n";
	}
}

//Play the dungeon music
void AudioSystem::dungeonMusic()
{


	Mix_FadeOutMusic(2000);

	Mix_HaltMusic();

	Mix_FadeInMusic(mpDungeonMusic, -1, 5000);	
	mpCurrentSong = mpDungeonMusic;
}

//Player the dungeon Music
void AudioSystem::titleScreenMusic()
{
	if (Mix_PlayingMusic())
	{
		Mix_HaltMusic();
	}

	Mix_PlayMusic(mpTitleMusic, -1);
	mpCurrentSong = mpTitleMusic;
}

//Stop the music
void AudioSystem::stopMusic()
{
	Mix_HaltMusic();

}

//Resume the last song
void AudioSystem::resumeCurrentMusic()
{
	Mix_PlayMusic(mpCurrentSong, -1);
}

//Handle all of the audio system's event listeners
void AudioSystem::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == OPEN_DOOR_EVENT)
		playSound("Door Unlock");

	else if (theEvent.getType() == PLAY_AUDIO_EVENT)
	{
		const PlayAudioEvent& playAudioEvent = static_cast<const PlayAudioEvent&>(theEvent);

		playSound(playAudioEvent.getName());
	}
	else if (theEvent.getType() == STOP_MUSIC_EVENT)
	{
		if (!mIsStopped)
		{
			stopMusic();
			mIsStopped = true;
		}
			
		else
		{
			resumeCurrentMusic();
			mIsStopped = false;
		}
			
	}
}