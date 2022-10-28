#ifndef GENERALS_H
#define GENERALS_H

class Generals : public TroopType {
    public:
        Generals();
        ~Generals();
        TroopType* changeType(theTroopTypes);
};
#endif