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
    virtual string getStatus();
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif