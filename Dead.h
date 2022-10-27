#ifndef DEAD_H
#define DEAD_H
#include "Status.h"
#include "Citizens.h"

using namespace std;

class Citizens;
class Dead : public Status
{
public:
    virtual string getStatus();
    virtual void handleChange(Citizens *c);
};
#endif