#ifndef ENLISTED_H
#define ENLISTED_H
#include "Status.h"
#include "Citizens.h"
#include "Stationed.h"

using namespace std;
/**
 * @brief Enlisted is a state of a citizen who has been drafted into the military but is not yet stationed
 *
 */
class Enlisted : public Status
{
public:
    /**
     * @brief Virtual function that returns the status of class
     *
     */
    virtual string getStatus();
    /**
     * @brief Virtual function that handles a new change
     *
     * @param Citzens** new citizen class to be handled
     */
    virtual void handleChange(Citizens *c);
    /**
     * @brief Returns all the citzens of the country
     *
     * @return Citzens**
     */
    virtual void die(Citizens *c);
};
#endif