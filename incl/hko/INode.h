//
// Created by HP on 07.03.2021.
//

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

namespace hko{

    class INode: public sf::Drawable{
    public:
        using Ptr = std::shared_ptr<INode>;
    public:
        INode();
        virtual ~INode() = 0;

        virtual void setPosition(const sf::Vector2f& pos) = 0;
        void draw(sf::RenderTarget &target, sf::RenderStates states) const  = 0;
    protected:
        sf::Vector2f m_pos;
    };
}
