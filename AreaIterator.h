#ifndef AreaIterator_H
#define AreaIterator_H
#include "MapIterator.h"
#include "WarMap.h"
#include "Area.h"
#include "Edge.h"
#include <list>
#include <iterator>
using namespace std;
class AreaIterator : public MapIterator
{
private:	
	WarMap *graph = nullptr;
	list<Area*> areaList;
	int DFTcount = 0;
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
	 * @brief Will increment the counter to get the next Area in the DFT
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

	void depthFirst(Area* v);

	void resetCount();
	Area* getZero();
};

#endif