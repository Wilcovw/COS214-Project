#include <iostream>
#include "Vehicles.h"
#include "LandVehicles.h"
#include "AquaticVehicles.h"
#include "Aircraft.h"
#include "Infrastructure.h"
#include "AquaticVehicleFactory.h"
#include "LandVehicleFactory.h"
#include "AircraftFactory.h"
#include "Factory.h"

void testVehicles(int numVehicles){
    cout << "Test Vehicles:\n";
    Vehicles *vehicles[numVehicles];

    for (int i = 0; i < numVehicles; ++i) {
        // 3 types of vehicles
        switch (i%3) {
            case 0:
                vehicles[i] = new LandVehicles("BMW", 20, 10, 200);
                break;
            case 1:
                vehicles[i] = new Aircraft("Fighter Jet", 30, 200, 150);
                break;
            case 2:
                vehicles[i] = new AquaticVehicles("BO-AT", 100, 30, 50);
                break;


        }
        vehicles[i]->print();
    }
    
    //Clone
    Vehicles *clone = vehicles[0]->clone();
    cout << "clone:" << endl;
    clone -> print();

}
void testFactory(int numVehicles){
    cout << "Test Factory:\n";
    Factory *f[3];
    f[0] = new LandVehicleFactory();
    f[1] = new AircraftFactory();
    f[2] = new AquaticVehicleFactory();
    Vehicles *v[numVehicles];
    for (int i = 0; i < numVehicles; ++i) {
        switch (i%3) {
            case 0:
                v[i] = f[0]->createVehicle("BMW", 20, 10, 200);
                break;
            case 1:
                v[i] = f[1]->createVehicle("Fighter Jet", 30, 200, 150);
                break;
            case 2:
                v[i] = f[2]->createVehicle("BO-AT", 100, 30, 50);
                break;
        }
        v[i]->print();

    }
    Vehicles *clone;
    clone = f[0]->createVehicle("Honda", 10, 10, 10)->clone();
    cout << "clone:\n";
    clone->print();
}

void testMultipleClones(int numClones){
    Vehicles *v = new LandVehicles("T2",1,1,1);
    Vehicles **clones;

    cout << "Test Multiple Clones:\n";
    clones = v->clone(numClones);

    for (int i = 0; i < numClones; ++i) {
        clones[i]->print();
    }

    //deallocate
    for (int i = 0; i < numClones; ++i) {
        delete clones[i];
    }
    delete clones;
    delete v;

}

int main() {
//    testVehicles(10);
//    testFactory(10);
//    testMultipleClones(5);
  


    return 0;
}
