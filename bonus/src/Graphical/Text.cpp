/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Text
*/

#include "Text.hpp"

Plazza::Text::Text(int size, float x, float y, sf::Color color, std::string string)
{
    _font.loadFromFile("ressources/Italianno-Regular.ttf");
    _text.setFont(_font);
    _text.setCharacterSize(size);
    _text.setFillColor(color);
    _text.setPosition(x, y);
    _text.setString(string);
}

Plazza::Text::~Text()
{
}


void Plazza::Text::draw(sf::RenderWindow &window)
{
    window.draw(_text);
}