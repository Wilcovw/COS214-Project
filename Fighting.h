#ifndef FIGHTING_H
#define FIGHTING_H
#include "Status.h"
#include "Citizens.h"
#include "Stationed.h"

using namespace std;

class Fighting : public Status
{
public:
    virtual string getStatus();
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif