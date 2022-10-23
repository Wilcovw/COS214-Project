#include <iostream>
#include "AssociatedCountries.h"
#include "Country.h"
#include "Relationship.h"
int main()
{
    AssociatedCountries *countriesAtWar = new Relationship("Countries in the war");
    AssociatedCountries *allies = new Relationship("Allies");
    AssociatedCountries *axis = new Relationship("Axis");

    allies->addAssociatedCountries(new Country("England"));
    allies->addAssociatedCountries(new Country("France"));
    allies->addAssociatedCountries(new Country("America"));
    allies->addAssociatedCountries(new Country("Poland"));
    allies->addAssociatedCountries(new Country("Russia"));
    countriesAtWar->addAssociatedCountries(allies);
    axis->addAssociatedCountries(new Country("Germany"));
    axis->addAssociatedCountries(new Country("Italy"));
    countriesAtWar->addAssociatedCountries(axis);
    countriesAtWar->addAssociatedCountries(new Country("Switzerland"));

    std::cout << countriesAtWar->print() << std::endl;
}
