#include "Runway.h"
#include <vector>

Runway::Runway(Area *source, double hp, double distanec) : Infrastructure(hp, source) {
    this->distance = distance;
};

void Runway::addConnection(Area *destination)
{
    srand(time(0));
    double distance = (rand() % 100) + 10;

    Edge *flight = new Edge(distance, "Runway", this->location, destination);
    flights.push_back(flight);
    this->location->addEdge(flight);

    Edge *flippedFlight = new Edge(distance, "Runway", destination, this->location);
    destination->addEdge(flippedFlight);
};

void Runway::destroy() {
    for (auto e : flights){
        this->location->removeEdge(e);
    }
}


Infrastructure* Runway::clone(Area* newArea) {
    Runway* newRunway = new Runway(newArea, this->HP, this->distance);
    for(auto f : flights) {
        if(f != nullptr && f->getDestination() != nullptr && f->getDestination()->getClonedArea() != nullptr && f->getDestination()->getClonedArea() != newArea) {
            newRunway->addConnection(f->getDestination()->getClonedArea());
        }
    }
    return newRunway;
}