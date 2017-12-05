#pragma once
#include "Trackable.h"

class Node;
class Connection : public Trackable
{
public:
	Connection(Node* To, Node* From, float cost);
	~Connection();
	float getCost() { return mCost; };
	Node* getFromNode() { return mpFrom; };
	Node* getToNode() { return mpTo; };

	void renderConnection();
private:
	float mCost;
	Node* mpTo;
	Node* mpFrom;

};