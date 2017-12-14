#include "PlayerHasPowerupMessage.h"
#include "GameMessage.h"
#include "GameMessageManager.h"

#include "Game.h"
#include "UnitManager.h"

PlayerHasPowerupMessage::PlayerHasPowerupMessage(int increase) : GameMessage(ADD_TO_SCORE_MESSAGE)
{
   mIncrease = increase;
}

PlayerHasPowerupMessage::~PlayerHasPowerupMessage()
{

}

void PlayerHasPowerupMessage::process()
{
   
}