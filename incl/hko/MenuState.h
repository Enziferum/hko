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