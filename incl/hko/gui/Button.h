//
// Created by HP on 07.03.2021.
//

#pragma once

#include "GuiNode.h"
#include "Label.h"

namespace hko{

    class Button: public GuiNode, sf::Transformable{
    public:
        using Ptr = std::shared_ptr<Button>;
    public:
        Button();
        ~Button();


        static Button::Ptr create();

        void setOnClick(const std::function<void()>& func);
        void setTexture(sf::Texture& texture);
        void setLabel(Label::Ptr label);
        void setPosition(const sf::Vector2f &f) override;

        bool intersects(const sf::Vector2f& mousePos) override;
        virtual void update(float dt);

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        std::function<void()> m_callback;
        Label::Ptr m_label;
        sf::Sprite m_sprite;
    };

}
