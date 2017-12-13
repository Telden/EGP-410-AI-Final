#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "Trackable.h"
#include <vector>
#include <string>

#include "allegro5\allegro_audio.h"

struct AudioClip;

class AudioManager : public Trackable
{
   public:
      AudioManager();
      ~AudioManager();

      void AddClip(std::string name, std::string path);
      void PlayClip(std::string name);
      void AddMusic(std::string path);

   private:
      std::vector<AudioClip> clips;
      ALLEGRO_SAMPLE* mpMusic;
};

struct AudioClip
{
   std::string name;
   ALLEGRO_SAMPLE* sample;

   AudioClip(std::string nme, ALLEGRO_SAMPLE* smple)
   {
      name = nme;
      sample = smple;
   }
};

#endif // !AUDIOMANAGER_H