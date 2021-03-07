//
// Created by support on 06.03.2021.
//

#include "hko/IState.h"

namespace hko{

    IState::IState(IStateMachine& machine):
        m_machine(machine),
        m_window(machine.getWindow()) {

    }

    IState::~IState() {

    }
}