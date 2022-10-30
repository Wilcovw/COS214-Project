#ifndef REVOLUTION_COMMAND_H
#define REVOLUTION_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Country.h"

using namespace std;

class RevolutionCommand : public Command
{
private:
    bool active;
public:
    RevolutionCommand(bool s);
    ~RevolutionCommand();

    void execute();
    bool isActive();
};
#endif