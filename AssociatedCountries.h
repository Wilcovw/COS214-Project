#ifndef ASSOCIATEDCOUNTRIES_H
#define ASSOCIATEDCOUNTRIES_H
#include <string>
class Communication;
/**
 * @brief AssociatedCountries takes the role of the Component class in the composite pattern and Colleague in the Mediator pattern
 * it is also the parent class of the Relationship and Country classes
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
     * @brief Set the Parent object, this method is only used by the composite design pattern and not for use by a client
     *
     */
    virtual void setParent(AssociatedCountries *parent) = 0;
    /**
     * @brief Add a country to to the tree of associated couintries
     *
     * @param al  The country to be added to the tree
     */
    virtual void addAssociatedCountries(AssociatedCountries *al){};
    /**
     * @brief Remove a country from the tree of associated couintries
     *
     * @param al The country to be removed from the tree
     */
    virtual void removeAssociatedCountries(AssociatedCountries *al) = 0;
    /**
     * @brief Returns the Parent object
     *
     * @return AssociatedCountries - The parent object of the current object
     */
    virtual AssociatedCountries *getParent() = 0;
    /**
     * @brief Destroys the dynbamic objects in the object
     *
     */
    virtual ~AssociatedCountries(){};
    /**
     * @brief Allows this object to receive messages from other AssociatedCountries objects
     *
     * @param std::string The message received from the other AssociatedCountries object
     */
    virtual void receiveMessage(std::string message) = 0;
    /**
     * @brief Allows this object to send messages from other AssociatedCountries objects
     *
     * @param AssociatedCountries The AssociatedCountries object that must receive the message
     * @param std::string The message to be received
     */
    virtual void sendBroadcast(AssociatedCountries *messageReceiver, std::string message) = 0;
    /**
     * @brief Output the contents of this AssociatedCountries object
     *
     * @return std::string - The string containing the contents of this AssociatedCountries object
     */
    virtual std::string print() = 0;
    /**
     * @brief Returns a deep copy of the AssociatedCountries object and its children
     *
     * @param comm The comunication object used between all countries
     * @return AssociatedCountries* The cloned copy of the AssociatedCountries object
     */
    virtual AssociatedCountries *clone(Communication *comm, AssociatedCountries *parent) = 0;
};
#endif