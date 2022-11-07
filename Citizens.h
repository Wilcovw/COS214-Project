#ifndef CITIZENS_H
#define CITIZENS_H
#include "Status.h"
#include "Unlisted.h"
#include "RevolutionCommand.h"

using namespace std;

class Status; // forward declaration
class Citizens
{
private:
	/**
	 * @brief Stores the status of the citizen
	 *
	 */
	Status *status;
	/**
	 * @brief Safes the command pattern which can enable a revolution
	 *
	 */
	Command *toggleCommand;

public:
	/**
	 * @brief Construct a new Citizens object
	 *
	 */
	Citizens();
	/**
	 * @brief Destroy the Citizens object
	 *
	 */
	~Citizens();
	/**
	 * @brief Changes the Status of the current Citizen
	 *
	 */
	void changeStatus();
	/**
	 * @brief Set the Status object
	 *
	 * @param status The new status
	 */
	void setStatus(Status *status);
	/**
	 * @brief Returns the status description
	 *
	 * @return string
	 */
	string getStatus();
	/**
	 * @brief Kills the current Citizen
	 *
	 */
	void die();
	/**
	 * @brief calls a revolution in the country
	 *
	 */
	void toggleRevolution(Country *country);
	/**
	 * @brief calls clone on Citizens for the Memento pattern
	 *
	 */
	Citizens *clone();
};
#endif