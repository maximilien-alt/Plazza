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
    kitchen.setFd(fd);
    _kitchens[fd] = kitchen;
}

Plazza::Kitchen Plazza::KitchenManager::giveMeKitchen(int time, int cooks, int cooldown)
{
    return (Plazza::Kitchen(time, cooks, cooldown));
}

void Plazza::KitchenManager::dump()
{
    int index = 1;

    for (auto &n: _kitchens) {
        std::cout << "  Kitchen number " << index << ":" << std::endl;
        dprintf(n.first, "dump\n");
        index += 1;
    }
}

size_t Plazza::KitchenManager::size() const
{
    return _kitchens.size();
}

Plazza::Kitchen &Plazza::KitchenManager::at(int pos)
{
    int index = 0;

    for (auto &n: _kitchens) {
        if (index == pos)
            return n.second;
        index += 1;
    }
    throw Error("[KitchenManager]: No kitchen found with this index! ('" + std::to_string(pos) + "')");
}