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
    std::string strorder;
    Text xxl(50, 940, 680,sf::Color::Red, "XXL");
    Text xl(50, 940, 680 - 75,sf::Color::Red, "XL");
    Text l(50, 940, 680 - 150,sf::Color::Red, "L");
    Text m(50, 940, 680 - 225,sf::Color::Red, "M");
    Text s(50, 940, 680 - 300,sf::Color::Red, "S");
    Text click(50, 885, 880,sf::Color::Red, "Click to");
    Text order(50, 885, 920,sf::Color::Red, " Order");
    Popup popup("Pizza ready", 200, 200);
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

                for (auto &i : tabBtnSize)
                {
                    if (mouse.x - 70 > i.getX() + 10 && mouse.x - 70 < i.getX() + 62.5 - 10 && mouse.y - 65 > i.getY() + 10 && mouse.y - 65 < i.getY() + 125 - 10)
                    {
                        for (auto &b : tabBtnSize)
                        {
                            if (b.getstate() == true)
                                b.check();
                        }
                        i.check();
                    }
                }
                if (mouse.x - 70 > 820 && mouse.x - 70 < 871 && mouse.y - 65 > 820 && mouse.y - 65 < 870)
                    counter.inc();
                if (mouse.x - 70 > 1022 && mouse.x - 70 < 1064 && mouse.y - 65 > 820 && mouse.y - 65 < 869)
                    counter.dec();
                if (mouse.x - 70 > regina.getX() + 10 && mouse.x - 70 < regina.getX() + 62.5 - 10 && mouse.y - 65 > regina.getY() + 10 && mouse.y - 65 < regina.getY() + 125 - 10) {
                    margarita.setState(false);
                    americana.setState(false);
                    fantasia.setState(false);
                    regina.check();
                }
                if (mouse.x - 70 > margarita.getX() + 10 && mouse.x - 70 < margarita.getX() + 62.5 - 10 && mouse.y - 65 > margarita.getY() + 10 && mouse.y - 65 < margarita.getY() + 125 - 10) {
                    regina.setState(false);
                    americana.setState(false);
                    fantasia.setState(false);
                    margarita.check();
                }
                if (mouse.x - 70 > americana.getX() + 10 && mouse.x - 70 < americana.getX() + 62.5 - 10 && mouse.y - 65 > americana.getY() + 10 && mouse.y - 65 < americana.getY() + 125 - 10) {
                    margarita.setState(false);
                    regina.setState(false);
                    fantasia.setState(false);
                    americana.check();
                }
                if (mouse.x - 70 > fantasia.getX() + 10 && mouse.x - 70 < fantasia.getX() + 62.5 - 10 && mouse.y - 65 > fantasia.getY() + 10 && mouse.y - 65 < fantasia.getY() + 125 - 10) {
                    margarita.setState(false);
                    americana.setState(false);
                    regina.setState(false);
                    fantasia.check();
                }

                if (mouse.x - 70 > 882 && mouse.x - 70 < 1017 && mouse.y - 65 > 892 && mouse.y - 65 < 979) {
                    if (margarita.getstate() == true)
                        strorder = "margarita ";
                    else if (americana.getstate() == true)
                        strorder = "americana ";
                    else if (regina.getstate() == true)
                        strorder = "regina ";
                    else if (fantasia.getstate() == true)
                        strorder = "fantasia ";
                    else
                        strorder = "";
                    if (strorder != "") {
                        if (tabBtnSize.at(0).getstate() == true)
                            strorder.append("XXL ");
                        else if (tabBtnSize.at(1).getstate() == true)
                            strorder.append("XL ");
                        else if (tabBtnSize.at(2).getstate() == true)
                            strorder.append("L ");
                        else if (tabBtnSize.at(3).getstate() == true)
                            strorder.append("M ");
                        else if (tabBtnSize.at(4).getstate() == true)
                            strorder.append("S ");
                        else 
                            strorder = "";
                    }
                    if (strorder != "")
                        strorder.append(std::to_string(counter.getNb()));
                    std::cout << strorder << std::endl;
                }
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
        popup.draw(_window);
        _window.display();
    }
}

// int main(void)
// {
//     Plazza::Menu men;
//     men.loop();
// }