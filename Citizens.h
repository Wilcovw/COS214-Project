#ifndef CITIZENS_H
#define CITIZENS_H
#include "Status.h"
#include "Unlisted.h"
#include "RevolutionCommand.h"

using namespace std;

class Status;
/**
 * @brief Citizens store a group of people as a single object to be used in the state design pattern
 *
 */
class Citizens
{
private:
	Status *status;
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
	Citizens *clone();
};
#endif