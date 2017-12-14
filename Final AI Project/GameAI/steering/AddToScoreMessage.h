#ifndef ADDTOSCOREMESSAGE_H
#define ADDTOSCOREMESSAGE_H

#include "GameMessage.h"

class AddToScoreMessage : public GameMessage
{
public:
   AddToScoreMessage(int increase);
   ~AddToScoreMessage();

   void process();

private:
   int mIncrease;
};

#endif // !ADDTOSCOREMESSAGE_H