#ifndef WARPHASE_H
#define WARPHASE_H
#include "WarEngine.h"

using namespace std;

class WarPhase
{
private:
	vector<Country*> countryGroup;
    vector<Area*> warTheatreGraph;
    WarMap map;
public:
    WarPhase(vector<Country*> countryGroup, vector<Area*> warTheatreGraph, WarMap map);
    vector<Country*> getCountryGroup();
    vector<Area*> getWarTheatreGraph();
    WarMap getMap();
};

#endif