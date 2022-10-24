#ifndef STATUS_H
#define STATUS_H
#include <iostream>
#include <sstream>
#include "Citizens.h"

using namespace std;

class Citizens; // forward declaration

class Status // Abstract State class
{

private:
public:
    virtual ~Status();

    virtual string getStatusReport(Citizens *c) = 0; // returns current Stated
    virtual void handleChange(Citizens *c) = 0;      // handles State changes
    virtual void die(Citizens *c) = 0;
};
#endif