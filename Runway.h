#ifndef RUNWAY_H
#define RUNWAY_H

#include <iostream>
#include <list>
#include "Infrastructure.h"
using namespace std;

class Edge;
class Runway : public Infrastructure
{
private:
    /**
     * @brief Name of the runway
     */
    string name;
    /**
     * @brief connects to all other airports
     */
    list<Edge*> edges;
public:
    /**
     * @brief Constructor - Creates a new Infrastructure, runway, and sets type to Runway
     */
    Runway(Area *, double);
    /**
     * @brief Destructor - removes current runway from all connected edges and destroys the current airway
     */
    ~Runway();
    /**
     * @brief Creates a new connection between this runway and all other runways
     * @param destination
     * @param distance
     * @param otherRunway
     */
    void addConnection(Area *destination, double distance, Runway* otherRunway);
    /**
     * @brief removes connection between current runway and other runways.
     * @param destination
     * @param otherRunway
     * @param path
     */
    void removeConnection(Area* destination, Runway* otherRunway, Edge* path);
    /**
     * @brief calls current class' destructor
     */
    virtual void destroy();
    /**
     * @brief Clones the runway between the current destination and a new destination, with the same stats as the current runway
     * @param newArea
     * @return
     */
    virtual Infrastructure* clone(Area* newArea);
};

#endif