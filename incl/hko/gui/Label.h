//
// Created by HP on 07.03.2021.
//

#pragma once

#include "GuiNode.h"

namespace hko{
    class Label: public GuiNode, sf::Transformable{
    public:
        using Ptr = std::shared_ptr<Label>;
    public:
        Label();
        virtual ~Label() override = default;

        static Ptr create();

        void setFont(sf::Font& font);
        void setText(const std::string& text, const sf::Color color = sf::Color::White);
        void setTextSize(const int& size);

        void setPosition(const sf::Vector2f &f) override;

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    protected:
        std::string m_text;
        int m_text_size;

        sf::Text m_sftext;
        sf::Font* m_font;
    };
}
