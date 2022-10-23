#ifndef ASSOCIATEDCOUNTRIES_H
#define ASSOCIATEDCOUNTRIES_H
// #include "Communication.h"
// #include "Relationship.h"
// #include "Country.h"
#include <string>
class Communication;
/**
 * @brief AssociatedCountries takes the role of the Component class in the composite pattern and Colleague in the Mediator pattern
 *
 */
class AssociatedCountries
{
protected:
    /**
     * @brief Stores the parent object of the component
     *
     */
    AssociatedCountries *parent;
    /**
     * @brief Stores the communication object used in the Mediator design pattern
     *
     */
    Communication *tele;

public:
    /**
     * @brief Add a country to to the tree of associated couintries
     *
     * @param al  The country to be added to the tree
     */
    virtual void addAssociatedCountries(AssociatedCountries *al) = 0;
    /**
     * @brief Remove a country from the tree of associated couintries
     *
     * @param al The country to be removed from the tree
     */
    virtual void removeAssociatedCountries(AssociatedCountries *al) = 0;
    /**
     * @brief Returns the Parent object
     *
     * @return The parent object of the current object
     */
    virtual AssociatedCountries *getParent() = 0;
    /**
     * @brief Set the Parent object
     *
     */
    virtual void setParent(AssociatedCountries *parent) = 0;
    /**
     * @brief Destroy the Associated Countries object
     *
     */
    // virtual ~AssociatedCountries();
    /**
     * @brief Allows this object to receive messages from other AssociatedCountries objects
     *
     * @param mess The message received from the other AssociatedCountries object
     */
    virtual void receiveMessage(std::string mess) = 0;
    /**
     * @brief Allows this object to send messages from other AssociatedCountries objects
     *
     */
    virtual void sendBroadcast() = 0;
    virtual std::string print() = 0;
};
#endif