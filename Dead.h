#ifndef DEAD_H
#define DEAD_H
#include "Status.h"

using namespace std;

class Dead : public Status
{
public:
    virtual string getStatusReport(Citizens *c);
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif