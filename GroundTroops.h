#ifndef GROUNDTROOPS_H
#define GROUNDTROOPS_H
#include "Troops.h"

class GroundTroops : public Troops {
    public:
        GroundTroops(Area*, TroopType*);
        virtual ~GroundTroops();
};

#endif