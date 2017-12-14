#pragma once
#include "Trackable.h"
class Node;

struct NodeRecord :  public Trackable
{
	Node* mNode;
	NodeRecord* mConnection;
	float mCostSoFar;

	bool operator<(const NodeRecord node)
	{
		return this->mCostSoFar < node.mCostSoFar;
	}
};