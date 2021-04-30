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

void Plazza::KitchenManager::addKitchen(int fd, Kitchen &kitchen, int maxPizzas)
{
    kitchen.setFd(fd);
    _kitchens.insert(std::make_pair(std::make_shared<Plazza::Kitchen>(kitchen), maxPizzas));
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
        dprintf(n.first->getFd(), "dump\n");
        index += 1;
    }
}

size_t Plazza::KitchenManager::size() const
{
    return _kitchens.size();
}

std::pair<std::shared_ptr<Plazza::Kitchen>, int> Plazza::KitchenManager::at(int pos)
{
    int index = 0;
    std::pair<std::shared_ptr<Plazza::Kitchen>, int> pair; 

    for (auto &n: _kitchens)
        if (index++ == pos) {
            pair = n;
            break;
        }
    return pair;
}

void Plazza::KitchenManager::deleteKitchenFromFd(int fd)
{
    for (std::unordered_map<std::shared_ptr<Plazza::Kitchen>, int>::iterator it = _kitchens.begin(); it != _kitchens.end(); ++it)
        if ((*it).first->getFd() == fd) {
            _kitchens.erase(it);
            return;
        }
}

void Plazza::KitchenManager::updateMaxPizzasFromFd(int fd, int state)
{
    for (auto &n: _kitchens)
        if (n.first->getFd() == fd) {
            n.second += state;
            return;
        }
}