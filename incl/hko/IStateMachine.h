//
// Created by HP on 07.03.2021.
//

#pragma once
#include <SFML/Graphics.hpp>

namespace hko{
    class IStateMachine{
    public:
        IStateMachine(const sf::Vector2u& size, const std::string& name);
        virtual ~IStateMachine();

        void pushState(const int& idx);
        sf::RenderWindow& getWindow();
    protected:
        sf::RenderWindow m_window;
        int m_currentState = 0;
    };
}
