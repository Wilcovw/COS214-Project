#ifndef REVOLUTION_COMMAND_H
#define REVOLUTION_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Country.h"

using namespace std;

class RevolutionCommand : public Command
{
private:
    bool active;
public:
	/**
	 * @brief Construct a new Revolution Command object
	 * 
	 * @param s 
	 */
    RevolutionCommand(bool s);
	/**
	 * @brief Destroy the Revolution Command object
	 * 
	 */
    ~RevolutionCommand();
	/**
	 * @brief Execeute the Revolution
	 * 
	 */
    void execute();
	/**
	 * @brief Determines whether the Command
	 * 
	 * @return true 
	 * @return false 
	 */
    bool isActive();
};
#endif