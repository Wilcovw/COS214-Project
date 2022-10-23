#ifndef COUNTRY_H
#define COUNTRY_H
#include "AssociatedCountries.h"
#include <string>
/**
 * @brief Country takes the role of the Leaf class in the composite pattern and ConcreteColleague in the Mediator pattern
 *
 */
class Country : public AssociatedCountries
{
private:
    /**
     * @brief The country name
     *
     */
    std::string name;
    /**
     * @brief The WarMap of the all areas of importance throuout the war
     *
     */
    // Map map;
    /**
     * @brief Array of all the citzens of the country and thier state
     *
     */
    // Citzens** citzens;
    /**
     * @brief All the WarEntities the country owns
     *
     */
    // WarEntities* entities;
    /**
     * @brief All the areas that this country controls
     *
     */
    // Area** areas;
public:
    /**
     * @brief Construct a new Country object
     *
     * @param name The name of the country
     */
    Country(std::string name, Communication *tele);
    /**
     * @brief Return the name of the Country
     *
     * @return std::string
     */
    std::string getName();
    /**
     * @brief Return the WarMap
     *
     * @return WarMap
     */
    // Map getMap();
    /**
     * @brief Returns all the citzens of the country
     *
     * @return Citzens**
     */
    // Citzens** getCitzens();
    /**
     * @brief Returns all the WarEntities of the country
     *
     * @return WarEntities*
     */
    // WarEntities* getWarEntities();
    /**
     * @brief Destroy the Country object
     *
     */
    // virtual ~Country();
    /**
     * @brief Allows this object to receive messages from other AssociatedCountries objects
     *
     * @param mess The message received from the other AssociatedCountries object
     */
    virtual void receiveMessage(std::string message);
    /**
     * @brief Allows this object to send messages from other AssociatedCountries objects
     *
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
    virtual void addAssociatedCountries(AssociatedCountries *al);
    virtual void removeAssociatedCountries(AssociatedCountries *al);
    virtual std::string print();
};
#endif