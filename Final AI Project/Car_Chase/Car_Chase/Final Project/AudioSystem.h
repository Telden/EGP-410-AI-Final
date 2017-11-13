#pragma once
#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include "SDL_lib.h"
#include <SDL_mixer.h>
#include "Trackable.h"
#include "EventListener.h"
#include <vector>
#include <map>

typedef std::string AudioKey;
//http://soundprogramming.net/programming/tutorial-using-sdl2-and-sdl_mixer-to-play-samples/
//http://lazyfoo.net/SDL_tutorials/lesson11/
class AudioBuffer;

class AudioSystem :public EventListener
{

private:
	//The instance of the audioSystem
	static AudioSystem* mpAudioInstance;
	const std::string AUDIO_PATH = "Data/audiopaths.txt";
	std::map<AudioKey, Mix_Chunk*>mpAudio;
	Mix_Music* mpDungeonMusic;
	Mix_Music* mpTitleMusic;
	Mix_Music* mpCurrentSong;
	bool mIsStopped = false;

public:

	AudioSystem();
	~AudioSystem();

	//instance functions
	static void initInstance();
	static void deleteInstance();
	static AudioSystem* getInstance();
	
	//Map Functions
	void addAudio(std::string key, Mix_Chunk* newAudio);
	Mix_Chunk* getAudio(const AudioKey& key);
	void clear();

	//Sound Related functions
	void playSound(std::string soundName);
	void titleScreenMusic();
	void dungeonMusic();
	void stopMusic();
	void resumeCurrentMusic();
	void handleEvent(const Event& theEvent);
};

#endif 