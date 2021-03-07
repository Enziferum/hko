//
// Created by support on 06.03.2021.
//

#include "hko/App.h"

namespace hko{
    App::App(): IStateMachine(sf::Vector2u(800, 600),
                              "Hko") {

    }

    void App::register_state(const int& idx, IState::Ptr state) {
        //don't allocate memory
        if(state == nullptr)
            return;

        auto found = m_states.find(idx);
        if(found != m_states.end()){
            //already have state

            return;
        }

        m_states.insert(std::pair<int, IState::Ptr>(idx, state));
    }

    void App::run() {
        sf::Event event;

        while (m_window.isOpen()){
            handleEvents(event);
            update();
            render();
        }
    }

    void App::handleEvents(sf::Event& event) {
        while (m_window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                m_window.close();

            m_states[m_currentState]->handleEvents(event);
        }
    }

    void App::update() {
        m_states[m_currentState]->update(deltaTime);
    }

    void App::render() {
        m_window.clear(sf::Color::Black);
        m_states[m_currentState]->render();
        m_window.display();
    }

}