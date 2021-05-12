/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Menu
*/

#include "Menu.hpp"
#include <iostream>

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
    Count counter(790, 900);
    for (int a = 0; a < 5; a++)
    {
        Button button(830, 650 - 75 * a);
        tabBtn.push_back(button);
    }
    // Button button(1920 / 2 - 50, 1080 / 2 - 0);
    // Button button1(1920 / 2 - 50, 1080 / 2 - 75);
    // Button button2(1920 / 2 - 50, 1080 / 2 - 150);
    // Button button3(1920 / 2 - 50, 1080 / 2 - 225);
    Button button4(1920 / 2 - 50, 1080 / 2 - 300);

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
            if (_event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mouse = sf::Mouse::getPosition();
                // std::cout << mouse.x - 70 << "|" << mouse.y - 65 << std::endl << std::endl;

                for (auto &i : tabBtn) {
                    // std::cout << i.getX() << "|" << i.getY() << "-" << i.getX() + 62.5 << "|" << i.getY() + 125 << std::endl;
                    if (mouse.x - 70 > i.getX() && mouse.x - 70 < i.getX() + 62.5 && mouse.y - 65 > i.getY() && mouse.y - 65 < i.getY() + 125) {
                        for (auto &b : tabBtn) {
                            if (b.getstate() == true)
                                b.check();
                        }
                        i.check();
                    }
                    // if (mouse.x)
                }
                if (mouse.x - 70 > 802 && mouse.x - 70 < 848 && mouse.y - 65 > 940 && mouse.y - 65 < 992)
                    counter.inc();
                if (mouse.x - 70 > 1001 && mouse.x - 70 < 1051 && mouse.y - 65 > 937 && mouse.y - 65 < 987)
                    counter.dec();
                // button4.check();
            }
        }
        for (auto &i : tabBtn)
            i.draw(_window);
        // button4.draw(_window);
        counter.draw(_window);
        _window.display();
    }
}

int main(void)
{
    Plazza::Menu men;
    men.loop();
}