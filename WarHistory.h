#ifndef WARHISTORY_H
#define WARHISTORY_H
#include <vector>
using namespace std;

class Memento;
class WarHistory
{
private:
	vector<Memento*> warhistory;
public:
    WarHistory();
    Memento* getMementoAt(int index);
    Memento* getLastMemento();
    void storeMemento(Memento* memento);
    vector<Memento*> getEntireHistory();
};

#endif