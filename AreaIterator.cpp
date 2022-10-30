#include "AreaIterator.h"

AreaIterator::AreaIterator(WarMap *g) : MapIterator()
{
	this->graph = g;
}

void AreaIterator::first()
{
	trav = this->graph->begin();
}

void AreaIterator::next()
{
	trav++;
}

bool AreaIterator::isDone()
{
	return trav == graph->end();
}

Area *AreaIterator::currentItem()
{
	return *trav;
}