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

#include "hko/gui/ScrollBar.h"

namespace hko{
    ScrollBar::ScrollBar():
    m_start(0),
    m_end(0),
    m_current(0){

    }

    void ScrollBar::between(const float &start, const float &end) {
        //nothing to scroll
        if(start >= end)
            return;

        m_start = start;
        m_current = start;
        m_end = end;
    }

    void ScrollBar::handleEvents(const sf::Event& event) {
        //check if pressed to
        if(event.type == sf::Event::MouseButtonPressed){

        }
    }


    void ScrollBar::update(float dt) {

    }

    void ScrollBar::setPosition(const sf::Vector2f &f) {
        GuiNode::setPosition(f);
    }

    bool ScrollBar::intersects(const sf::Vector2f& mousePos) {
        bool res = false;

        return false;
    }



    void ScrollBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        GuiNode::draw(target, states);
    }


    const float& ScrollBar::current_value() const {
        return m_current;
    }

    ScrollBar::Ptr ScrollBar::create() {
        return std::make_shared<ScrollBar>();
    }

    void ScrollBar::set_current(const float &value) {
        m_current = value;
    }


}