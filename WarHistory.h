#ifndef WARHISTORY_H
#define WARHISTORY_H
#include <vector>
using namespace std;

class Memento;
/**
 * @brief WarHistory takes the role of the Caretaker in the Memento design pattern. It is used to keep the memento safe
 */
class WarHistory
{
private:
	vector<Memento*> warhistory;
public:
    /**
     * Default constructor
     */
    WarHistory();
    /**
     * @brief returns memento at index
     * @param index
     * @return Memento* - warhistory at index
     */
    Memento* getMementoAt(int index);
    /**
     * @brief returns the previous phase of war
     * @return Memento* - the most recent warhistory
     */
    Memento* getLastMemento();
    /**
     * @brief stores memento in warhistory list
     * @param memento
     */
    void storeMemento(Memento* memento);
    /**
     * @brief returns the entire history of a war
     * @return vector<Memento*> - warhistory
     */
    vector<Memento*> getEntireHistory();
};

#endif