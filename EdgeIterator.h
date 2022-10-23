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
class EdgeIterator : public MapIterator
{
private:
	WarMap *graph = nullptr;
	list<Edge *> allEdges;
	list<Edge *>::iterator trav;
public:
	EdgeIterator(WarMap *g);
	~EdgeIterator();
	void first();
	/**
	 * @brief Will increment the counter to get the next edge
	 * 
	 */
	void next();
	/**
	 * @brief Will check if your done traverse through the entire graph
	 * 
	 * @return true, if have to traversed through the entire graph yet
	 * @return false, if done traversng through the entire graph
	 */
	bool isDone();

	Edge *currentItem();
};

//Code to get all the edges in the graph
/*
EdgeIterator *edgeIter = graph->createEdgeIterator();
	edgeIter->first();
	while(edgeIter->isDone() == false){
		Edge* currentEdge = edgeIter->currentItem();
		cout << currentEdge->getName() << endl;

		edgeIter->next();
}*/
#endif