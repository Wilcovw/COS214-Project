#include "TroopType.cpp"
#include "Troops.cpp"
#include "TrainingCamp.cpp"
#include <iostream>
using namespace std;
int main() {
    Area* testArea = new Area();

    TroopType* testGeneral = new Generals();
    TroopType* testSoldier = new Soldiers();
    TroopType* testMedic = new Medics();

    Troops* testGroundTroops = new GroundTroops(testArea, testSoldier);
    Troops* testNavy = new Navy(testArea, testMedic);
    Troops* testAirforce = new Airforce(testArea, testSoldier);

    TrainingCamp* testGroundTraining = new GroundTroopTraining();
    TrainingCamp* testNavyTraining = new NavyTraining();
    TrainingCamp* testAirforceTraining = new AirforceTraining();

    
    delete testGroundTraining;
    delete testNavyTraining;
    delete testAirforceTraining;
    cout << "No error" << endl;
    delete testGeneral;
    cout << "Success" << endl;
    delete testSoldier;
    delete testMedic;
    delete testArea;
    return 0;
}