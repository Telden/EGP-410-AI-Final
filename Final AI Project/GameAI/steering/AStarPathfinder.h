#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H

#include "NodeRecord.h"
#include <vector>
#include <queue>
#include <stack>
class Path;
class Graph;
class GraphicsBuffer;
class Vector2D;

class AStarPathfinder 
{
public:
	AStarPathfinder();
	~AStarPathfinder();

	std::stack<Node*> findPath(Node* pFrom, Node* pTo);//make sure to delete the path when you are done!

	NodeRecord* checkOpenList(std::priority_queue<NodeRecord*> queue, Node* node);
	NodeRecord* checkOpenList(std::vector<NodeRecord*> vect, Node* node);
	NodeRecord* checkClosedList(std::vector<NodeRecord*> vect, Node* node);
	NodeRecord* getSmallestCost(std::vector<NodeRecord*> vect, Node* to);
	int getIDFromOpen(std::vector<NodeRecord*> vect, Node* node);
	float getDistance(Vector2D to, Vector2D from);

private:
	Graph* mpGraph;
	
};

#endif ASTARPATHFINDER_H