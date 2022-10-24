#include <iostream>
#include "Citizens.h"

using namespace std;

int main(){
    Citizens *citizens = new Citizens();
    for (int i = 0; i < 10; i++)
    {
        string currentStatus = citizens->getStatus()->getStatusReport(citizens);
        cout <<"Current state of these citizens are: " << currentStatus <<endl;
        citizens->changeStatus();
    }
    delete citizens;

    return 0;
}