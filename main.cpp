#include <iostream>
#include "AssociatedCountries.h"
#include "Country.h"
#include "Relationship.h"
#include "CommunicationBroadcast.h"
int main()
{
    Communication *tele = new CommunicationBroadcast();
    AssociatedCountries *countriesAtWar = new Relationship("Countries in the war", tele);
    AssociatedCountries *allies = new Relationship("Allies", tele);
    AssociatedCountries *axis = new Relationship("Axis", tele);
    Country *germany = new Country("Germany", tele);

    allies->addAssociatedCountries(new Country("England", tele));
    allies->addAssociatedCountries(new Country("France", tele));
    allies->addAssociatedCountries(new Country("America", tele));
    allies->addAssociatedCountries(new Country("Poland", tele));
    allies->addAssociatedCountries(new Country("Russia", tele));
    countriesAtWar->addAssociatedCountries(allies);
    axis->addAssociatedCountries(germany);
    axis->addAssociatedCountries(new Country("Italy", tele));
    countriesAtWar->addAssociatedCountries(axis);
    countriesAtWar->addAssociatedCountries(new Country("Switzerland", tele));

    // std::cout << countriesAtWar->print();

    germany->sendBroadcast(allies, "We (germany) declare war against you");
    allies->sendBroadcast(germany, "We (allies) accept your declaration of war and respond in kind");
}
