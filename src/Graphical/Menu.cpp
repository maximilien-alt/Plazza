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
    Text xxl(50, 940, 680,sf::Color::Red, "XXL");
    Text xl(50, 940, 680 - 75,sf::Color::Red, "XL");
    Text l(50, 940, 680 - 150,sf::Color::Red, "L");
    Text m(50, 940, 680 - 225,sf::Color::Red, "M");
    Text s(50, 940, 680 - 300,sf::Color::Red, "S");
    
    Text click(50, 885, 880,sf::Color::Red, "Click to");
    Text order(50, 885, 920,sf::Color::Red, " Order");

    Count counter(810, 780);
    for (int a = 0; a < 5; a++)
    {
        Button button(850, 650 - 75 * a);
        tabBtnSize.push_back(button);
    }
    Button regina(531 - 30, 320);
    Button margarita(531 - 30, 720);
    Button americana(1330 - 30, 320);
    Button fantasia(1330 - 30, 720);

    // Button regina(531, 370);

    Button button4(1920 / 2 - 30, 1080 / 2 - 300);

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
                std::cout << mouse.x - 70 << "|" << mouse.y - 65 << std::endl
                          << std::endl;

                for (auto &i : tabBtnSize)
                {
                    // std::cout << i.getX() << "|" << i.getY() << "-" << i.getX() + 62.5 << "|" << i.getY() + 125 << std::endl;
                    if (mouse.x - 70 > i.getX() + 10 && mouse.x - 70 < i.getX() + 62.5 - 10 && mouse.y - 65 > i.getY() + 10 && mouse.y - 65 < i.getY() + 125 - 10)
                    {
                        for (auto &b : tabBtnSize)
                        {
                            if (b.getstate() == true)
                                b.check();
                        }
                        i.check();
                    }
                    // if (mouse.x)
                }
                if (mouse.x - 70 > 820 && mouse.x - 70 < 871 && mouse.y - 65 > 820 && mouse.y - 65 < 870)
                    counter.inc();
                if (mouse.x - 70 > 1022 && mouse.x - 70 < 1064 && mouse.y - 65 > 820 && mouse.y - 65 < 869)
                    counter.dec();
                // button4.check();
            }
        }
        for (auto &i : tabBtnSize)
            i.draw(_window);
        // button4.draw(_window);
        counter.draw(_window);
        regina.draw(_window);
        margarita.draw(_window);
        americana.draw(_window);
        fantasia.draw(_window);
        xxl.draw(_window);
        xl.draw(_window);
        l.draw(_window);
        m.draw(_window);
        s.draw(_window);
        click.draw(_window);
        order.draw(_window);
        _window.display();
    }
}

int main(void)
{
    Plazza::Menu men;
    men.loop();
}