#include "Area.h"

Area::Area(string name)
{
	this->name = name;
}

bool Area::addEdge(Edge *e)
{
	if (e == nullptr)
	{
		return false;
	}
	connectedEdges.push_back(e);
	return true;
}

string Area::getName()
{
	return name;
}

bool Area::isAccessible(Area *d)
{
	if (this == d || d == nullptr)
	{
		return false;
	}
	queue<Area *> queue;
	queue.push(this);
	while (queue.empty() == false)
	{
		Area *v = queue.front();
		queue.pop();
		list<Edge *>::iterator it;
		if (v->getEdges().size() != 0)
		{
			for (it = v->getEdges().begin(); it != v->getEdges().end(); it++)
			{
				Area *u = (*it)->getDestination();
				if (u == d)
				{
					return true;
				}
				if (u->visited == false)
				{
					queue.push(u);
					u->visited = true;
				}
			}
		}
	}

	return false;
}

list<Edge *> Area::getEdges()
{
	return connectedEdges;
}

bool Area::isAccessible(Area *d, string type)
{
	if (this == d || d == nullptr)
	{
		return false;
	}
	queue<Area *> queue;
	queue.push(this);
	while (queue.empty() == false)
	{
		Area *v = queue.front();
		queue.pop();
		list<Edge *>::iterator it;
		if (v->getEdges().size() != 0)
		{
			for (it = v->getEdges().begin(); it != v->getEdges().end(); it++)
			{
				if ((*it)->getType() == type)
				{
					Area *u = (*it)->getDestination();
					if (u == d)
					{
						return true;
					}
					if (u->visited == false)
					{
						queue.push(u);
						u->visited = true;
					}
				}
			}
		}
	}

	return false;
}
