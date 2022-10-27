#include <iostream>
#include "Citizens.h"

using namespace std;

int main() {
    Citizens* citizens = new Citizens;
    for (int i = 0; i < 10; i++)
    {
        string status = citizens->getStatus();
        cout << "Citizens are currently: " << status << endl;
        citizens->changeStatus();
    }
    
    return 0;
}