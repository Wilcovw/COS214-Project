#include "Area.h"
#include "Country.h"


Area::Area(string name, Country *controllingCountry)
{
	this->name = name;
	this->controllingCountry = controllingCountry;
	this->controllingCountry->addArea(this);
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
		for (auto e : v->getEdges())
		{
			Area *u = e->getDestination();
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
		for (auto e : v->getEdges())
		{

			if (e->getType() == type)
			{
				Area *u = e->getDestination();
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

void Area::printEdges()
{
	list<Edge *>::iterator it;
	if (connectedEdges.size() == 0)
	{
		cout << name << " is not conncted to anything" << endl;
		return;
	}
	cout << "Edges of " << this->name  << ":"<< endl;
	for (it = connectedEdges.begin(); it != connectedEdges.end(); it++)
	{
		cout << (*it)->getDescription() << endl;
	}
	cout << endl;
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

Country *Area::getControllingCountry()
{
	return this->controllingCountry;
}

void Area::removeEdge(Edge * e){
	connectedEdges.remove(e);
}

Area* Area::clone(Country * c) {
    return new Area(name, c);
}
