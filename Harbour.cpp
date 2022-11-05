#include "Harbour.h"
#include "Edge.h"

#include <list>

Harbour::Harbour(Area *source, double hp) : Infrastructure(hp, source) {
    type = ::iHarbour;
};

Harbour::~Harbour() {
    for (auto e : edges) {
        if(e->getSource() == location) {
           removeConnection(e->getSource(), e->getDestination()->getHarbourInArea(), e);
        } else {
           removeConnection(e->getSource(), e->getSource()->getHarbourInArea(), e);
        }
    }
}

void Harbour::addConnection(Area *destination, double distance, Harbour* otherHarbour)
{
    Edge *path = new Edge(distance, "Harbour", location, destination);
    Edge *reversePath = new Edge(distance, "Harbour", destination, location);

    edges.push_back(path);
    edges.push_back(reversePath);
    if(otherHarbour != this) {
        otherHarbour->edges.push_back(path);
        otherHarbour->edges.push_back(reversePath);
    }
    location->addEdge(path);
    destination->addEdge(reversePath);
    location->addHarbour(this);
    destination->addHarbour(otherHarbour);
};

void Harbour::removeConnection(Area* destination, Harbour* otherHarbour, Edge* path) {
    if(otherHarbour != nullptr && otherHarbour != this) {
        otherHarbour->edges.remove(path);
    }
    if(destination != nullptr) {
        destination->removeEdge(path);
    }
    location->addHarbour(nullptr);
}

void Harbour::destroy() {
    delete this;
}

Infrastructure* Harbour::clone(Area* newArea) {
    Harbour* newHarbour = new Harbour(newArea, this->HP);
    for(auto c : edges) {
        if(c != nullptr && c->getDestination() != nullptr && c->getDestination()->getClonedArea() != nullptr && c->getDestination()->getClonedArea() != newArea) {
            newHarbour->addConnection(c->getDestination()->getClonedArea(), c->getDistance(), c->getDestination()->getHarbourInArea());
        }
    }
    return newHarbour;
}