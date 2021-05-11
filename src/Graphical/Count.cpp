/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Count
*/

#include "Count.hpp"

Plazza::Count::Count(float x, float y) : position(x, y), _rect(0, 0, 100, 200), _plus(), _minus()
{
    _texture.loadFromFile("ressources/plus-moins.png");
    count = 0;
    _plus.setTexture(_texture);
    _minus.setTexture(_texture);
    _font.loadFromFile("ressources/Italianno-Regular.ttf");
}

Plazza::Count::~Count()
{
}

void Plazza::Count::inc()
{
    count += 1;
}

void Plazza::Count::dec()
{
    count -= 1;
}

void Plazza::Count::draw(sf::RenderWindow &window)
{
    sf::IntRect sec(100, 0, 100, 200);
    _plus.setPosition(position);
    _plus.setTextureRect(_rect);
    _minus.setTextureRect(sec);
    _minus.setPosition(position.x + 200, position.y);
    _text.setCharacterSize(160);
    _text.setPosition(position.x + 110, position.y - 15);
    _text.setFont(_font);
    _text.setString(std::to_string(count));
    _plus.setScale(sf::Vector2f{0.625,0.625});
    _minus.setScale(sf::Vector2f{0.625,0.625});
    _text.setScale(sf::Vector2f{0.625,0.625});

    window.draw(_plus);
    window.draw(_minus);
    window.draw(_text);
}