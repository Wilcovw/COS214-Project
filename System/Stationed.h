#ifndef STATIONED_H
#define STATIONED_H
#include "Status.h"
#include "Citizens.h"
#include "Fighting.h"

using namespace std;
/**
 * @brief Stationed is a Status of Citizens. It inherits from Status
 */
class Stationed : public Status
{
public:
    /**
     * @brief sets c's status to Fighting status
     * @param c
     */
    virtual void handleChange(Citizens *c);
    /**
     * @brief returns current class' status
     * @return string - the word "Stationed"
     */
    virtual string getStatus();
    /**
     * sets c's status to Dead status
     * @param c
     */
    virtual void die(Citizens *c);
};
#endif