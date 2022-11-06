#ifndef SOLDIERS_CPP
#define SOLDIERS_CPP
#include "Soldiers.h"
#include "SpecialForces.h"
#include "Generals.h"

// VALUES TO BE CHANGED
Soldiers::Soldiers() : TroopType(4, 20, 10)
{
    type = ::theSoldiers;
}

Soldiers::~Soldiers()
{
}

TroopType *Soldiers::changeType(theTroopTypes theType)
{
    if (theType != ::theSoldiers)
    {
        if (theType == ::theSpecialForces)
        {
            return new SpecialForces();
        }
        else if (theType == ::theGenerals)
        {
            return new Generals();
        }
    }
    return this;
}
#endif