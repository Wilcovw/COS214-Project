#ifndef STATIONED_H
#define STATIONED_H
#include "Status.h"
#include "Citizens.h"
#include "Fighting.h"

using namespace std;

class Stationed : public Status
{
public:
    virtual string getStatus();
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif