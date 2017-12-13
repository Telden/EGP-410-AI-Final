#include "Game.h"
#include "Graph.h"
#include "SwitchMapMessage.h"
#include "UnitManager.h"
#include "UnitManager.h"
#include "Player.h"

SwitchMapMessage::SwitchMapMessage() : GameMessage(SWITCH_MAP_MESSAGE)
{

}

void SwitchMapMessage::process()
{
	GRAPH->switchMap();
	UNIT_MANAGER->getPlayerUnit()->switchMap();
}