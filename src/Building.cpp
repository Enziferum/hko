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

#include "hko/Building.h"
#include "framework/Utility.h"

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