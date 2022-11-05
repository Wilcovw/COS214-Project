#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H
#include <vector>
#include <string>
#include "AssociatedCountries.h"

/**
 * @brief Relationship takes the role of the Composite class in the Composite design pattern and ConcreteColleague in the Mediator patten
 *
 */
class Relationship : public AssociatedCountries
{
private:
    /**
     * @brief alliances store all of the associated countries and their alliances
     *
     */
    std::vector<AssociatedCountries *> alliances;
    /**
     * @brief The type of relationship between the countries, eg: neutral, allies, enemies, etc
     *
     */
    std::string relationshipType;

public:
    /**
     * @brief Construct a new Relationship object and pass in the relationship type
     *
     * @param r The type of relationship between the countries
     */
    Relationship(std::string r, Communication *tele);
    /**
     * @brief Copy constructor for Relationship, This will create a full copy of the relationship all sub-relationships and countries
     *
     * @param relationship The relationship to copy
     */
    Relationship(Relationship &relationship, Communication *comm);
    /**
     * @brief Get the Relationship Type object
     *
     * @return std::string The relationship type name
     */
    std::string getRelationshipType();
    /**
     * @brief Add a new AssociatedCountries object to the tree
     *
     * @param al AssociatedCountries objct to be added
     */
    virtual void addAssociatedCountries(AssociatedCountries *al);
    /**
     * @brief Remove a AssociatedCountries object from the tree
     *
     * @param al The AssociatedCountries objct to be removed
     */
    virtual void removeAssociatedCountries(AssociatedCountries *al);
    /**
     * @brief Returns the alliances object
     *
     * @return A vector storing all the associated countries
     */
    std::vector<AssociatedCountries *> getRelationships();
    /**
     * @brief Destroy the Relationship object
     *
     */
    virtual ~Relationship();
    /**
     * @brief Allows this object to receive messages from other AssociatedCountries objects
     *
     * @param std::string The message received from the other AssociatedCountries object
     */
    virtual void receiveMessage(std::string message);
    /**
     * @brief Allows this object to send messages from other AssociatedCountries objects
     *
     * @param AssociatedCountries The AssociatedCountries object that must receive the message
     * @param std::string The message to be received
     */
    virtual void sendBroadcast(AssociatedCountries *messageReceiver, std::string message);
    /**
     * @brief Return the parent object of this object
     *
     * @return AssociatedCountries*
     */
    virtual AssociatedCountries *getParent();
    /**
     * @brief Set the Parent object
     *
     * @param parent The parent of this object
     */
    virtual void setParent(AssociatedCountries *parent);
    /**
     * @brief Output the contents of this AssociatedCountries object
     *
     * @return std::string - The string containing the contents of this AssociatedCountries object
     */
    virtual std::string print();
    /**
     * @brief Returns a deep copy of the AssociatedCountries object and its children
     *
     * @param comm The comunication object used between all countries
     * @return AssociatedCountries* - The cloned copy of the AssociatedCountries object
     */
    virtual AssociatedCountries *clone(Communication *comm);
};
#endif