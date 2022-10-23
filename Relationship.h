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
    Relationship(std::string r);
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
     * @param mess The message received from the other AssociatedCountries object
     */
    virtual void receiveMessage(std::string mess);
    /**
     * @brief Allows this object to send messages from other AssociatedCountries objects
     *
     */
    virtual void sendBroadcast();
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
     * @brief Returns a string countaining all the AssociatedCountries objects in it
     *
     * @param rel The relationship whos objects should be printed
     * @return std::string  The output string
     */
    virtual std::string print();
};
#endif