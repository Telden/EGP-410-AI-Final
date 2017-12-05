#include "Graph.h"
#include "Connection.h"
#include "Node.h"
#include <fstream>


Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::init()
{
	std::fstream ifStream(PATHING_FILENAME);
	while (!ifStream.eof())
	{
		ifStream >> 
	}
}

std::vector<Connection*> Graph::getConnections(const Node& from)
{
	return getConnections(from.getId());
}

std::vector<Connection*> Graph::getConnections(const NODE_ID& fromId)
{
	static std::vector<Connection*> sEmpty;

	std::map< NODE_ID, std::vector<Connection*> >::iterator iter = mConnectionMap.find(fromId);
	if (iter == mConnectionMap.end())
	{
		return sEmpty;
	}
	else
	{
		return iter->second;
	}
}

Node* Graph::getNode(int index)
{
	if (index < (int)mpNodes.size())
	{
		return mpNodes[index];
	}
	else
	{
		return NULL;
	}
}


void Graph::renderGraph()
{
	for (int i = 0; i < mpNodes.size(); i++)
		mpNodes[i]->renderNode();
	for (int i = 0; i < mpConnections.size(); i++)
		mpConnections[i]->renderConnection();
}