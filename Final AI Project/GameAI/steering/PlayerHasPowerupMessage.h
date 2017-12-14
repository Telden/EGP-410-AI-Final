#ifndef PLAYERHASPOWERUPMESSAGE_H
#define PLAYERHASPOWERUPMESSAGE_H

#include "GameMessage.h"

class UnitManager;

class PlayerHasPowerupMessage : public GameMessage
{
public:
   PlayerHasPowerupMessage(int increase);
   ~PlayerHasPowerupMessage();

   void process();

private:
   int mIncrease;
   UnitManager* mpUnitManager;
};

#endif