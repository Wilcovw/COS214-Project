#include "Country.h"
#include "Communication.h"
#include <iostream>

Country::Country(std::string name)
{

    this->name = name;
}

std::string Country::getName()
{
    return name;
}

// Map Country::getMap()
// {
//     return map;
// }

// Citzens** Country::getCitzens()
// {
//     return citzens;
// }

// WarEntities Country::getWarEntities()
// {
//     return entities;
// }

// Country::~Country()
// {
//     // for (int i = 0; i < citzens.length; i++)
//     // {
//     //     delete citzens[i];
//     // }
//     // delete citzens;
// }

void Country::receiveMessage(std::string mess)
{
    std::cout << mess << std::endl;
}

void Country::sendBroadcast()
{
    tele->notify(this);
}

AssociatedCountries *Country::getParent()
{
    return parent;
}

void Country::setParent(AssociatedCountries *parent)
{
    this->parent = parent;
}

std::string Country::print()
{
    return name;
}

void Country::addAssociatedCountries(AssociatedCountries *al)
{
    parent->addAssociatedCountries(al);
}

void Country::removeAssociatedCountries(AssociatedCountries *al)
{
    parent->removeAssociatedCountries(al);
}