#ifndef DEAD_H
#define DEAD_H
#include "Status.h"
#include "Citizens.h"

using namespace std;
/**
 * @brief A state for a citizen if they die
 *
 */
class Dead : public Status
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