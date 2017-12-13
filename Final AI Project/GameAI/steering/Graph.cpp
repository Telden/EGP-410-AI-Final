#include "Graph.h"
#include "Connection.h"
#include "Node.h"
#include <fstream>
#include <string>
#include <vector>
#include <stack>

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::init()
{
	loadNodes();
	loadConnections();

	
}

void Graph::loadNodes()
{
	Node* newnode;
	std::string input;
	float xPos, yPos;
	int level;
	
	std::fstream ifStream(NODES_FILENAME_PATH);
	while (!ifStream.eof())
	{
		//Get the Node's ID
		ifStream >> input;
		const NODE_ID nodeID = lastID = std::stoi(input);
		//Get the node's level
		ifStream >> input;
		level = std::stoi(input);
		//Get the x and y location of the node
		ifStream >> input;
		xPos = std::stoi(input);
		ifStream >> input;
		yPos = std::stoi(input);
		
		//Create the node
		newnode = new Node(xPos, yPos, level, nodeID);

		//Add it to the node vector and the node map w/node id
		mpNodes.push_back(newnode);
		mpNodeMap.insert(std::pair<NODE_ID, Node*>(nodeID, newnode));

	}
}

void Graph::loadConnections()
{
	int numConnections;
	Node* pfrom; Node* pto;
	std::vector<Connection*> connectionList;
	Connection* newConnection;
	std::string input;

	std::fstream ifStream(CONNECTIONS_FILENAME_PATH);
	while (!ifStream.eof())
	{
		//Get node ID (node from)
		ifStream >> input;
		const NODE_ID nodeID = std::stoi(input);
		pfrom = getNode(nodeID);
		std::vector<Connection*> connectionList;

		//std::cout << "\n" << pfrom->getId() << "\t";

		//Get the number of connections this node has
		ifStream >> input;
		numConnections = std::stoi(input);

		//Load the NodeID's that have connection from this node (Node to(s))
		for (int i = 0; i < numConnections; i++)
		{
			ifStream >> input;
			const NODE_ID toNode = std::stoi(input);
			pto = getNode(toNode);
			//std::cout << pto->getId() << "\t";
			newConnection = new Connection(pto, pfrom, CONNECTION_COST);
			connectionList.push_back(newConnection);
			mpConnections.push_back(newConnection);


		}
		
		mConnectionMap.insert(std::pair<NODE_ID, std::vector<Connection*>>(nodeID, connectionList));
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

//Node* Graph::getNode(const NODE_ID& nodeID)
//{
//	std::map< NODE_ID, Node*>::iterator iter = mpNodeMap.find(nodeID);
//	if (iter == mpNodeMap.end())
//	{
//		std::cout << "ERROR: Could not find node with given node ID\n";
//	}
//	else
//	{
//		return iter->second;
//	}
//}


void Graph::renderGraph()
{
	for (unsigned int i = 0; i < mpNodes.size(); i++)
	{
		mpNodes[i]->renderNode(mCurrentLevel);
	}
		for (unsigned int i = 0; i < mpConnections.size(); i++)
			mpConnections[i]->renderConnection();
	
	
}

void Graph::createNode(Vector2D mousePos)
{
	Node* pNode;
	const NODE_ID nodeID = lastID += 1;
	
	pNode = new Node(mousePos.getX(), mousePos.getY(), 0, nodeID);
	mpNodes.push_back(pNode);
}

void Graph::deleteNode(Vector2D mousePos)
{
	Vector2D  topleft;
	Vector2D bottomRight;
	Node* pTarget;
	NODE_ID targetID;
	unsigned int i = 0;
	bool nodeFound = false;
	for (i; i < mpNodes.size(); i++)
	{
		//cache the bottom right, top  left corners 
		topleft = mpNodes[i]->getTopLeftCorner();
		bottomRight = mpNodes[i]->getBottomRightCorner();

		if (mousePos.getX() >= topleft.getX() && mousePos.getY() >= topleft.getY() &&
			mousePos.getX() <= bottomRight.getX() && mousePos.getY() <= bottomRight.getY())
		{
			targetID = mpNodes[i]->getId();
			std::cout << "Deleting node " << mpNodes[i]->getId() << std::endl;
			nodeFound = true;
			break;
		}
	}

	
	if (nodeFound)
	{
		removeConnections(targetID);
		mpNodes.erase(mpNodes.begin() + i);
	}
		
	

}

void Graph::removeConnections(NODE_ID targetID)
{
	std::stack<int> indexes;
	int toDelete;
	for (unsigned int i = 0; i < mpConnections.size(); i++)
	{
		if (mpConnections[i]->getFromNode()->getId() == targetID || mpConnections[i]->getToNode()->getId() == targetID)
		{
			toDelete = i;
			indexes.push(toDelete);
		}
	}

	while (!indexes.empty())
	{
		toDelete = indexes.top();
		mpConnections.erase(mpConnections.begin() + toDelete);
		indexes.pop();
	}
}

void Graph::switchMap()
{
	if (mCurrentLevel == 0)
		mCurrentLevel = 1;
	else if (mCurrentLevel == 1)
		mCurrentLevel = 0;
}
