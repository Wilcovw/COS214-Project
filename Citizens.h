#ifndef CITIZENS_H
#define CITIZENS_H
#include "Status.h"
#include "Unlisted.h"
#include "Dead.h"

using namespace std;

class Status; // forward declaration
class Citizens
{
private:
    int numberCitizens;
    Status *status;

public:
    Citizens();
    ~Citizens();

    int getNumberCitizens();
    void changeStatus();
    void setStatus(Status *status);
    Status *getStatus();
};
#endif