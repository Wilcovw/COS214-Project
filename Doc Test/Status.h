#ifndef STATUS_H
#define STATUS_H
#include <iostream>
#include <sstream>

using namespace std;

class Citizens; // forward declaration
/**
 * @brief Status is used by citizens. It has classes that inherit from it that is used to set a Citizen's state.
 */
class Status    // Abstract State class
{
public:
    /**
     * @brief virtual destructor
     */
    virtual ~Status();
    /**
     * @brief pure virtual function
     * @return string
     */
    virtual string getStatus() = 0;             // returns current State
    /**
      * @brief pure virtual function
      */
    virtual void handleChange(Citizens *c) = 0; // handles State changes
    /**
    * @brief pure virtual function
    */
    virtual void die(Citizens *c) = 0;          // group of citizens die
};
#endif