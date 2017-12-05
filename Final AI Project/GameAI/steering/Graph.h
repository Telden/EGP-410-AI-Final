#pragma once
#include "Trackable.h"
#include "Node.h"
#include <string>
#include <vector>
#include <map>

class Node;
class Connection;

class Graph : public Trackable
{
public:
	Graph();
	~Graph();

	void init();
	std::vector<Connection*> getConnections(const Node& from);
	std::vector<Connection*> getConnections(const NODE_ID& fromId);
	Node* getNode(int index) { return mpNodes[index]; };
	void renderGraph();


private:
	std::vector<Node*> mpNodes;
	std::vector<Connection*>mpConnections;
	std::map< NODE_ID, std::vector<Connection*> > mConnectionMap;


	bool mShouldDebug = false;
	const std::string PATHING_FILENAME = "pathgrid.txt";
	
	
};