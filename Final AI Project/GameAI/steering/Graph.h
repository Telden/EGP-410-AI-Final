#pragma once
#include "Trackable.h"
#include <string>

class Node;
class Connection;

class Graph : public Trackable
{
public:
	Graph();
	~Graph();

	void init();


private:
	const std::string PATHING_FILENAME = "pathgrid.txt";
	
};