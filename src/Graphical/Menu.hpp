/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Count.hpp"

namespace Plazza {
    class Menu {
        public:
            Menu();
            ~Menu();
            void loop();

        protected:
        private:
            sf::RenderWindow _window;
            sf::Event _event;
            std::vector<Button> tabBtn;
    };
};

#endif /* !MENU_HPP_ */