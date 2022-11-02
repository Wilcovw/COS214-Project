#include "Harbour.h"

#include <vector>

Harbour::Harbour(Area *source, double hp) : Infrastructure(hp, source)
{
    type = ::iHarbour;
};

void Harbour::addConnection(Area *destination, double distance)
{
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
    Harbour* newHarbour = new Harbour(newArea, this->HP);
    for(auto c : connectedHarbours) {
        if(c != nullptr && c->getDestination() != nullptr && c->getDestination()->getClonedArea() != nullptr && c->getDestination()->getClonedArea() != newArea) {
            newHarbour->addConnection(c->getDestination()->getClonedArea(), c->getDistance());
        }
    }
    return newHarbour;
}