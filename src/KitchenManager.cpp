/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** KitchenManager
*/

#include "KitchenManager.hpp"

Plazza::KitchenManager::KitchenManager()
{
}

Plazza::KitchenManager::~KitchenManager()
{
}

bool Plazza::KitchenManager::empty() const
{
    return _kitchens.empty();
}

void Plazza::KitchenManager::addKitchen(int fd, Kitchen &kitchen)
{
    _kitchens[fd] = kitchen;
}

Plazza::Kitchen Plazza::KitchenManager::giveMeKitchen(int time, int cooks, int cooldown)
{
    return (Plazza::Kitchen(time, cooks, cooldown));
}

void Plazza::KitchenManager::dump()
{
    for (size_t index = 0; index < _kitchens.size(); index += 1) {
        std::cout << "  Kitchen number " << index + 1 << ":" << std::endl;
        _kitchens[index].dump();
    }
}

size_t Plazza::KitchenManager::size() const
{
    return _kitchens.size();
}

Plazza::Kitchen &Plazza::KitchenManager::at(int pos)
{
    return _kitchens[pos];
}