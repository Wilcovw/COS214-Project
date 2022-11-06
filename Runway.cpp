#include "Runway.h"
#include "Edge.h"
#include <list>

Runway::Runway(Area *source, double hp) : Infrastructure(hp, source)
{
    type = ::iRunway;
};

Runway::~Runway()
{
    if (!edges.empty())
    {
        for (auto e : edges)
        {
            if (e != nullptr)
            {
                if (e->getSource() == location)
                {
                    removeConnection(e->getSource(), e->getDestination()->getRunwayInArea(), e);
                }
                else
                {
                    removeConnection(e->getSource(), e->getSource()->getRunwayInArea(), e);
                }
            }
        }
    }
}

void Runway::addConnection(Area *destination, double distance, Runway *otherRunway)
{
    if (otherRunway != nullptr)
    {
        bool alreadyThere = false;
        for (auto e : otherRunway->edges)
        {
            if (e->getSource() == location && e->getDestination() == destination)
            {
                alreadyThere = true;
                break;
            }
        }
        if (!alreadyThere)
        {
            Edge *flight = new Edge(distance, "Runway", location, destination);
            Edge *returnFlight = new Edge(distance, "Runway", destination, location);

            edges.push_back(flight);
            edges.push_back(returnFlight);
            if (otherRunway != this)
            {
                otherRunway->edges.push_back(flight);
                otherRunway->edges.push_back(returnFlight);
            }
            location->addEdge(flight);
            destination->addEdge(returnFlight);
            location->addRunway(this);
            destination->addRunway(otherRunway);
        }
    }
}

void Runway::removeConnection(Area *destination, Runway *otherRunway, Edge *path)
{
    if (otherRunway != nullptr && otherRunway != this)
    {
        otherRunway->edges.remove(path);
    }
    if (destination != nullptr)
    {
        destination->removeEdge(path);
    }
    location->addRunway(nullptr);
}

void Runway::destroy()
{
    delete this;
}

Infrastructure *Runway::clone(Area *newArea)
{
    Runway *newRunway = new Runway(newArea, this->HP);
    for (auto f : edges)
    {
        if (f != nullptr && f->getDestination() != nullptr && f->getDestination()->getClonedArea() != nullptr && f->getDestination()->getClonedArea() != newArea)
        {
            newRunway->addConnection(f->getDestination()->getClonedArea(), f->getDistance(), f->getDestination()->getRunwayInArea());
        }
    }
    return newRunway;
}