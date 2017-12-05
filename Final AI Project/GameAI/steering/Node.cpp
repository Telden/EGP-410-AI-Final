#include "Node.h"
#include "Game.h"
#include "GraphicsSystem.h"

Node::Node(float xLoc, float yLoc, const NODE_ID& id):mId(id)
{
	mPos.setX(xLoc);
	mPos.setY(yLoc);
}

void Node::renderNode()
{
	//Implement Render code here
}