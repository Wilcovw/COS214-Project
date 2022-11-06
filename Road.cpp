#include "Road.h"
#include "Edge.h"
#include "Country.h"
#include "WarEntities.h"

Road::Road(Area* source, Area *destination, double hp, double distance) : Infrastructure(hp, source)
{
    type = ::iRoad;
    edges[0] = new Edge(distance, "Road", location, destination);
    edges[1] = new Edge(distance, "Road", destination, location);
    
    location->addEdge(edges[0]);
    destination->addEdge(edges[1]);
    location->getControllingCountry()->getWarEntities()->addInfrastructure(this);
    if(location->getControllingCountry() != destination->getControllingCountry()) {
        destination->getControllingCountry()->getWarEntities()->addInfrastructure(this);
    }
};

Road::~Road() {
    if(edges[0]->getSource()->getControllingCountry() != edges[0]->getDestination()->getControllingCountry()) {
        edges[0]->getDestination()->getControllingCountry()->getWarEntities()->removeInfrastructure(this);
    }
    Area* destination;
    if(edges[0]->getSource() == location) {
        destination = edges[0]->getDestination();
    } else {
        destination = edges[0]->getSource();
    }
    location->removeEdge(edges[0]);
    destination->removeEdge(edges[1]);
}

void Road::destroy(){
    edges[0]->getSource()->getControllingCountry()->getWarEntities()->removeInfrastructure(this);
    delete this;
}

Infrastructure* Road::clone(Area* newArea) {    
    if(edges[0]->getDestination() != nullptr && edges[0]->getDestination()->getClonedArea() != nullptr) {
        Infrastructure* newRoad = new Road(newArea, edges[0]->getDestination()->getClonedArea(), HP, edges[0]->getDistance());
    }
    return newRoad;
}