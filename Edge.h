#ifndef Edge_H
#define Edge_H
#include "Area.h"
#include <string>

using namespace std;
class Area;
class Edge
{
private:
	/**
	 * @brief The start point of an edge in the directed graph
	 * 
	 */
	Area* source = nullptr;
	/**
	 * @brief The end point of an edge in the directed graph
	 * 
	 */
	Area* destination = nullptr;
	/**
	 * @brief Represents the distance the current Edge cost to traverse
	 * 
	 */
	double distance = 0;
	/**
	 * @brief Type of Edge
	 * 
	 */
	string type;
public:
	/**
	 * @brief Construct a new Edge object
	 * 
	 * @param v , The distance to traverse
	 * @param type , The type of Edge
	 * @param s , The start point
	 * @param d , The end point
	 */
	Edge(double v, string type,Area* s, Area* d);
	/**
	 * @brief Destroy the Edge object
	 * 
	 */
	~Edge();
	/**
	 * @brief Get the Source object
	 * 
	 * @return Area* 
	 */
	Area* getSource();
	/**
	 * @brief Get the Destination object
	 * 
	 * @return Area* 
	 */
	Area* getDestination();
	/**
	 * @brief Get the Type of Edge
	 * 
	 * @return string 
	 */
	string getType();
	/**
	 * @brief Get the Description of the Edge
	 * 
	 * @return string 
	 */
	string getDescription();
	/**
	 * @brief Get the Name of the Edge
	 * 
	 * @return string 
	 */
	string getName();
	/**
	 * @brief Get the Distance the Edge represents
	 * 
	 * @return double 
	 */
	double getDistance();
	
	
};

#endif
