#include "Road.h"

Road::Road(Area* source, Area *destination, double hp, double distance) : Infrastructure(hp, source)
{
    this->distance = distance;
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
    if(theRoad[0]->getDestination() != nullptr && theRoad[0]->getDestination()->getClonedArea() != nullptr) {
        Infrastructure* newRoad = new Road(newArea, theRoad[0]->getDestination()->getClonedArea(), this->HP, this->distance);
    }
    return nullptr;
}