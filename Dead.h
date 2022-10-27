#ifndef DEAD_H
#define DEAD_H
#include "Status.h"
#include "Citizens.h"

using namespace std;

class Dead : public Status
{
public:
    virtual string getStatus();
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif