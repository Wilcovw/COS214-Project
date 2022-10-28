#include "Area.h"

Area::Area(string name, Country *controllingCountry)
{
	this->name = name;
	std::cout << controllingCountry->getName() << std::endl;
	this->controllingCountry = controllingCountry;
}

void Area::setControllingCountry(Country *controllingCountry)
{
	controllingCountry->removeArea(this);
	this->controllingCountry = controllingCountry;
	controllingCountry->addArea(this);
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
			int total = v->getEdges().size(), count = 0;
			it = v->getEdges().begin();
			while (count != total)
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
				count++;
				it++;
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
			int total = v->getEdges().size(), count = 0;
			it = v->getEdges().begin();
			while (count != total)
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

				count++;
				it++;
			}
		}
	}

	return false;
}

void Area::printEdges()
{
	list<Edge *>::iterator it;
	if (connectedEdges.size() == 0)
	{
		cout << name << " is not conncted to anything" << endl;
		return;
	}

	for (it = connectedEdges.begin(); it != connectedEdges.end(); it++)
	{
		cout << (*it)->getDescription() << endl;
	}
}

void Area::setPrev(Area *p)
{
	this->prev = p;
}

Area *Area::getPrev()
{
	return prev;
}

double Area::getDist()
{
	return dist;
}

void Area::setDist(double d)
{
	this->dist = d;
}
