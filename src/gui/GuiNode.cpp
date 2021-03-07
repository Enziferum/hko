//
// Created by HP on 07.03.2021.
//

#include "hko/gui/GuiNode.h"

namespace hko{
    GuiNode::GuiNode():
        m_intersects(false) {

    }

    GuiNode::~GuiNode() {

    }

    void GuiNode::setPosition(const sf::Vector2f& pos) {
        m_pos = pos;
    }

    void GuiNode::update(float dt) {

    }

    void GuiNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    }

    bool GuiNode::intersects(const sf::Vector2f &mousePos) {
        return false;
    }


}
