//
// Created by HP on 07.03.2021.
//

#include "hko/gui/Button.h"
#include "hko/Utility.h"

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