#include "AudioManager.h"

AudioManager::AudioManager()
{
   
}

AudioManager::~AudioManager()
{

}

void AudioManager::AddClip(std::string name, std::string path)
{
   // make a temporary audio sample
   ALLEGRO_SAMPLE* tmpSamp = NULL;

   // load it based on file path
   tmpSamp = al_load_sample(path.c_str());

   // check to see if the sound loaded properly
   if (!tmpSamp)
   {
      std::cout << "Audio Manager could not load sound " << name << " at path " << path << std::endl;
   }

   // add it to the vector
   clips.push_back(AudioClip(name, tmpSamp));
}

void AudioManager::PlayClip(std::string name)
{
   for (unsigned int i = 0; i < clips.size(); i++)
   {
      // if the name matches one of the existing clips...
      if (name == clips[i].name)
      {
         // play that sound
         al_play_sample(clips[i].sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
      }
   }
}

void AudioManager::AddMusic(std::string path)
{
   // load the music based on the file path
   mpMusic = al_load_sample(path.c_str());

   // check to see if the music loaded properly
   if (!mpMusic)
   {
      std::cout << "Audio Manager could not load music at path " << path << std::endl;
   }

   // loop the music
   al_play_sample(mpMusic, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}