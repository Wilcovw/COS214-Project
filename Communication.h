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
    // Communication();
    virtual void storeMe(AssociatedCountries *me) = 0;
    /**
     * @brief A method implemented in the concrete mediator class (CommunicationBroadcast) to notify all allied countries of changes in alliances
     *
     * @param countries Country in the affected relation change
     */
    virtual void notify(AssociatedCountries *countries, std::string message) = 0;
    // virtual ~Communication() = 0;
};
#endif