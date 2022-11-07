#ifndef EdgeIterator_H
#define EdgeIterator_H
#include "MapIterator.h"
#include "WarMap.h"
#include "AreaIterator.h"
#include "Edge.h"
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

class WarMap;
/**
 * @brief EdgeIterator inherits from MapIterator and is used to traverse a map
 *
 */
class EdgeIterator : public MapIterator
{
private:
	/**
	 * @brief Stores the graph which to iterate over
	 *
	 */
	WarMap *graph = nullptr;
	/**
	 * @brief Stores all the Edges to iterate over
	 *
	 */
	list<Edge *> allEdges;
	/**
	 * @brief Stores an iterator of type Edge, to keep track of the iteration
	 *
	 */
	list<Edge *>::iterator trav;

public:
	/**
	 * @brief Construct a new Edge Iterator object
	 *
	 * @param g
	 */
	EdgeIterator(WarMap *g);
	/**
	 * @brief Destroy the Edge Iterator object
	 *
	 */
	~EdgeIterator();
	/**
	 * @brief Start the iteration from the begining
	 *
	 */
	void first();
	/**
	 * @brief Will increment the counter to get the next edge
	 *
	 */
	void next();
	/**
	 * @brief Will check if your done traverse through the entire graph
	 *
	 * @return true, if have not completed traversing through the entire graph yet
	 * @return false, if done traversng through the entire graph
	 */
	bool isDone();
	/**
	 * @brief Returns the current Item in the iteration
	 *
	 * @return Edge*
	 */
	Edge *currentItem();
};

#endif