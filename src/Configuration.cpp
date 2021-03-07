//
// Created by HP on 07.03.2021.
//

#include "hko/Configuration.h"

namespace hko{

    Configuration Configuration::create() {
        Configuration configuration = Configuration();

        configuration.m_sounds_volume = 0;
        configuration.m_music_volume = 0;
        configuration.m_keymap[hko::keyBindings::menu] = sf::Keyboard::M;

        return configuration;
    }

    bool Configuration::save(const char *path) {

        return true;
    }

    bool Configuration::read(const char *path) {

        return true;
    }
}