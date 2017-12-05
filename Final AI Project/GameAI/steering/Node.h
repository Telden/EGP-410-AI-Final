#pragma once
#include "Trackable.h"
#include "Vector2D.h"
#include <vector>

#define NODE_ID int

class Node : public  Trackable
{
public:
	Node(float xPos, float yPos, const NODE_ID& id);
	~Node();
	Vector2D getPosision() { return mPos; };
	void renderNode();
	const NODE_ID& getId() const { return mId; };
private:
	Vector2D mPos;
	const NODE_ID mId;
};