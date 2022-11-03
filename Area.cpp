#include "Area.h"
#include "Country.h"


Area::Area(string name, Country *controllingCountry)
{
	this->name = name;
	this->controllingCountry = controllingCountry;
	this->controllingCountry->addArea(this);
}

Area::~Area() {
	if(!connectedEdges.empty()) {
		for(auto e : connectedEdges) {
			if(e != nullptr) {
				connectedEdges.remove(e);
				e->getDescription();
				if(e->getSource() == this) {
					e->getDestination()->removeEdge(e);
				} else {
					e->getSource()->removeEdge(e);
				}
			}
		}
	}
}


void Area::addHarbour(Harbour* theHarbour) {
	harbour = theHarbour;	
}

void Area::addRunway(Runway* theRunway) {
	runway = theRunway;
}

Harbour* Area::getHarbourInArea() {
	return harbour;
}

Runway * Area::getRunwayInArea() {
	return runway;
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

Country *Area::getControllingCountry()
{
	return this->controllingCountry;
}

void Area::removeEdge(Edge * e){
	connectedEdges.remove(e);
	delete e;
}

Area* Area::clone(Country * c) {
	Area* clonedArea = new Area(name, c);
    return clonedArea;
}

Area* Area::getClonedArea() {
		return clonedArea;
}
