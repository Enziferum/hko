//
// Created by HP on 07.03.2021.
//

#include "hko/MainBuilding.h"

namespace hko{

    MainBuilding::MainBuilding(): Building()
    {
        m_type = buiding_Type::Main;
        m_hp = 400;
        m_cost = 400;
    }

    void MainBuilding::setScale(const sf::Vector2f& scale_factor) {
        auto bounds = m_sprite.getLocalBounds();
        auto scale = sf::Vector2f(128.f / bounds.width,
                                  128.f/ bounds.height);
        m_sprite.setScale(scale);
    }


}