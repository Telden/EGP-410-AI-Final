#include "Node.h"
#include "Game.h"
#include "GraphicsSystem.h"

Node::Node(float xLoc, float yLoc, int level, const NODE_ID& id):mId(id)
{
	int width = NODE_SIZE / 2;
	int height = NODE_SIZE / 2;
	mLevel = level;
	//Set the node centerpoint
	mCenterpoint.setX(xLoc);
	mCenterpoint.setY(yLoc);

	//set the top left corner
	mTopLeftCorner.setX(mCenterpoint.getX() - width);
	mTopLeftCorner.setY(mCenterpoint.getY() - height);

	//set the bottom right corner
	mBottomRightCorner.setX(mCenterpoint.getX() + width);
	mBottomRightCorner.setY(mCenterpoint.getY() + height);


}

void Node::renderNode(int currentLevel)
{
	int test = mLevel;
	if(currentLevel == test)
		if(mLevel == 0)
			GRAPHICS_SYSTEM->drawStreetsNode(mTopLeftCorner, mBottomRightCorner);
		else
			GRAPHICS_SYSTEM->drawSewerNode(mTopLeftCorner, mBottomRightCorner);
}