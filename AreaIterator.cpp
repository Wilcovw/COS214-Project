#include "AreaIterator.h"

AreaIterator::AreaIterator(WarMap *g) : MapIterator()
{
	this->graph = g;
}

void AreaIterator::first()
{
	this->graph->reset();
	resetCount();
	if (this->graph->getAreaList().size() == 0)
	{
		return;
	}

	Area *index = getZero();
	while (index != nullptr)
	{
		depthFirst(index);
		index = getZero();
	}

	trav = areaList.begin();
}

void AreaIterator::next()
{
	trav++;
}

bool AreaIterator::isDone()
{
	return trav == areaList.end();
}

Area *AreaIterator::currentItem()
{
	return *trav;
}

void AreaIterator::depthFirst(Area *v)
{
	v->num = DFTcount++;
	areaList.push_back(v);
	if (v->getEdges().size() != 0)
	{
		list<Edge *>::iterator it;
		int total = v->getEdges().size(), count = 0;
		it = v->getEdges().begin();
		while (count != total)
		{
			Area* u = (*it)->getDestination();
			if (u->num == 0){
				depthFirst(u);
			}
			count++;
			it++;
		}
	}
}

void AreaIterator::resetCount()
{
	list<Area *>::iterator it;
	int total = graph->getAreaList().size(), count = 0;
	it = graph->getAreaList().begin();
	while (count != total)
	{
		(*it)->num = 0;
		count++;
		it++;
	}
}

Area *AreaIterator::getZero()
{
	list<Area *>::iterator it;
	int total = graph->getAreaList().size(), count = 0;
	it = graph->getAreaList().begin();
	while (count != total)
	{
		if ((*it)->num == 0)
		{
			return *it;
		}
		count++;
		it++;
	}
	return nullptr;
}
