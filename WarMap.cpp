#include "WarMap.h"


WarMap::WarMap() {
    
}

WarMap::~WarMap() {
    
}

Area* WarMap::getArea(string name) {
    list<Area*>::iterator it;

	for (it = areasWT.begin(); it != areasWT.end(); it++)
	{
		if ((*it)->getName() == name){
			return *it;
		}
	}

	return nullptr;
}

bool WarMap::isAccessible(Area* source, Area* destination) {
    if (source == nullptr || destination == nullptr){
		return false;
	}

	return source->isAccessible(destination);
	
}

bool WarMap::isAccessible(Area* source, Area* destination, string type) {
    if (source == nullptr || destination == nullptr){
		return false;
	}

	return source->isAccessible(destination, type);
}

bool WarMap::addEdge(Area* source, Area* destination, double distance, string name,  string type) {
	if (source == nullptr || destination == nullptr){
		return false;
	}	

	Area* s = this->getArea(source->getName());
	Area* d = this->getArea(destination->getName());

	Edge* e = new Edge(distance, name, type ,source, destination);
	return s->addEdge(e);
}

bool WarMap::addArea(Area *a) {
    list<Area*>::iterator it;

	for (it = areasWT.begin(); it != areasWT.end(); it++)
	{
		if (*it == a){
			return false;
		}
	}
	areasWT.push_back(a);
	return true;
	
}


