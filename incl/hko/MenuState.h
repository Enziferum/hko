//
// Created by HP on 07.03.2021.
//

#pragma once

#include "IState.h"
#include "ResourceManager.h"

#include "hko/gui/Button.h"
#include "hko/gui/Gui.h"
#include "hko/Configuration.h"

namespace hko{
    class MenuState: public IState{
    public:
        using Ptr = std::shared_ptr<MenuState>;
    public:
        MenuState(IStateMachine& machine, Configuration& configuration);
        ~MenuState()override = default;

        void handleEvents(const sf::Event& event)override;
        void update(float dt) override;
        void render() override;

    private:
        void setup();
        void setup_main();
        void setup_settings();
    private:
        Configuration& m_configuration;
        ResourceManager<sf::Texture> m_textures;
        ResourceManager<sf::Font> m_fonts;

        bool m_show_settings;

        Gui m_gui;
        Gui m_settings_gui;


        Button::Ptr m_play;
        Button::Ptr m_exit;

        sf::RectangleShape border;
    };
}