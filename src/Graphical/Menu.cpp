/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Menu
*/

#include "Menu.hpp"

Plazza::Menu::Menu()
{
    _window.create(sf::VideoMode(1920, 1080), "My _window");
}

Plazza::Menu::~Menu()
{
    _window.close();
}

void Plazza::Menu::loop()
{
    Button button(100, 100);
    while (_window.isOpen())
    {
        _window.clear(sf::Color::Black);
        sf::Sprite background;
        sf::Texture backgroundTexture;

        backgroundTexture.loadFromFile("ressources/menu.png", sf::IntRect(0, 0, 1920, 1080));
        background.setTexture(backgroundTexture);
        _window.draw(background);

        while (_window.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed)
                _window.close();
            if (_event.type == sf::Event::KeyPressed)
                button.check();
        }
        button.draw(_window);
        _window.display();
    }
}

int main(void)
{
    Plazza::Menu men;
    men.loop();
}