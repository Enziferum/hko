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

#pragma once

#include <vector>

#include "IState.h"
#include "INode.h"

#include "ResourceManager.h"
#include "Configuration.h"
#include "Camera.h"
#include "Map.h"
#include "Building.h"

#include "Ai.h"

#include "gui/Gui.h"
#include "gui/Label.h"



#include "ecs/Scene.h"

namespace hko{

    class StrategyState: public IState{
    public:
        using Ptr = std::shared_ptr<StrategyState>;
    public:
        StrategyState(IStateMachine& machine,
                      Configuration& configuration);
        ~StrategyState();

        void handleEvents(const sf::Event& event) override;
        void update(float dt) override;
        void render() override;

    private:
        void setup();
        void setupGame();
        void setupMainGui();

        void setupScene();

        //main building canvas
        void setup_build_gui();

        //build logic just now 08.03 - not working
        void before_build();
        void try_build(const sf::Vector2f& pos);

        void process_ai_decision(const AiDecision& decision);
    private:
        Configuration& m_configuration;
        ResourceManager<sf::Texture> m_textures;
        ResourceManager<sf::Font> m_fonts;

        //will all stuff here
        Scene m_scene;

        Map m_map;
        Camera m_camera;
        sf::View m_minimap;

        std::vector<Building::Ptr> m_buildings;

        Gui m_main_gui;
        Gui m_build_gui;

        //demo sheet
        sf::RectangleShape m_gui_background;

        //modes check
        bool m_open_building;
        bool m_build_mode;

        Label::Ptr coin_label;
        unsigned int m_coins = 400;

        IAi::Ptr m_ai;

        //todo outside
        struct : public sf::Drawable{
            std::vector<sf::CircleShape> cells;
            sf::Color grid_color = sf::Color(150, 250, 100,
                                             100);

            sf::Vector2f intersects_pos = sf::Vector2f();
            sf::Vector2f left;

            bool insersects(const sf::Vector2f& pos){
                if(cells.empty())
                    return false;

                for(int it = 0; it < cells.size(); ++it){
                    if(cells[it].getGlobalBounds().contains(pos)){
                        int row = it / 4;
                        int column = it - row * 4;

                        intersects_pos.x = left.x + 64 * row;
                        intersects_pos.y = left.y + 64 * column;

                        return true;
                    }
                }

                return false;
            }



            void setup_grid(const sf::Vector2f& left,
                            const int& cell_value){
                cells.clear();

                const int row_sz = 4;

                this->left = left;

                int idx = 0;
                for(int it = 0; it < cell_value / row_sz; ++it){
                    for(int ij = 0; ij < cell_value / row_sz; ++ij){
                        sf::CircleShape cell(32.f, 6);
                        cell.setPosition(left.x + it * 64, left.y+ ij * 64);
                        //cell.setPosition(left);
                        cell.setFillColor(grid_color);
                        cell.setOutlineColor(sf::Color::Black);
                        cell.setOutlineThickness(1.f);

                        cells.emplace_back(cell);
                    }
                }
            }

            virtual void draw(sf::RenderTarget& target,
                              sf::RenderStates states) const{
                for(const auto& it: cells)
                    target.draw(it);
            }

        }build_grid;
    };
}
