#include "RevolutionCommand.h"

RevolutionCommand::RevolutionCommand(bool s) {
    this->active = s;
}

void RevolutionCommand::execute() {
    this->active = this->active ? false : true;
    // TODO: Insert Reciever action()

    // Country::revolt(active);
    
}

bool RevolutionCommand::isActive() {
    return this->active;
}