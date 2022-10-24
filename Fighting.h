#ifndef FIGHTING_H
#define FIGHTING_H
#include "Status.h"
#include "Stationed.h"
#include "Dead.h"

using namespace std;

class Fighting : public Status
{
public:
    virtual string getStatusReport(Citizens *c);
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif