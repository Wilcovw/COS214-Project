#ifndef COMMAND_H
#define COMMAND_H

class Country;
class Command
{
public:
    /**
     * @brief Executes a revolt
     *
     * @param country Country That gets a revolution
     */
    virtual void execute(Country *country) = 0;
    /**
     * @brief Returns whether revolution is active
     *
     * @return bool
     */
    virtual bool isActive() = 0;
};
#endif