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
	void loadNodes();
	void loadConnections();

	std::vector<Connection*> getConnections(const Node& from);
	std::vector<Connection*> getConnections(const NODE_ID& fromId);
	Node* getNode(int index);
	int getNumNodes() { return mpNodes.size(); };
	void renderGraph();
	

private:
	std::vector<Node*> mpNodes;
	std::vector<Connection*>mpConnections;
	std::map< NODE_ID, std::vector<Connection*> > mConnectionMap;
	std::map<NODE_ID, Node*>  mpNodeMap;
	
	NODE_ID lastID; //Used for adding new nodes past what is loaded from the textfile

	const std::string NODES_FILENAME_PATH = "data/nodes.txt";
	const std::string CONNECTIONS_FILENAME_PATH = "data/connections.txt";
	const int CONNECTION_COST = 1;
	
	
	
};