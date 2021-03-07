//
// Created by HP on 07.03.2021.
//

#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "INode.h"
#include "ResourceManager.h"


namespace hko{
    struct Tile: public sf::Drawable, sf::Transformable{
        int m_h;
        int m_w;

        sf::Vector2f m_pos;
        sf::Sprite m_sprite;
    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };

    class Map: public sf::Drawable{
    public:
        Map();
        ~Map() = default;

        bool loadMap(const std::string& map);
        virtual void draw(sf::RenderTarget& target,
                          sf::RenderStates states) const;


    private:
        std::vector<Tile> m_tiles;
        ResourceManager<sf::Texture> m_textures;
    };
}