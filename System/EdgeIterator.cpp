#include "EdgeIterator.h"


EdgeIterator::EdgeIterator(WarMap *g) {
    this->graph = g;
}

EdgeIterator::~EdgeIterator() {
    
}

void EdgeIterator::first() {
    AreaIterator *areaIter = graph->createAreaIterator();
	areaIter->first();
	while(areaIter->isDone() == false){
		Area *currentArea = areaIter->currentItem();
		for (auto edges : currentArea->getEdges())
		{
			if (find(allEdges.begin(), allEdges.end(), edges) == allEdges.end())
			{
				allEdges.push_back(edges);
			}
		}
		areaIter->next();

	}


	trav = allEdges.begin();
}

void EdgeIterator::next() {
    trav++;
}

bool EdgeIterator::isDone() {
    return trav == allEdges.end();
}

Edge* EdgeIterator::currentItem() {
    return *trav;
}
