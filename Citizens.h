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
	Status *status = nullptr;
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
	 * @brief 
	 * 
	 */
    void toggleRevolution();
    Citizens *clone();
};
#endif