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
		Area* currentArea = areaIter->currentItem();
		trav = currentArea->getEdges().begin();
		int total = currentArea->getEdges().size();
		int count = 0;
		while(count != total){
			 if (find(allEdges.begin(), allEdges.end(), *trav) == allEdges.end()){
				allEdges.push_back(*trav);
			}
			count++;
			trav++;
			
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
