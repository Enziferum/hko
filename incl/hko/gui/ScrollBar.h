//
// Created by HP on 07.03.2021.
//

#pragma once

#include "GuiNode.h"
#include "Label.h"

namespace hko{

    class ScrollBar: public GuiNode{
    public:
        enum class scrollType{
            horizontal, vertical
        };

        using Ptr = std::shared_ptr<ScrollBar>;
    public:
        ScrollBar();
        ~ScrollBar()override = default;

        void handleEvents(const sf::Event& event);
        void update(float dt) override;

        static Ptr create();

        void set_current(const float& value);
        const float& current_value()const;

        void between(const float& start, const float& end);
        void setPosition(const sf::Vector2f &f) override;
        bool intersects(const sf::Vector2f &mousePos) override;
    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        float m_start;
        float m_end;
        float m_current;
        float m_step;


        //for sample
        sf::RectangleShape m_scroll_bar;
        sf::CircleShape m_scroll_circle;
    };
}
