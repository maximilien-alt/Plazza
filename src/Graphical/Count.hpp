/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Count
*/

#ifndef Count_HPP_
#define Count_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Plazza {
    class Count {
        public:
            Count(float x, float y);
            void inc();
            void dec();
            void draw(sf::RenderWindow &);
            ~Count();
        private:
            sf::Sprite _plus, _minus;
            sf::Texture _texture;
            sf::Vector2f position;
            sf::Font _font;
            sf::Text _text;
            sf::IntRect _rect;
            int count;
    };
}

#endif /* !Count_HPP_ */
