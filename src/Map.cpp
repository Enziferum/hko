//
// Created by HP on 07.03.2021.
//
#include <fstream>
#include <string>
#include <map>
#include "hko/Map.h"

namespace hko{
    enum class MapTile{
        sand, grass
    };

    std::map<char, MapTile> tile_dict = {
            {'0',MapTile::sand},
            {'1',MapTile::grass},
    };


    Map::Map() {

    }

    bool Map::loadMap(const std::string& map_path) {
        std::fstream map_file(map_path);
        int w = 0;
        int h = 0;

        if(!map_file.is_open())
            return false;

        m_textures.loadFile("res/map_tiles/sand.png", "sand");
        m_textures.loadFile("res/map_tiles/tile_grass.png", "grass");
        sf::Sprite sandSprite;
        sf::Sprite grassSprite;

        sandSprite.setTexture(m_textures.get("sand"));
        grassSprite.setTexture(m_textures.get("grass"));

        sf::Vector2f scale_factor(800.f / (8 * 64),
                                  600.f / (8 * 64));

        const sf::Vector2f tile_sz(64 * scale_factor.x,
                    64 * scale_factor.y);
        std::string cur_line;
        while (std::getline(map_file, cur_line)){
            for(auto& ch: cur_line){
                Tile curTile;
                curTile.m_w = w;
                curTile.m_h = h;

                curTile.m_pos = sf::Vector2f(w * tile_sz.x,
                                             h * tile_sz.y);

                MapTile tile_type = tile_dict[ch];
                if(tile_type == MapTile::sand)
                    curTile.m_sprite = sandSprite;
                if(tile_type == MapTile::grass)
                    curTile.m_sprite = grassSprite;

                ++h;

                curTile.m_sprite.setScale(scale_factor);
                curTile.m_sprite.setPosition(curTile.m_pos);
                m_tiles.push_back(curTile);
            }

            h = 0;
            ++w;
        }

        map_file.close();
        return true;
    }

    void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        for(const auto& it: m_tiles)
            target.draw(it);
    }

    void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform = getTransform();
        target.draw(m_sprite, states);
    }
}