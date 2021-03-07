//
// Created by HP on 07.03.2021.
//

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "INode.h"


namespace hko{
    enum class buiding_Type{
        None, Main, Barracks
    };

    class Building: public INode{
    public:
        using Ptr = std::shared_ptr<Building>;
    public:
        Building();
        ~Building()override;


        const buiding_Type& get_type(){
            return m_type;
        }

        bool contains(const sf::Vector2f& pos);

        void draw(sf::RenderTarget &target,
                  sf::RenderStates states) const override;

        void setTexture(sf::Texture& );
        virtual void setPosition(const sf::Vector2f& pos);

    protected:
        buiding_Type m_type;
        sf::Sprite m_sprite;

        //game params
        float m_hp;
        int m_cost;
    };
}