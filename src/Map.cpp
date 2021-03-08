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

        auto bounds = grassSprite.getLocalBounds();

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