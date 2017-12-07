#include "Connection.h"
#include "Node.h" //Do we need this?
#include "Game.h"
#include "GraphicsSystem.h"


Connection::Connection(Node* To, Node* From, float Cost)
{
	mpTo = To;
	mpFrom = From;
	mCost = Cost;
}

Connection::~Connection()
{

}

void Connection::renderConnection()
{
	GRAPHICS_SYSTEM->drawLine(mpTo->getPosision(), mpFrom->getPosision());
}

