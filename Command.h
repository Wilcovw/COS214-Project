#ifndef COMMAND_H
#define COMMAND_H

class Country;
class Command
{
public:
    virtual void execute(Country *country) = 0;
    virtual bool isActive() = 0;
};
#endif