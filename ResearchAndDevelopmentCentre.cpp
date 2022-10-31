
#include "ResearchAndDevelopmentCentre.h"

void ResearchAndDevelopmentCentre::destroy()
{
    delete this;
}
void ResearchAndDevelopmentCentre::notifyDevelop()
{
    vector<Vehicles *>::iterator it = vehicleToBeUpgraded.begin();
    while (it != vehicleToBeUpgraded.end())
    {
        (*it)->update();
        vehicleToBeUpgraded.erase(it);
    }
}

void ResearchAndDevelopmentCentre::startDeveloping()
{
    stopDeveloping();
}

void ResearchAndDevelopmentCentre::stopDeveloping()
{
    notifyDevelop();
}

void ResearchAndDevelopmentCentre::printList()
{
    vector<Vehicles *>::iterator it = vehicleToBeUpgraded.begin();
    for (it = vehicleToBeUpgraded.begin(); it != vehicleToBeUpgraded.end(); ++it)
    {
        (*it)->print();
    }
}

void ResearchAndDevelopmentCentre::addToList(Vehicles *v)
{
    if (v == NULL)
        return;

    vehicleToBeUpgraded.push_back(v);
}

ResearchAndDevelopmentCentre *ResearchAndDevelopmentCentre::clone()
{
    return new ResearchAndDevelopmentCentre(this->HP, this->location);
}