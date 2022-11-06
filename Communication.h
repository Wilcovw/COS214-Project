#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include "AssociatedCountries.h"
/**
 * @brief Communication takes the role of the Mediator in the Mediator design pattern
 *
 */
class Communication
{
public:
    /**
     * @brief Allowws a AssociatedCountries object to "register" themselves with this Communication instance
     *
     * @param AssociatedCountries the AssociatedCountries object to be registered
     */
    virtual void storeMe(AssociatedCountries *me) = 0;
    /**
     * @brief A method implemented in the concrete mediator class (CommunicationBroadcast) to notify all allied countries of changes in alliances
     *
     * @param countries Country in the affected relation change
     */
    virtual void notify(AssociatedCountries *countries, std::string message) = 0;
    /**
     * @brief Remove a country from the list of countries
     *
     * @param aC the country to be removed
     */
    virtual void removeAssociatedCountries(AssociatedCountries *aC) = 0;
    /**
     * @brief Destroy the dynamic objects created in the communication objects
     *
     */
    virtual ~Communication(){};
};
#endif