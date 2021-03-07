//
// Created by HP on 07.03.2021.
//

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