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
    virtual string getStatus();
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif