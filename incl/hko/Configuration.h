//
// Created by HP on 07.03.2021.
//

#pragma once
#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>

namespace hko{
    enum keyBindings{
        pause, screenshot, menu
    };

    struct Configuration{
        static Configuration create();

        bool save(const char* path);
        bool read(const char* path);

        float m_sounds_volume;
        float m_music_volume;
        std::unordered_map<keyBindings, sf::Keyboard::Key> m_keymap;
    };
}
