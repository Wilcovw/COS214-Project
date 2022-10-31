#include "Runway.h"
#include <vector>

Runway::Runway(Area *destination, string name,  Area* location) : Infrastructure(location){
    addConnection(destination,name);
};

void Runway::addConnection(Area *destination, string name){
    srand(time(0));
    double distance = (rand() % 100) + 10;

    Edge *flight = new Edge(distance, name, "Runway", this->location, destination);
    flights.push_back(*flight);
    this->location->addEdge(flight);

    Edge *flippedFlight = new Edge(distance, name, "Runway", destination, this->location);
    destination->addEdge(flippedFlight);
};