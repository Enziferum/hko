//
// Created by HP on 07.03.2021.
//

#include "hko/gui/Gui.h"

namespace hko{
    Gui::Gui() {
    }

    Gui::~Gui() {
    }

    void Gui::pack(GuiNode::Ptr m_node) {
        if(m_node == nullptr)
            return;

        m_nodes.push_back(m_node);
    }

    void Gui::handleEvents(const sf::Event &event) {
        if(event.type == sf::Event::MouseButtonPressed){
            sf::Vector2f mouse_pos(event.mouseButton.x, event.mouseButton.y);
            for(auto& it: m_nodes)
                if(it->intersects(mouse_pos)){
                    //todo smth
                }
        }
    }

    void Gui::update(float dt) {
        for(auto& it: m_nodes)
            it->update(dt);
    }

    void Gui::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        for(auto& it: m_nodes)
            target.draw(*it);
    }

    void Gui::resize(const sf::Vector2u& new_size) {

    }


}