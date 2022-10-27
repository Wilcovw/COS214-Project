#ifndef ENLISTED_H
#define ENLISTED_H
#include "Status.h"
#include "Citizens.h"
#include "Stationed.h"

using namespace std;

class Citizens;
class Enlisted : public Status
{
public:
    virtual string getStatus();
    virtual void handleChange(Citizens *c);
};
#endif