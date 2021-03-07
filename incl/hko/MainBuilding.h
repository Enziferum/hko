//
// Created by HP on 07.03.2021.
//

#pragma once

#include "Building.h"

namespace hko{
    class MainBuilding: public Building{
    public:
        using Ptr = std::shared_ptr<MainBuilding>;
    public:
        MainBuilding();
        ~MainBuilding()override = default;


        void setScale(const sf::Vector2f& scale_factor);
    private:

    };
}