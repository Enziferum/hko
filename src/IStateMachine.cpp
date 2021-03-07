//
// Created by HP on 07.03.2021.
//

#include "hko/IStateMachine.h"

namespace hko{

    IStateMachine::IStateMachine(const sf::Vector2u& size, const std::string& name):
            m_window(sf::VideoMode(size.x, size.y), name){

    }

    IStateMachine::~IStateMachine() {

    }


    void IStateMachine::pushState(const int& idx) {
        m_currentState = idx;
    }

    sf::RenderWindow &IStateMachine::getWindow() {
        return m_window;
    }


}