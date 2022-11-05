#ifndef COUNTRY_H
#define COUNTRY_H
#include "AssociatedCountries.h"
#include "Citizens.h"
#include "Area.h"
#include <string>
#include <vector>

class WarEntities;
class Area;
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
     * @brief Array of all the citzens of the country and thier state
     *
     */
    Citizens **citizens;
    /**
     * @brief Stores the number groups of citizens in the citizens array
     *
     */
    int numCitzenGroups;
    /**
     * @brief All the WarEntities the country owns
     *
     */
    WarEntities *entities;
    /**
     * @brief All the areas that this country controls
     *
     */
    std::list<Area *> areas;

public:
    /**
     * @brief Construct a new Country object
     *
     * @param name The name of the country
     * @param tele The Communication object used for communication between associatedCountries
     * @param numCitzenGroups The number of citizens inside the country to be created
     */
    Country(std::string name, Communication *tele, int numCitzenGroups);
    /**
     * @brief default constructor
     *
     */
    Country(Country &country, Communication *comm, AssociatedCountries *parent);
    /**
     * @brief Return the name of the Country
     *
     * @return std::string
     */
    std::string getName();
    /**
     * @brief Return the Areas controlled by this Country
     *
     * @return vector<Area*> The vector of areas controlled by this Country
     */
    std::list<Area *> getAreas();
    /**
     * @brief add a new Area to the vector containing all the areas that are controlled by this Country
     *
     * @param area The new Area to add to the vector containing all the areas that are controlled by this Country
     */
    void addArea(Area *area);
    /**
     * @brief Remove an area from the vector containing all the areas that are controlled by this Country
     *
     * @param area  The Area to remove from the vector containing all the areas that are controlled by this Country
     */
    void removeArea(Area *area);
    /**
     * @brief print all the areas that are controlled by this Country
     *
     */
    std::string printAreas();
    /**
     * @brief Returns all the citzens of the country
     *
     * @return Citzens**
     */
    Citizens **getCitizens();
    /**
     * @brief Get the Num Citzen Groups object
     *
     * @return int - The numCitzenGroups object
     */
    int getNumCitzenGroups();
    /**
     * @brief Returns all the WarEntities of the country
     *
     * @return WarEntities*
     */
    WarEntities *getWarEntities();
    /**
     * @brief Destroy the Country object
     *
     */
    virtual ~Country();
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
     * @brief Output the contents of this AssociatedCountries object
     *
     * @return std::string - The string containing the contents of this AssociatedCountries object
     */
    virtual std::string print();
    /**
     * @brief Allows the citizens of a country to revolt
     *
     * @param revolt Whether or not the citizerns are revolting
     */
    void revolt(bool revolt);
    /**
     * @brief Returns a deep copy of the AssociatedCountries object and its children
     *
     * @param comm The comunication object used between all countries
     * @return AssociatedCountries* The cloned copy of the AssociatedCountries object
     */
    virtual AssociatedCountries *clone(Communication *comm, AssociatedCountries *parent);
    /**
     * @brief Return all the allies of the current country, If this country has no allies or doesnt exist returns an empty vector
     *
     * @return vector<AssociatedCountries*> A vector containing all the allies of the current country
     */
    list<Country *> getAllies();
	/**
	 * @brief Get the Enemies the Current Country
	 * 
	 * @return list<Country *> 
	 */
    list<Country *> getEnemies();
	/**
	 * @brief Removes the passed in Citizen object from the Country
	 * 
	 */
    void removeCitizen(Citizens *);
};
#endif