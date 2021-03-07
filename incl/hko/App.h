//
// Created by support on 06.03.2021.
//

#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "IStateMachine.h"
#include "IState.h"

namespace hko{

    class App: public IStateMachine{
    public:
        App();
        ~App()override = default;

        void register_state(const int& idx, IState::Ptr state);
        void run();
    private:

        void handleEvents(sf::Event& event);
        void update();
        void render();
    private:
        std::unordered_map<int, IState::Ptr> m_states;

        float deltaTime = 0.f;
        float lastTime = 0.f;
    };

}