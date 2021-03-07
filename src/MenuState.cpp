//
// Created by HP on 07.03.2021.
//

#include <iostream>

#include "hko/States.h"
#include "hko/MenuState.h"
#include "hko/gui/Label.h"
#include "hko/gui/ScrollBar.h"

namespace hko{

    MenuState::MenuState(IStateMachine& machine, Configuration& configuration):
        IState(machine),
        m_configuration(configuration),
        m_show_settings(false)
        {
        setup();
    }

    void MenuState::setup() {
        m_textures.loadFile("res/gui/buttons/btn_normal.png", "default_btn");
        m_fonts.loadFile("res/gui/fonts/arcade.ttf", "title_font");

        auto size = m_window.getSize();

        border.setFillColor(sf::Color::Transparent);
        border.setPosition(100, 100);
        border.setSize(sf::Vector2f(size.x - 2 * 100,
                                    size.y - 2 * 100));
        border.setOutlineColor(sf::Color::Yellow);
        border.setOutlineThickness(5);

        setup_main();
        setup_settings();
    }

    void MenuState::setup_main() {
        auto size = m_window.getSize();

        Label::Ptr title = Label::create();
        title->setText("Hko");
        title->setTextSize(30);
        title->setFont(m_fonts.get("title_font"));
        title->setPosition(sf::Vector2f(400, 120));

        Label::Ptr play_label = Label::create();
        play_label -> setText("Play");
        play_label -> setTextSize(18);
        play_label -> setFont(m_fonts.get("title_font"));

        m_play = Button::create();
        m_play -> setTexture(m_textures.get("default_btn"));
        m_play -> setPosition(sf::Vector2f(400, 200));
        m_play -> setOnClick([this](){
            m_machine.pushState(States::Strategy);
        });
        m_play -> setLabel(play_label);

        Label::Ptr settings_label = Label::create();
        settings_label -> setText("Settings");
        settings_label -> setTextSize(18);
        settings_label -> setFont(m_fonts.get("title_font"));

        Button::Ptr m_settings = Button::create();
        m_settings -> setTexture(m_textures.get("default_btn"));
        m_settings -> setPosition(sf::Vector2f(400, 300));
        m_settings -> setOnClick([this](){
            m_show_settings = true;
        });
        m_settings -> setLabel(settings_label);

        Label::Ptr exit_label = Label::create();
        exit_label -> setText("Exit");
        exit_label -> setTextSize(18);
        exit_label -> setFont(m_fonts.get("title_font"));

        m_exit = Button::create();
        m_exit -> setTexture(m_textures.get("default_btn"));
        m_exit -> setPosition(sf::Vector2f(400, 400));
        m_exit -> setOnClick([this](){
            //todo cleanps;
            m_window.close();
        });
        m_exit -> setLabel(exit_label);

        m_gui.pack(title);
        m_gui.pack(m_play);
        m_gui.pack(m_settings);
        m_gui.pack(m_exit);
    }

    void MenuState::setup_settings() {
        //todo add step
        auto sound_scroll = ScrollBar::create();
        sound_scroll -> setPosition(sf::Vector2f());
        sound_scroll -> between(0.f, 100.f);
        sound_scroll -> set_current(m_configuration.m_sounds_volume);

        auto music_scroll = ScrollBar::create();
        music_scroll -> between(0.f, 100.f);
        music_scroll -> setPosition(sf::Vector2f());
        music_scroll -> set_current(m_configuration.m_music_volume);

        auto back_button_label = Label::create();
        auto back_button = Button::create();

        m_settings_gui.pack(sound_scroll);
        m_settings_gui.pack(music_scroll);
        m_settings_gui.pack(back_button);
    }

    void MenuState::handleEvents(const sf::Event& event) {
        if(event.type == sf::Event::Resized){
            auto size = sf::Vector2u(event.size.width, event.size.height);
            m_gui.resize(size);
            border.setPosition(100, 100);
            border.setSize(sf::Vector2f(size.x - 200,
                                        size.y - 200));
        }

        if(m_show_settings)
            m_settings_gui.handleEvents(event);
        else
            m_gui.handleEvents(event);
    }

    void MenuState::update(float dt) {
        if(m_show_settings)
            m_settings_gui.update(dt);
        else
            m_gui.update(dt);
    }

    void MenuState::render() {
        m_window.draw(border);
        if(m_show_settings)
            m_window.draw(m_settings_gui);
        else
            m_window.draw(m_gui);
    }



}