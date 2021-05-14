/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-leo.sarochar
** File description:
** Clock
*/

#include "Clock.hpp"

Plazza::Clock::Clock()
{
}

Plazza::Clock::~Clock()
{
}

void Plazza::Clock::reset()
{
    _clock = _Clock::now();
}

float Plazza::Clock::getElapsedTime()
{
    auto now = _Clock::now();
    std::chrono::duration<double, std::micro> elapsedTime = now - _clock;

    return (elapsedTime.count() / 1000000);
}