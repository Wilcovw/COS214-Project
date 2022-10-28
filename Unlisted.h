#ifndef UNLISTED_H
#define UNLISTED_H
#include "Citizens.h"
#include "Status.h"
#include "Enlisted.h"
#include "Dead.h"

using namespace std;

class Unlisted : public Status
{
public:
    virtual string getStatus();
    virtual void handleChange(Citizens *c);
    virtual void die(Citizens *c);
};
#endif