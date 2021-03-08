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

#include "framework/gui/Label.h"
#include "framework/Utility.h"

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