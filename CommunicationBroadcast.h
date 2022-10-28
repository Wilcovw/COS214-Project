#ifndef COMMUNICATIONBROADCAST_H
#define COMMUNICATIONBROADCAST_H
#include "Communication.h"
#include "Relationship.h"
#include "Country.h"
#include <vector>
/**
 * @brief CommunicationBroadcast takes the role of the ConcreteMediator in the Mediator pattern
 *
 */
class CommunicationBroadcast
{
private:
    std::vector<AssociatedCountries *> countryList;

public:
    CommunicationBroadcast();
    /**
     * @brief Notifies all the countries in the countryList vector of changes in this country's alliances
     *
     * @param countries  Country in the affected relation change of the current country
     */
    void notify(AssociatedCountries *countries);
    ~CommunicationBroadcast();
};
#endif