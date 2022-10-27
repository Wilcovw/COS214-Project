#ifndef UNLISTED_H
#define UNLISTED_H
#include "Citizens.h"
#include "Status.h"
#include "Enlisted.h"

using namespace std;

class Citizens;
class Unlisted : public Status
{
public:
    virtual string getStatus();
    virtual void handleChange(Citizens* c);
};
#endif