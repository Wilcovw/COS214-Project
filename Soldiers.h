#ifndef SOLDIERS_H
#define SOLDIERS_H

class Soldiers : public TroopType {
    public:
        Soldiers();
        TroopType* changeType(theTroopTypes);
};


#endif