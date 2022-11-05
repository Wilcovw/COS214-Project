#ifndef REVOLUTION_COMMAND_H
#define REVOLUTION_COMMAND_H
#include <iostream>
#include "Command.h"
#include "Country.h"

using namespace std;

class RevolutionCommand : public Command
{
private:
    /**
     * @brief a bool value to determine if there is a revolution or not
     */
    bool active;
public:
    /**
     * @brief Constructor for this class. Sets active to s
     * @param s
     */
    RevolutionCommand(bool s);
    /**
     * @brief Default destructor
     */
    ~RevolutionCommand();
    /**
     * @brief Starts the revolution
     */
    void execute();
    /**
     * @brief returns if there is currently a revolution active
     * @return true - a revolution is active
     * @return false - a revolution is not currently happening
     */
    bool isActive();
};
#endif