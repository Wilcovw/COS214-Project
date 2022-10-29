#include "Road.h"

Road::Road(Area *destination, string name){
    srand(time(0));
    this->distance = (rand() % 10) + 1;

    this->theRoad[0] = new Edge(distance, name, "Road", this->location, destination);
    this->location->addEdge(theRoad[0]);

    this->theRoad[1] = new Edge(distance, name, "Road", destination, this->location);
    destination->addEdge(theRoad[1]);
};