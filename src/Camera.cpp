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

#include "hko/Camera.h"
#include <iostream>

namespace hko{

    Camera::Camera(): m_zoom(1.f) {

    }

    void Camera::handleEvents(const sf::Event& event) {

        if(event.type == sf::Event::MouseMoved){

        }

        if(event.type == sf::Event::MouseWheelScrolled){
            if(event.mouseWheelScroll.delta > 0){
                m_zoom *= 0.5;
                m_view.zoom(0.5f);
            }
            else {
                m_zoom *= 2;
                m_view.zoom(2.f);
            }

        }

        if(event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::W){
            m_view.move(0.f, -10.f);
        }

        if(event.type == sf::Event::KeyPressed &&
           event.key.code == sf::Keyboard::A){
            m_view.move(-10.f, 0.f);
        }

        if(event.type == sf::Event::KeyPressed &&
           event.key.code == sf::Keyboard::S){
            m_view.move(0.f, 10.f);
        }

        if(event.type == sf::Event::KeyPressed &&
           event.key.code == sf::Keyboard::D){
            m_view.move(10.f, 0.f);
        }
    }


    void Camera::update(float dt) {

    }

    sf::View& Camera::getView() {
        return m_view;
    }

    sf::Vector2f Camera::mapPixelToCoords(const sf::Vector2f &pos) {
        return sf::Vector2f();
    }
}