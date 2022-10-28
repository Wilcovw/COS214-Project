#ifndef GROUNDTROOPTRAINING_P
#define GROUNDTROOPTRAINING_P
#include "GroundTroopTraining.h"

GroundTroopTraining::GroundTroopTraining() : TrainingCamp() {

}

void GroundTroopTraining::startTraining(Troops* theTroops) {
    Troops** temp = troops;
    troops = new Troops * [++numTroops];
    for(int i = 0; i < numTroops - 1; i++) {
        troops[i] = temp[i];
    }
    troops[numTroops - 1] = theTroops;
}

#endif