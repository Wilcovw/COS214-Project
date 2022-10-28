#ifndef MEDICS_H
#define MEDICS_H

class Medics : public TroopType {
    public:
        Medics();
        ~Medics();
        TroopType* changeType(theTroopTypes);
};

#endif