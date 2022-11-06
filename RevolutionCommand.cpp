#include "RevolutionCommand.h"

RevolutionCommand::RevolutionCommand(bool s)
{
    this->active = s;
}

void RevolutionCommand::execute(Country *country)
{
    this->active = this->active ? false : true;
    country->revolt(active);
}

bool RevolutionCommand::isActive()
{
    return this->active;
}