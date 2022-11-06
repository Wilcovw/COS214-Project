#ifndef FIGHTING_H
#define FIGHTING_H
#include "Status.h"
#include "Citizens.h"
#include "Stationed.h"

using namespace std;

class Fighting : public Status
{
public:
	/**
	 * @brief Get the Status object
	 * 
	 * @return string 
	 */
    virtual string getStatus();
	/**
	 * @brief Manages the Status of the Citizen
	 * 
	 * @param c 
	 */
    virtual void handleChange(Citizens *c);
	/**
	 * @brief Kills of the passed in Citizen
	 * 
	 * @param c 
	 */
    virtual void die(Citizens *c);
};
#endif