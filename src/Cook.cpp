/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#include "Cook.hpp"

std::shared_ptr<Plazza::IMutex> mutex = std::make_shared<Plazza::AMutex>();

Plazza::Cook::Cook(): _isCooking(0)
{
}

Plazza::Cook::~Cook()
{
}

bool Plazza::Cook::isCooking() const
{
    return _isCooking;
}

void Plazza::Cook::cook(Plazza::Pizza toCook)
{
    _isCooking = true;
    std::cout << "Cooking this : " << toCook;
}