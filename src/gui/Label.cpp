//
// Created by HP on 07.03.2021.
//

#include "hko/gui/Label.h"
#include "hko/Utility.h"

namespace hko{
    Label::Label(): m_text("Label"),
        m_text_size(12) {

    }


    void Label::setText(const std::string& text, const sf::Color color) {
        m_text = text;
        m_sftext.setString(m_text);
        m_sftext.setFillColor(color);
        centerOrigin(m_sftext);
    }

    void Label::setTextSize(const int &size) {
        m_text_size = size;
        m_sftext.setCharacterSize(m_text_size);
    }

    void Label::setFont( sf::Font& font) {
        m_font = &font;
        m_sftext.setFont(*m_font);
    }

    void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(m_sftext, states);
    }

    void Label::setPosition(const sf::Vector2f& pos) {
        GuiNode::setPosition(pos);
        m_sftext.setPosition(pos);
        centerOrigin(m_sftext);
    }

    Label::Ptr Label::create() {
        return std::make_shared<Label>();
    }

}