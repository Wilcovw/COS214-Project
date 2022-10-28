//
// Created by wilco on 2022/10/28.
//

#include <iostream>
#include "TestVehiclesCloneAndFactories.h"

#include "Vehicles.h"
#include "LandVehicles.h"
#include "AquaticVehicles.h"
#include "Aircraft.h"
#include "Infrastructure.h"
#include "AquaticVehicleFactory.h"
#include "LandVehicleFactory.h"
#include "AircraftFactory.h"
#include "Factory.h"
#include "ResearchAndDevelopmentCentre.h"
#include "AircraftDevelopment.h"

void TestVehiclesCloneAndFactories::testVehicles(int numVehicles){
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

    for (int i = 0; i < numVehicles; ++i) {
        delete vehicles[i];
    }

    delete clone;
}
void TestVehiclesCloneAndFactories::testFactory(int numVehicles){
    cout << "Test Factory:\n";
    int numFactories=3;
    Factory *f[numFactories];
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

    for (int i = 0; i < numVehicles; ++i) {
        delete v[i];
    }
    for (int i = 0; i < numFactories; ++i) {
        delete f[i];
    }

    delete clone;
}

void TestVehiclesCloneAndFactories::testMultipleClones(int numClones){
    Vehicles *v = new LandVehicles("T2",1,1,1);
    Vehicles **clones;

    cout << "Test Multiple Clones:\n";
    clones = v->clone(numClones);

    for (int i = 0; i < numClones; ++i) {
        clones[i]->print();
    }

    //deallocate
    for (int i = 0; i < numClones; ++i) {
        delete[] clones[i];
    }
    delete clones;
    delete v;

}

void TestVehiclesCloneAndFactories::testAddingToDevList(){
    ResearchAndDevelopmentCentre *r = new AircraftDevelopment();
    Vehicles *a1 = new Aircraft("aircraft1", 1,1,1);
    Vehicles *a2 = new Aircraft("aircraft2", 1,1,1);
    r->addToList(a1);
    cout << "Should have 1 item:\n";
    r->printList();
    r->startDeveloping();


    r->addToList(a1);
    r->addToList(a2);
    cout << "Should have 2 items:\n";
    r->printList();
    r->startDeveloping();

    cout << "List should be empty:\n";
    r->printList();

    cout << "Print new specs of 2 aircraft:\n";
    a1->print();
    a2->print();

    delete a1;
    delete a2;

}




