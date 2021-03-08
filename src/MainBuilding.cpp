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