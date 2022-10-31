//
// Created by wilco on 2022/10/16.
//

#include "ResearchAndDevelopmentCentre.h"

// TODO: Make virtual and expand to children
void ResearchAndDevelopmentCentre::destroy()
{
    vehicleToBeUpgraded.clear();
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