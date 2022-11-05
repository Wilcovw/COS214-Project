#ifndef NAVYTRAINING_H
#define NAVYTRAINING_H
#include "TrainingCamp.h"

class NavyTraining : public TrainingCamp
{
public:
    /**
     * @brief Constructor for class. Sets type to NavyCamp
     */
    NavyTraining(double, Area *);
    /**
     * @brief Virtual destructor for class
     */
    virtual ~NavyTraining();
    /**
     * @brief Changes state of a citizen to a soldier by enlisting them
     * @return Troops* - the newly enlisted troop, which was a citizen
     */
    virtual Troops *startDrafting(Citizens *);
    /**
     * @brief calls the destructor for the class.
     */
    virtual void destroy();
    /**
     * @brief Makes a copy of the TrainingCamp, with the same stats, but adds it in a passed in location
     * @param newArea
     * @return Infrastructure* - A clone of this object, but with a passed in newArea where it is located
     */
    virtual Infrastructure *clone(Area *);
};

#endif