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

#include "framework/gui/Button.h"
#include "framework/Utility.h"

namespace hko{
    Button::Button()
        : m_label(nullptr) {

    }

    Button::~Button() {

    }

    Button::Ptr Button::create() {
        return std::make_shared<Button>();
    }


    void Button::setOnClick(const std::function<void()>& func) {
        m_callback = func;
    }

    void Button::setTexture(sf::Texture& texture) {
        m_sprite.setTexture(texture);
    }

    void Button::update(float dt) {
        if(m_intersects)
            m_callback();
        m_intersects = false;
    }

    bool Button::intersects(const sf::Vector2f& mousePos) {
        m_intersects = m_sprite.getGlobalBounds().contains(mousePos);
        return m_intersects;
    }

    void Button::draw(sf::RenderTarget &target,
                      sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(m_sprite, states);
        if(m_label != nullptr)
            target.draw(*m_label, states);
    }


    void Button::setPosition(const sf::Vector2f& pos) {
        GuiNode::setPosition(pos);
        m_sprite.setPosition(pos);

        if(m_label != nullptr){
            sf::FloatRect bound = m_sprite.getLocalBounds();
            m_label -> setPosition(sf::Vector2f(bound.width / 2,
                                                bound.height / 2));
        }

        centerOrigin(m_sprite);
    }

    void Button::setLabel(Label::Ptr label) {
        m_label = label;

        sf::FloatRect bound = m_sprite.getLocalBounds();
        m_label -> setPosition(sf::Vector2f(m_pos.x,
                                            m_pos.y));

    }

}