#ifndef WarMap_H
#define WarMap_H
#include <list>
#include <string>
#include "Area.h"
#include "AreaIterator.h"
#include "EdgeIterator.h"
#include "Country.h"
#include <iterator>
#include <math.h>
#include <climits>
#include <algorithm>
using namespace std;

class EdgeIterator;
class AreaIterator;
/**
 * @brief The Graph
 *
 */
class WarMap
{
private:
	/**
	 * @brief stores all the Area's in the graph
	 *
	 */
	list<Area *> areasWT;

public:
	/**
	 * @brief Construct a new War Map object
	 *
	 */
	WarMap();
	/**
	 * @brief Destroy the War Map object
	 *
	 */
	~WarMap();
	/**
	 * @brief Get the Area object of a certian name
	 *
	 * @param name The Area of this name to search for
	 * @return Area*
	 */
	Area *getArea(string name);
	/**
	 * @brief Checks if the desitination Area is accessible from the source Area
	 *
	 * @param source Area to search from
	 * @param destination Area to search to
	 * @return true If there exsists a path from source to destination
	 * @return false If there exsists no path from source to destination
	 */
	bool isAccessible(Area *source, Area *destination);
	/**
	 * @brief
	 *
	 * @param source
	 * @param destination
	 * @param type
	 * @return true
	 * @return false
	 */
	bool isAccessible(Area *source, Area *destination, string type);
	/**
	 * @brief
	 *
	 * @param source
	 * @param destination
	 * @param distance
	 * @param name
	 * @param type
	 * @return true
	 * @return false
	 */
	bool addEdge(Area *source, Area *destination, double distance, string type);
	/**
	 * @brief
	 *
	 * @param a
	 * @return true
	 * @return false
	 */
	bool addArea(Area *a);
	/**
	 * @brief
	 *
	 */
	void reset();
	/**
	 * @brief Get the Area List object
	 *
	 * @return list<Area*>
	 */
	list<Area *> getAreaList();
	/**
	 * @brief Create a Area Iterator object
	 *
	 * @return AreaIterator*
	 */
	AreaIterator *createAreaIterator();
	/**
	 * @brief Create a Edge Iterator object
	 *
	 * @return EdgeIterator*
	 */
	EdgeIterator *createEdgeIterator();
	/**
	 * @brief
	 *
	 * @return list<Area *>::iterator
	 */
	list<Area *>::iterator begin();
	/**
	 * @brief Gets the end of Areas list
	 *
	 * @return list<Area *>::iterator
	 */
	list<Area *>::iterator end();
	/**
	 * @brief Determines the sortest path between the source and destination
	 *
	 * @param source The start point
	 * @param destination The end point
	 * @return list<Area*> List of Area's contained in sortest path
	 */
	list<Area *> shortestPath(Area *source, Area *destination);
	/**
	 * @brief Determines the sortest path between the source and destination via a certain Type
	 * 
	 * @param source  The start point
	 * @param destination The end point
	 * @param type The type of Edge to filter through
	 * @return list<Area *> List of Area's contained in sortest path
	 */
	list<Area *> shortestPath(Area *source, Area *destination, string type);
};

#endif