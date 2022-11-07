#ifndef HARBOUR_H
#define HARBOUR_H
#include <list>
#include <iostream>
#include "Infrastructure.h"

using namespace std;

class Edge;
class Harbour : public Infrastructure
{
private:
    string name;
    list<Edge*> edges;

public:
	/**
	 * @brief Construct a new Harbour object
	 * 
	 */
    Harbour(Area *, double);
	/**
	 * @brief Destroy the Harbour object
	 * 
	 */
    ~Harbour();
	/**
	 * @brief Addes an Edge between 2 Areas
	 * 
	 * @param destination The desitination of the Harbour
	 * @param distance The travel distance
	 * @param otherHarbour The Harbour by the destination's Area
	 */
    void addConnection(Area* destination, double distance, Harbour* otherHarbour);
	/**
	 * @brief Removes an Edge between 2 Areas
	 * 
	 * @param destination The desitination of the Harbour
	 * @param otherHarbour The Harbour by the destination's Area
	 * @param path The Edge to remove
	 */
    void removeConnection(Area* destination, Harbour* otherHarbour, Edge* path);
	/**
	 * @brief Destroys the current Harbour
	 * 
	 */
    virtual void destroy();
	/**
	 * @brief Makes a copy of the current Object
	 * 
	 * @param newArea The current Area it is in.
	 * @return Infrastructure* 
	 */
    virtual Infrastructure* clone(Area* newArea);
};


#endif