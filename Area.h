#ifndef Area_H
#define Area_H

#include <list>
#include <queue>
#include <string>
#include <iostream>
#include "Edge.h"
using namespace std;


class Edge;
class Area
{
private:
/**
 * @brief name stores the Name of the area
 * The list stores all the Areas connnected to this one via an Edge
 * 
 */
	string name;
	list<Edge*> connectedEdges;
	
public:
	/**
	 * @brief Construct a new Area object
	 * 
	 * @param name 
	 */
	Area(string name);
	/**
	 * @brief 
	 * 
	 * @param e 
	 * @return true 
	 * @return false 
	 */
	bool addEdge(Edge *e);
	string getName();
	bool isAccessible(Area* d);
	bool isAccessible(Area* d, string type);
	list<Edge*> getEdges();
	bool visited = false;
	void printEdges();
};

#endif