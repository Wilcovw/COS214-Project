#include "CommunicationBroadcast.h"
#include "Relationship.h"
#include "Country.h"
#include <iostream>

CommunicationBroadcast::CommunicationBroadcast()
{
}

void CommunicationBroadcast::storeMe(AssociatedCountries *me)
{
    countryList.push_back(me);
}

void notifySubCountries(Relationship *rel, std::string message)
{
    std::vector<AssociatedCountries *> alliances = rel->getRelationships();
    std::vector<AssociatedCountries *>::iterator it;
    for (it = alliances.begin(); it != alliances.end(); ++it)
    {
        (*it)->receiveMessage(message);
    }
}

void CommunicationBroadcast::notify(AssociatedCountries *associatedCountry, std::string message)
{
    if (Relationship *relationship = dynamic_cast<Relationship *>(associatedCountry))
    {
        std::vector<AssociatedCountries *>::iterator it;
        for (it = countryList.begin(); it != countryList.end(); ++it)
        {
            if (Relationship *rel = dynamic_cast<Relationship *>(*it))
            {
                if ((rel->getRelationshipType()).compare(relationship->getRelationshipType()) == 0)
                {
                    notifySubCountries(relationship, message);
                }
            }
        }
    }
    else if (Country *country = dynamic_cast<Country *>(associatedCountry))
    {
        std::vector<AssociatedCountries *>::iterator it;
        for (it = countryList.begin(); it != countryList.end(); ++it)
        {
            if (Country *c = dynamic_cast<Country *>(*it))
            {
                if ((country->getName()).compare(c->getName()) == 0)
                {
                    c->receiveMessage(message);
                }
            }
        }
    }
}

CommunicationBroadcast::~CommunicationBroadcast()
{
}