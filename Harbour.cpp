#include "Harbour.h"

#include <vector>

Harbour::Harbour(Area *source, double hp) : Infrastructure(hp, source)
{
    
};

void Harbour::addConnection(Area *destination)
{
    srand(time(0));
    double distance = (rand() % 100) + 10;

    Edge *connectedHarbour = new Edge(distance, "Harbour", this->location, destination);
    connectedHarbours.push_back(connectedHarbour);
    this->location->addEdge(connectedHarbour);

    Edge *flippedConnectedHarbour = new Edge(distance, "Harbour", destination, this->location);
    destination->addEdge(flippedConnectedHarbour);
};

void Harbour::destroy(){
    for (auto e : connectedHarbours){
        this->location->removeEdge(e);
    }
}

Infrastructure* Harbour::clone(Area* newArea) {
    return nullptr;
}