#include "RevolutionCommand.h"

RevolutionCommand::RevolutionCommand(bool s) {
    this->active = s;
}

void RevolutionCommand::execute() {
    this->active = this->active ? false : true;
    // TODO: Insert Reciever action()
    if (active)
    {
        cout << "Citizens started a revolution!" << endl;
    }
    else {
        cout << "The revolution has ended" << endl;
    }
    
}

bool RevolutionCommand::isActive() {
    return this->active;
}