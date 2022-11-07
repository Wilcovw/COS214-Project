#ifndef UNLISTED_H
#define UNLISTED_H
#include "Citizens.h"
#include "Status.h"
#include "Enlisted.h"
#include "Dead.h"

using namespace std;

/**
 * @brief Unlisted is a Status of Citizens. It inherits from Status
 */
class Unlisted : public Status
{
public:
    /**
     * @brief returns the class' status
     * @return string - "Unlisted"
     */
    virtual string getStatus();
    /**
     * @brief sets c's status to Enlisted
     * @param c
     */
    virtual void handleChange(Citizens *c);
    /**
     * @brief sets c's status to Dead
     * @param c
     */
    virtual void die(Citizens *c);
};
#endif