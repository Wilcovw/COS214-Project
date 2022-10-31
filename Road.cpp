#include "Road.h"

Road::Road(Area* source, Area *destination, double hp) : Infrastructure(hp, source)
{
    srand(time(0));
    this->distance = (rand() % 10) + 1;

    this->theRoad[0] = new Edge(distance, "Road", this->location, destination);
    this->location->addEdge(theRoad[0]);

    this->theRoad[1] = new Edge(distance, "Road", destination, this->location);
    destination->addEdge(theRoad[1]);
};

void Road::destroy(){
    this->location->removeEdge(theRoad[0]);
     this->location->removeEdge(theRoad[1]);
}

Infrastructure* Road::clone(Area* newArea) {
    return nullptr;
}