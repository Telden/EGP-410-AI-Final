#include "AddToScoreMessage.h"
#include "GameMessage.h"
#include "GameMessageManager.h"

#include "Game.h"

AddToScoreMessage::AddToScoreMessage(int increase) : GameMessage(ADD_TO_SCORE_MESSAGE)
{
   mIncrease = increase;
}

AddToScoreMessage::~AddToScoreMessage()
{

}

void AddToScoreMessage::process()
{
   gpGame->setScore(gpGame->getScore() + mIncrease);
}