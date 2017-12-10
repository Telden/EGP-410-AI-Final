#include "DeleteNodeMessage.h"
#include "Game.h"
#include "Graph.h"

DeleteNodeMessage::DeleteNodeMessage(Vector2D mousePos) : GameMessage(DELETE_NODE_MESSAGE)
{
	mMousePos = mousePos;
}

DeleteNodeMessage::~DeleteNodeMessage()
{

}

void DeleteNodeMessage::process()
{
	GRAPH->deleteNode(mMousePos);
}