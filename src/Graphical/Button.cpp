/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Button
*/

#include "Button.hpp"

Plazza::Button::Button(float x, float y):_rect(0, 0, 100, 200),_sprite()
{
    _texture.loadFromFile("ressources/checkbox.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(x, y);
    posx = x;
    posy = y;

}

Plazza::Button::~Button()
{
}

void Plazza::Button::check(void)
{
    _state = !_state;
}

void Plazza::Button::draw(sf::RenderWindow &win)
{
    if (!_state)
        _rect.left = 0;
    else
        _rect.left = 100;
    _sprite.setTextureRect(_rect);
    _sprite.setScale(sf::Vector2f{0.625,0.625});
    win.draw(_sprite);
}

int Plazza::Button::getX(void) const
{
    return (posx);
}

int Plazza::Button::getY(void) const
{
    return (posy);
}
