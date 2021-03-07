//
// Created by support on 06.03.2021.
//

#pragma once

#include <memory>
#include "IStateMachine.h"

namespace hko{
    class IState{
    public:
        using Ptr = std::shared_ptr<IState>;
    public:
        IState(IStateMachine& machine);
        virtual ~IState();

        virtual void handleEvents(const sf::Event& event) = 0;
        virtual void update(float dt) = 0;
        virtual void render() = 0;

    protected:
        IStateMachine& m_machine;
        sf::RenderWindow& m_window;
    };
}
