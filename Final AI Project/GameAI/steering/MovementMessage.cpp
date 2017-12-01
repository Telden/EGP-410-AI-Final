#include "Game.h"
#include "KinematicUnit.h"
#include "GameMessageManager.h"
#include "MovementMessage.h"
#include "UnitManager.h"
#include "Player.h"
#include "PlayerMovement.h"

MovementMessage::MovementMessage(char input, bool isPressed) :GameMessage(MOVEMENT_MESSAGE)
{
	mInput = input;
	mIsPressed = isPressed;
}

MovementMessage::~MovementMessage()
{

}

void MovementMessage::process()
{
	UNIT_MANAGER->getPlayerUnit()->getSteeringComponent()->recieveMessage(mInput, mIsPressed);
}
