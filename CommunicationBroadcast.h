#ifndef COMMUNICATIONBROADCAST_H
#define COMMUNICATIONBROADCAST_H
#include "Communication.h"
#include <vector>

/**
 * @brief CommunicationBroadcast takes the role of the ConcreteMediator in the Mediator pattern
 *
 */
class CommunicationBroadcast : public Communication
{
private:
    std::vector<AssociatedCountries *> countryList;

public:
    CommunicationBroadcast();
    virtual void storeMe(AssociatedCountries *me);
    /**
     * @brief Notifies all the countries in the countryList vector of changes in this country's alliances
     *
     * @param countries  Country in the affected relation change of the current country
     */
    virtual void notify(AssociatedCountries *countries, std::string message);
    virtual ~CommunicationBroadcast();
};
#endif