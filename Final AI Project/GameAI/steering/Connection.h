#pragma once
#include "Trackable.h"

class Node;
class Connection : public Trackable
{
public:
	Connection();
	~Connection();
	float getCost() { return mCost; };
	Node* getFromNode() { return mpFrom; };
	Node* getToNode() { return mpTo; };

private:
	float mCost;
	Node* mpTo;
	Node* mpFrom;

};