#include "Game.h"
#include "SwitchMapMessage.h"
#include "UnitManager.h"
#include "Player.h"

SwitchMapMessage::SwitchMapMessage() : GameMessage(SWITCH_MAP_MESSAGE)
{

}

void SwitchMapMessage::process()
{
	gpGame->switchMap();
	UNIT_MANAGER->getPlayerUnit()->switchMap();
}