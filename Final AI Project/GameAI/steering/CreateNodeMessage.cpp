#include "CreateNodeMessage.h"
#include "Game.h"
#include "Graph.h"


CreateNodeMessage::CreateNodeMessage(Vector2D mousePos) :GameMessage(CREATE_NODE_MESSAGE)
{
	mMousePos = mousePos;
}

CreateNodeMessage::~CreateNodeMessage()
{

}

void CreateNodeMessage::process()
{
	GRAPH->createNode(mMousePos);
}