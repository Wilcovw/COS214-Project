#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "Infrastructure.h"
using namespace std;

class Edge;
class Road : public Infrastructure
{
private:
    /**
     * @brief the connection between 2 Areas are connected by edges. In this class edges are roads, which go both directions
     */
    Edge **edges = new Edge *[2];
public:
    /**
     * @brief Constructor for roads. Adds road to source and destination.
     * @param source
     * @param destination
     * @param hp
     * @param distance
     */
    Road(Area*, Area *, double, double);
    /**
     * @brief destructor for class. Destroys road between current class and destination.
     */
    ~Road();
    /**
     * @brief removes road between areas and calls destructor for this class.
     */
    virtual void destroy();
    /**
     * @brief Clones the road between the current destination and a new destination, with the same stats as the current road
     * @param newArea
     * @return Infrastructure* - a new road between the current area and newArea
     */
    virtual Infrastructure* clone(Area* newArea);
};

#endif