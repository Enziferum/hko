//
// Created by HP on 07.03.2021.
//

#pragma once

#include "GuiNode.h"

namespace hko{

    class Gui: public sf::Drawable{
    public:
        Gui();
        ~Gui();

        void pack(GuiNode::Ptr m_node);
        void resize(const sf::Vector2u& new_size);


        void handleEvents(const sf::Event& event);
        void update(float dt);
    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        std::vector<GuiNode::Ptr> m_nodes;
    };
}