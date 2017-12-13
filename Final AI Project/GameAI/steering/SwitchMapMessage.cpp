#include "Game.h"
#include "Graph.h"
#include "SwitchMapMessage.h"

SwitchMapMessage::SwitchMapMessage() : GameMessage(SWITCH_MAP_MESSAGE)
{

}

void SwitchMapMessage::process()
{
	GRAPH->switchMap();
}