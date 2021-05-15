/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Popup
*/

#ifndef POPUP_HPP_
#define POPUP_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Text.hpp"

namespace Plazza {
    class Popup {
        public:
            Popup(std::string str, float x, float y);
            ~Popup();
            bool is_clear(void);
            void draw(sf::RenderWindow &);
        private:
            sf::RectangleShape _rect;
            Text _text;
            sf::Vector2f pos;
            sf::Clock _clock;
            bool _clear = false;
    };
}

#endif /* !POPUP_HPP_ */