#include "CommunicationBroadcast.h"
#include <iostream>

void CommunicationBroadcast::notify(AssociatedCountries *countries)
{
    if (Relationship *relationship = dynamic_cast<Relationship *>(countries))
    {
        std::vector<AssociatedCountries *>::iterator it;
        for (it = countryList.begin(); it != countryList.end(); ++it)
        {
            (*it)->receiveMessage("Message");
        }
    }
    else if (Country *c = dynamic_cast<Country *>(countries->getParent()))
    {
        std::vector<AssociatedCountries *>::iterator it;
        for (it = countryList.begin(); it != countryList.end(); ++it)
        {
            (*it)->receiveMessage("Message");
        }
    }
}