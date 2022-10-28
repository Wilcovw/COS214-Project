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
    /**
     * @brief A vector containing all the AssociatedCountries objects that called the storeMe() function
     *
     */
    std::vector<AssociatedCountries *> countryList;

public:
    /**
     * @brief Construct a new Communication Broadcast object
     *
     */
    CommunicationBroadcast();
    /**
     * @brief Allowws a AssociatedCountries object to "register" themselves with this Communication instance
     *
     * @param AssociatedCountries the AssociatedCountries object to be registered
     */
    virtual void storeMe(AssociatedCountries *me);
    /**
     * @brief Notifies all the countries in the countryList vector of changes in this country's alliances
     *
     * @param countries  Country in the affected relation change of the current country
     */
    virtual void notify(AssociatedCountries *countries, std::string message);
    /**
     * @brief Destroy the dynamic objects created in the communication objects
     *
     */
    virtual ~CommunicationBroadcast();
};
#endif