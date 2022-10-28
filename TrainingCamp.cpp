#ifndef TRAININGCAMP_CPP
#define TRAININGCAMP_CPP
#include "TrainingCamp.h"
#include "GroundTroopTraining.h"
#include "NavyTraining.h"
#include "AirforceTraining.h"

TrainingCamp::TrainingCamp() {

}

void TrainingCamp::addTroop(Troops* theTroops) {
    Troops** temp = troops;
    troops = new Troops * [++numTroops];
    for(int i = 0; i < numTroops - 1; i++) {
        troops[i] = temp[i];
    }
    troops[numTroops - 1] = theTroops;
}

bool TrainingCamp::removeTroop(Troops* theTroops) {
    bool isThere = false;
    for(int i = 0; i < numTroops; i++) {
        if(troops[i] == theTroops) {
            isThere = true;
        }
    }
    if(isThere) {
        Troops** temp = troops;
        troops = new Troops * [numTroops];
        int x = 0;
        for(int i = 0; i < numTroops; i++) {
            if(theTroops != temp[i]) {
                troops[x++] = temp[i];
            }
        }
        --numTroops;
    }
    return isThere;
}

#endif