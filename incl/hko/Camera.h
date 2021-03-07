//
// Created by HP on 07.03.2021.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace hko{
    class Camera{
    public:
        Camera();
        ~Camera() = default;

        void handleEvents(const sf::Event& event);
        void update(float dt);

        sf::View& getView();
    private:
        sf::View m_view;
    };
}