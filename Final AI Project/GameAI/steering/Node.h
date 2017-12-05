#pragma once
#include "Trackable.h"
#include "Vector2D.h"
#include <vector>

class Connection;

class Node : public  Trackable
{
public:
	Node();
	~Node();
	


private:
	Vector2D mPos;
	std::vector<Connection*> mpConnections;
};