#ifndef WARHISTORY_H
#define WARHISTORY_H
#include <list>
#include <iostream>
using namespace std;

class Memento;
/**
 * @brief WarHistory takes the role of the Caretaker in the Memento design pattern. It is used to keep the memento safe
 */
class WarHistory
{
private:
    list<Memento *> history;

public:
    /**
     * Default constructor
     */
    WarHistory();
    /**
     * @brief returns the previous phase of war
     * @return Memento* - the most recent warhistory
     */
    Memento *getLastMemento();
    /**
     * @brief stores memento in warhistory list
     * @param memento
     */
    void storeMemento(Memento *memento);
    /**
     * @brief returns the entire history of a war
     * @return list<Memento*> - warhistory
     */
    list<Memento *> getEntireHistory();
};

#endif