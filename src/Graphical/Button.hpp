/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Plazza {
    class Button {
        public:
            Button(float x, float y);
            ~Button();
            void check(void);
            void draw(sf::RenderWindow &win);
            int getX(void) const;
            int getY(void) const;
        private:
            bool _state = false;
            sf::Texture _texture;
            sf::IntRect _rect;
            sf::Sprite _sprite;
            float posx, posy;
    };
};

#endif /* !BUTTON_HPP_ */