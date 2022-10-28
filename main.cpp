#include <iostream>
#include "AssociatedCountries.h"
#include "Country.h"
#include "Relationship.h"
#include "CommunicationBroadcast.h"
#include "Citizens.h"

int main()
{
    Communication *tele = new CommunicationBroadcast();
    AssociatedCountries *countriesAtWar = new Relationship("Countries in the war", tele);
    AssociatedCountries *allies = new Relationship("Allies", tele);
    AssociatedCountries *axis = new Relationship("Axis", tele);
    Country *germany = new Country("Germany", tele);
    Citizens **citizens = germany->getCitizens();

    for (int i = 0; i < 5; i++)
    {
        citizens[i]->changeStatus();
        if (i == 3)
        {
            citizens[i]->die();
        }
    }

    for (int i = 0; i < germany->getNumCitzenGroups(); i++)
    {
        cout << "Group "<< i << " citizens current state: " << citizens[i]->getStatus() << endl;
    }
    
    

    // allies->addAssociatedCountries(new Country("England", tele));
    // allies->addAssociatedCountries(new Country("France", tele));
    // allies->addAssociatedCountries(new Country("America", tele));
    // allies->addAssociatedCountries(new Country("Poland", tele));
    // allies->addAssociatedCountries(new Country("Russia", tele));
    // countriesAtWar->addAssociatedCountries(allies);
    // axis->addAssociatedCountries(germany);
    // axis->addAssociatedCountries(new Country("Italy", tele));
    // countriesAtWar->addAssociatedCountries(axis);
    // countriesAtWar->addAssociatedCountries(new Country("Switzerland", tele));

    // std::cout << countriesAtWar->print();

    // axis->removeAssociatedCountries(germany);

    // std::cout << countriesAtWar->print();

    // germany->sendBroadcast(allies, "We (germany) declare war against you");
    // allies->sendBroadcast(germany, "We (allies) accept your declaration of war and respond in kind");
}