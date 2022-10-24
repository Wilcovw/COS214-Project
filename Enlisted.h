#ifndef ENLISTED_H
#define ENLISTED_H
#include "Status.h"
#include "Fighting.h"
#include "Stationed.h"
#include "Dead.h"

using namespace std;

class Enlisted : public Status
{
public:
    virtual string getStatusReport(Citizens *c);
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif