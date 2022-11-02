#ifndef WARPHASE_H
#define WARPHASE_H
#include "WarEngine.h"

using namespace std;

class WarPhase
{
private:
	vector<Country*> allCountries;
    WarMap* map;
    Communication* communication;
public:
    WarPhase(vector<Country*> allCountries, Communication* c, WarMap* map);
    vector<Country*> getCountryGroup();
    WarMap* getMap();
    Communication* getCommunication();
};

#endif