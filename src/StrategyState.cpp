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

#include "hko/StrategyState.h"
#include "hko/States.h"
#include "hko/MainBuilding.h"

#include "hko/gui/Button.h"
#include "hko/gui/Label.h"

namespace hko{
    StrategyState::StrategyState(IStateMachine& machine,
                                 Configuration& configuration)
        :IState(machine),
        m_configuration(configuration),
        m_open_building(false),
        m_build_mode(false) {

        setup();
    }

    StrategyState::~StrategyState() {
    }

    void StrategyState::setup() {

        //todo move to configuration file
        m_textures.loadFile("res/builds/castle_4.png", "castle");
        m_textures.loadFile("res/builds/castle_barracks.png",
                            "castle_barracks");

        m_textures.loadFile("res/builds/Castle_Archery.png",
                            "castle_archery");
        m_fonts.loadFile("res/gui/fonts/arcade.ttf", "gui_font");


        if(!m_map.loadMap("res/maps/1.map")){
            //todo log about error
            return;
        }


        setupGame();
        setup_build_gui();
        setupMainGui();
    }

    void StrategyState::setupGame() {
        const float offset = 80;


        MainBuilding::Ptr castleMain = std::make_shared<MainBuilding>();
        MainBuilding::Ptr golbinMain = std::make_shared<MainBuilding>();

        auto size = m_window.getSize();

        castleMain->setTexture(m_textures.get("castle"));
        golbinMain->setTexture(m_textures.get("castle"));

        castleMain->setPosition(sf::Vector2f(offset, size.y / 2 ));
        golbinMain->setPosition(sf::Vector2f(1200,
                                            800));

        castleMain -> setScale(sf::Vector2f());
        golbinMain -> setScale(sf::Vector2f());

        m_buildings.push_back(castleMain);
        m_buildings.push_back(golbinMain);

        m_ai = std::make_shared<EasyAi>();
    }

    void StrategyState::handleEvents(const sf::Event& event) {
        if(m_open_building)
            m_build_gui.handleEvents(event);

        if(event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left){
            //todo convert to world coords
                sf::Vector2f mousePos(event.mouseButton.x,
                                      event.mouseButton.y);

                mousePos = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x,
                                                       event.mouseButton.y),
                                          m_camera.getView());

                //todo check main building is player
                if(!m_open_building){
                    for(auto& it: m_buildings){
                        if(it->contains(mousePos)
                           && it->get_type() == buiding_Type::Main)
                                m_open_building = true;
                    }
                }

                //todo build mode
                if(m_build_mode)
                    try_build(mousePos);
        }

        if(event.type == sf::Event::KeyPressed
           && event.key.code == sf::Keyboard::Escape){
            if(m_open_building)
                m_open_building = false;
            if(m_build_mode)
                m_build_mode = false;
        }

        if(event.type == sf::Event::KeyPressed){
            auto& m_keys = m_configuration.m_keymap;
            if(event.key.code == m_keys[keyBindings::pause]){
                //todo push pause state
            }

            if(event.key.code == m_keys[keyBindings::screenshot]){
                //todo take screenshot
            }

            if(event.key.code == m_keys[keyBindings::menu]){
                m_machine.pushState(States::Menu);
            }
        }

        m_camera.handleEvents(event);
        m_main_gui.handleEvents(event);
    }

    void StrategyState::update(float dt) {
        //noting doing just now
        m_ai->update(dt);
        process_ai_decision(m_ai -> get_decision());


        m_camera.update(dt);
        if(m_open_building)
            m_build_gui.update(dt);


        coin_label -> setText("Coins " + std::to_string(m_coins));
        m_main_gui.update(dt);
    }

    void StrategyState::render() {
        sf::View& cameraView = m_camera.getView();
        auto view = m_window.getView();

        m_window.setView(cameraView);
        m_window.draw(m_map);

        m_window.setView(view);
        if(m_build_mode)
            m_window.draw(build_grid);

        m_window.setView(cameraView);
        for(const auto& it:m_buildings)
            m_window.draw(*it);

        m_window.setView(view);
        //draw building stuff
        if(m_open_building) {
            m_window.draw(m_gui_background);
            m_window.draw(m_build_gui);
        }

        m_window.draw(m_main_gui);
    }

    void StrategyState::setup_build_gui() {
        // demo background for building menu //

        m_gui_background.setPosition(100, 100);
        m_gui_background.setSize(sf::Vector2f(600, 400));
        m_gui_background.setFillColor(sf::Color(225, 228, 232,
                                                255));
        m_gui_background.setOutlineColor(sf::Color::Black);
        m_gui_background.setOutlineThickness(2.f);


        // demo background for building menu //

        //todo as canvas in future


        sf::Vector2f left(0.f, 0.f);
        const sf::Vector2f barrack_btn_pos(175, 150);
        const sf::Vector2f label_btn_pos(175, 220);
        const sf::Vector2f archery_btn_pos(300, 150);
        const sf::Vector2f label_archery_pos(300, 220);

        auto barrack_btn = Button::create();
        barrack_btn->setTexture(m_textures.get("castle_barracks"));
        barrack_btn->setOnClick([this](){
            // check coins
            m_open_building = false;
            before_build();
        });

        barrack_btn->setPosition(barrack_btn_pos);

        auto barrack_label = Label::create();
        barrack_label->setFont(m_fonts.get("gui_font"));
        barrack_label->setPosition(label_btn_pos);
        barrack_label->setTextSize(18);
        barrack_label->setText("100 Coins", sf::Color::Black);

        auto archery_btn = Button::create();
        archery_btn->setTexture(m_textures.get("castle_archery"));
        archery_btn->setOnClick([this](){
            // check coins
            m_open_building = false;
            before_build();
        });

        archery_btn->setPosition(archery_btn_pos);

        auto archery_label = Label::create();
        archery_label->setFont(m_fonts.get("gui_font"));

        archery_label->setPosition(label_archery_pos);
        archery_label->setTextSize(18);
        archery_label->setText("150 Coins", sf::Color::Black);

        m_build_gui.pack(barrack_btn);
        m_build_gui.pack(barrack_label);
        m_build_gui.pack(archery_btn);
        m_build_gui.pack(archery_label);
    }

    void StrategyState::before_build() {
        m_build_mode = true;

        //todo find start point and available cells
        const sf::Vector2f grid_left(100.f, 100.f);
        const int cells_in_grid = 16;


        build_grid.setup_grid(grid_left, 16);
    }

    void StrategyState::setupMainGui() {
        std::string coins = "Coins ";
        coins += std::to_string(m_coins);

        coin_label = Label::create();
        coin_label->setPosition(sf::Vector2f(100.f, 50.f));
        coin_label->setFont(m_fonts.get("gui_font"));
        coin_label->setText(coins);
        coin_label->setTextSize(24);

        m_main_gui.pack(coin_label);
    }

    void StrategyState::try_build(const sf::Vector2f& pos) {
        if(!m_build_mode)
            return;

        if(build_grid.insersects(pos)){
            auto pos = build_grid.intersects_pos;
            if(pos == sf::Vector2f())
                return;

            const sf::Vector2f building_pos;

            Building::Ptr building = nullptr;
            //building -> setPosition(building_pos);
            //building ->setTexture();

            //todo
            m_coins -= 100;

            //m_buildings.emplace_back(building);


            build_grid.intersects_pos = sf::Vector2f();
        }
    }



    void StrategyState::process_ai_decision(const AiDecision &decision) {

    }

}