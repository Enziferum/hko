/*********************************************************************
(c) Alex Raag 2021
https://github.com/Enziferum
hko - Zlib license.
This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.
2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/


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