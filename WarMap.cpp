#include "WarMap.h"

WarMap::WarMap()
{
}

WarMap::~WarMap()
{
}

Area *WarMap::getArea(string name)
{
	list<Area *>::iterator it;

	for (it = areasWT.begin(); it != areasWT.end(); it++)
	{
		if ((*it)->getName() == name)
		{
			return *it;
		}
	}

	return nullptr;
}

bool WarMap::isAccessible(Area *source, Area *destination)
{
	reset();
	if (source == nullptr || destination == nullptr)
	{
		return false;
	}

	return source->isAccessible(destination);
}

bool WarMap::isAccessible(Area *source, Area *destination, string type)
{
	reset();
	if (source == nullptr || destination == nullptr)
	{
		return false;
	}

	return source->isAccessible(destination, type);
}

bool WarMap::addEdge(Area *source, Area *destination, double distance, string name, string type)
{
	if (source == nullptr || destination == nullptr)
	{
		return false;
	}

	Area *s = this->getArea(source->getName());
	Area *d = this->getArea(destination->getName());
	if (s == nullptr || d == nullptr)
	{
		return false;
	}
	Edge *e = new Edge(distance, name, type, source, destination);
	return s->addEdge(e);
}

bool WarMap::addArea(Area *a)
{
	list<Area *>::iterator it;

	for (it = areasWT.begin(); it != areasWT.end(); it++)
	{
		if (*it == a)
		{
			return false;
		}
	}
	areasWT.push_back(a);
	return true;
}

void WarMap::reset()
{
	list<Area *>::iterator it;
	if (areasWT.size() == 0)
	{
		return;
	}
	for (it = areasWT.begin(); it != areasWT.end(); it++)
	{
		(*it)->visited = false;
	}
}

list<Area *> WarMap::getAreaList()
{
	return this->areasWT;
}

AreaIterator *WarMap::createAreaIterator()
{
	return new AreaIterator(this);
}

list<Area *>::iterator WarMap::begin()
{
	return areasWT.begin();
}

list<Area *>::iterator WarMap::end()
{
	return areasWT.end();
}

EdgeIterator *WarMap::createEdgeIterator()
{
	return new EdgeIterator(this);
}

list<Area *> WarMap::shortestPath(Area *source, Area *destination)
{
	list<Area *> ans;
	if (source == nullptr || destination == nullptr)
	{
		return ans;
	}
	if (isAccessible(source, destination) == false)
	{
		return ans;
	}


}
