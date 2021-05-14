/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Plazza {
    class Text {
        public:
            Text(int size, float x, float y, sf::Color color, std::string string);
            ~Text();
            void draw(sf::RenderWindow &window);
        private:
            sf::Font _font;
            sf::Text _text;
    };
};

#endif /* !TEXT_HPP_ */
