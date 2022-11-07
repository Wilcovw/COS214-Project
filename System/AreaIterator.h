#ifndef AreaIterator_H
#define AreaIterator_H
#include "MapIterator.h"
#include "WarMap.h"
#include "Area.h"
#include "Edge.h"
#include <list>
#include <iterator>

using namespace std;
class WarMap;
/**
 * @brief AreaIterator inherits from MapIterator and is used to iterate through the map
 *
 */
class AreaIterator : public MapIterator
{
private:
	/**
	 * @brief Stores the graph which to iterate over
	 *
	 */
	WarMap *graph = nullptr;
	/**
	 * @brief Stores an iterator of type Area, to keep track of the iteration
	 *
	 */
	list<Area *>::iterator trav;

public:
	/**
	 * @brief Construct a new Area Iterator object
	 *
	 * @param g The WarMap, graph that will need to be traversed
	 */
	AreaIterator(WarMap *g);
	/**
	 * @brief Will perform a depth first traversal of the graph
	 *
	 */
	void first();
	/**
	 * @brief Will increment the counter to get the next Area
	 *
	 */
	void next();
	/**
	 * @brief Will check if you did traverse through the entire graph
	 *
	 * @return true, if have to traversed through the entire graph yet
	 * @return false, if done traversng through the entire graph
	 */
	bool isDone();
	/**
	 * @brief Will return the current element of the graph traversal
	 *
	 * @return Area*
	 */
	Area *currentItem();
};

// Code to interface with all the Areas in a graph
/*AreaIterator *areaIter = graph->createAreaIterator();
	areaIter->first();
	while(areaIter->isDone() == false){
		Area* currentArea = areaIter->currentItem();
		cout << currentArea->getName() << endl;

		areaIter->next();
	}
*/
#endif