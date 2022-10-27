#ifndef CITIZENS_H
#define CITIZENS_H
#include "Status.h"
#include "Unlisted.h"

using namespace std;

class Status; // forward declaration
class Citizens
{
private:
    Status *status;

public:
    Citizens();
    ~Citizens();

    void changeStatus();
    void setStatus(Status *status);
    string getStatus();
};
#endif