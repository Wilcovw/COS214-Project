#ifndef Area_H
#define Area_H

#include <list>
#include <queue>
#include <string>
#include <iostream>
#include "Edge.h"

using namespace std;

class Country;
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
	/**
	 * @brief List of all connected edges to the current Edge
	 *
	 */
	list<Edge *> connectedEdges;
	/**
	 * @brief Used to store the previous Area in the shortest Path
	 * 
	 */
	Area *prev = nullptr;
	/**
	 * @brief Represents the distance from the current Area to the closet Area before it. Used in the shortest path algorithm
	 * 
	 */
	double dist = 0;

	Country *controllingCountry = nullptr;
	Area* clonedArea = nullptr;

public:
	/**
	 * @brief Construct a new Area object
	 *
	 * @param name: Is the name of the the Edge
	 */
	Area(string name, Country *controllingCountry);
	/**
	 * @brief Set the Controlling Country object
	 *
	 * @param Country THe new controlling Country object
	 */
	void setControllingCountry(Country *controllingCountry);
	/**
	 * @brief Get the Controlling Country object
	 *
	 * @return Country* - the controlling Country object
	 */
	Country *getControllingCountry();
	/**
	 * @brief Adds an edge of type Road/Harbour/Air to the current Area
	 *
	 * @param e The Edge to add
	 * @return true, if the Edge was added successfuly
	 * @return false, if the Edge was already existed and was not added
	 */
	bool addEdge(Edge *e);
	/**
	 * @brief Get the Name object
	 *
	 * @return string
	 */
	string getName();
	/**
	 * @brief Check if the Area passed in is connected to this Area
	 *
	 * @param d The Area to check if it is connected to the current One
	 * @return true
	 * @return false
	 */
	bool isAccessible(Area *d);
	/**
	 * @brief Check if the Area passed in is connected to this Area via a certain type edge
	 *
	 * @param d The Area to check if it is connected to the current One
	 * @param type The type of edge
	 * @return true
	 * @return false
	 */
	bool isAccessible(Area *d, string type);
	/**
	 * @brief Get the Edges object
	 *
	 * @return list<Edge*>
	 */
	list<Edge *> getEdges();
	/**
	 * @brief Variable needed to determine if it was visited in the traversal
	 *
	 */
	bool visited = false;
	/**
	 * @brief Prints all the edges that are connected to this Area
	 *
	 */
	void printEdges();
	/**
	 * @brief Variable needed for shortest path
	 *
	 */
	int num = 0;
	/**
	 * @brief Set the Prev object
	 * 
	 * @param p The Area object to set the prev pointer
	 */
	void setPrev(Area *p);
	/**
	 * @brief Get the Prev object
	 * 
	 * @return Area* 
	 */
	Area *getPrev();
	/**
	 * @brief Get the dist varaible
	 * 
	 * @return double 
	 */
	double getDist();
	/**
	 * @brief Set the dist object
	 * 
	 * @param d 
	 */
	void setDist(double d);
	/**
	 * @brief remove the passed in Edge from the Area
	 * 
	 */
	void removeEdge(Edge *);
	/**
	 * @brief Returns a copy of current Object
	 * 
	 * @return Area* 
	 */
	Area* clone(Country * c);
	Area* getClonedArea();
};

#endif