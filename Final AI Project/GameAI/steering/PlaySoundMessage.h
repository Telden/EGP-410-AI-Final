#ifndef PLAYSOUNDMESSAGE_H
#define PLAYSOUNDMESSAGE_H

#include "GameMessage.h"

class PlaySoundMessage : public GameMessage
{
public:
   PlaySoundMessage(std::string soundName);
   ~PlaySoundMessage();

   void process();
private:
   std::string mName;
};

#endif