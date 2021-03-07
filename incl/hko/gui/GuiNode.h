//
// Created by HP on 07.03.2021.
//

#pragma once

#include <string>
#include <functional>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

namespace hko{

    class GuiNode: public sf::Drawable{
    public:
        using Ptr = std::shared_ptr<GuiNode>;
    public:
        GuiNode();
        virtual ~GuiNode();

        virtual void setPosition(const sf::Vector2f& );
        virtual bool intersects(const sf::Vector2f& mousePos);

        virtual void update(float dt);
    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    protected:
        bool m_intersects;
        sf::Vector2f m_pos;
    };
}
