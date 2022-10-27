#ifndef STATUS_H
#define STATUS_H
#include <iostream>
#include <sstream>

using namespace std;

class Citizens; // forward declaration
class Status // Abstract State class
{
public:
    virtual ~Status();

    virtual string getStatus() = 0; // returns current State
    virtual void handleChange(Citizens *c) = 0;      // handles State changes
};
#endif