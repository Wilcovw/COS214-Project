//
// Created by wilco on 2022/10/16.
//

#ifndef FACTORY_AND_OBSERVER_INFRASTRUCTURE_H
#define FACTORY_AND_OBSERVER_INFRASTRUCTURE_H


class Infrastructure {
private:
    double HP;
//    Area *location;
public:
    double getHP();
    virtual void destroy();
};


#endif //FACTORY_AND_OBSERVER_INFRASTRUCTURE_H
