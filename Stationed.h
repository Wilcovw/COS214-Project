#ifndef STATIONED_H
#define STATIONED_H
#include "Status.h"
#include "Fighting.h"
#include "Dead.h"

using namespace std;

class Stationed : public Status
{
public:
    virtual string getStatusReport(Citizens *c);
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif