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

#include "framework/gui/Gui.h"

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