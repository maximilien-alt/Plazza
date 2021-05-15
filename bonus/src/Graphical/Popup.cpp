/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Popup
*/

#include "Popup.hpp"

Plazza::Popup::Popup(std::string str, float x, float y) : _text(100, x, y + 30, sf::Color::Green, str), pos(x, y), _clock()
{
    _rect.setSize(sf::Vector2f(1300, 300));
    _rect.setOutlineColor(sf::Color::Green);
    _rect.setOutlineThickness(10);
    _rect.setFillColor(sf::Color::Black);
    _rect.setPosition(pos);
}

Plazza::Popup::~Popup()
{
}

bool Plazza::Popup::is_clear(void)
{
    return _clear;
}

void Plazza::Popup::draw(sf::RenderWindow &window)
{
    static int i = 0;

    if (i++ == 0) {
        _clock.restart();
    }
    sf::Time elapsed = _clock.getElapsedTime();
    if (elapsed.asSeconds() < 3) {
        window.draw(_rect);
        _text.draw(window);
    } else
        _clear = true;
}