#ifndef CITIZENS_H
#define CITIZENS_H
#include "Status.h"
#include "Unlisted.h"
#include "RevolutionCommand.h"

using namespace std;

class Status; // forward declaration
class Citizens
{
private:
    Status *status;
    Command *toggleCommand;

public:
    Citizens();
    ~Citizens();

    void changeStatus();
    void setStatus(Status *status);
    string getStatus();
    void die();
    void toggleRevolution();
    Citizens *clone();
};
#endif