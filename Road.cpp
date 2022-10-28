#include "Road.h"

Road::Road(Area *destination, string name){
    srand(time(0));
    double distance = (rand() % 10) + 1;
    this->name = name;

    this->theRoad = new Edge(distance, name, "Road", this->location, destination);
    // source.addEdge(&theRoad);

    Edge *roadFlipped = new Edge(distance, name, "Road", destination, this->location);
    // destination->addEdge(&roadFlipped);

    delete roadFlipped;
};