#pragma once
#include "Trackable.h"
#include "Vector2D.h"
#include <vector>

#define NODE_ID int

class Node : public  Trackable
{
public:
	Node(float xPos, float yPos, int level, const NODE_ID& id);
	~Node() {};
	Vector2D getPosision() { return mCenterpoint; };
	Vector2D getTopLeftCorner() { return mTopLeftCorner; };
	Vector2D getBottomRightCorner() { return mBottomRightCorner; };
	int getLevel() { return mLevel; };
	void renderNode(int currentLevel);
	const NODE_ID& getId() const { return mId; };
private:
	Vector2D mCenterpoint;
	Vector2D mTopLeftCorner;
	Vector2D mBottomRightCorner;
	const int NODE_SIZE= 64;
	const NODE_ID mId;
	int mLevel;
};