//
// Created by HP on 07.03.2021.
//

#include "hko/Building.h"
#include "hko/Utility.h"

namespace hko{

    Building::Building():INode(),
        m_hp(0.f),
        m_cost(0) {

    }

    Building::~Building(){}

    void Building::draw(sf::RenderTarget& target,
                        sf::RenderStates states) const {
        target.draw(m_sprite);
    }

    void Building::setPosition(const sf::Vector2f &pos) {
        m_pos = pos;
        m_sprite.setPosition(pos);
        centerOrigin(m_sprite);
    }

    void Building::setTexture(sf::Texture& texture) {
        m_sprite.setTexture(texture);
    }

    bool Building::contains(const sf::Vector2f &pos) {
        return m_sprite.getGlobalBounds()
                .contains(pos);
    }


}