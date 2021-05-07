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

void Plazza::KitchenManager::addKitchen(int fd, int maxPizzas)
{
    _kitchens.insert(std::make_pair(fd, maxPizzas));
}

Plazza::Kitchen Plazza::KitchenManager::giveMeKitchen(int time, int cooks, int cooldown, int id)
{
    return (Plazza::Kitchen(time, cooks, cooldown, id));
}

void Plazza::KitchenManager::dump()
{
    int index = 1;
    int ret = 0;
    int protocol = 1;

    for (auto &n: _kitchens) {
        write(n.first, &protocol, 4);
        write(n.first, "dump\n", 5);
        read(n.first, &ret, 4);
        index += 1;
    }
    if (_kitchens.size() == 0)
        std::cout << "No kitchens were found... Try to take an order before do that!" << std::endl;
}

void Plazza::KitchenManager::endAll()
{
    int protocol = 1;

    for (auto &n: _kitchens) {
        write(n.first, &protocol, 4);
        write(n.first, "shutdown\n", 9);
        close(n.first);
    }
}

void Plazza::KitchenManager::endOne(int fd)
{
    int protocol = 1;

    write(fd, &protocol, 4);
    write(fd, "shutdown\n", 9);
}

size_t Plazza::KitchenManager::size() const
{
    return _kitchens.size();
}

std::pair<const int, int> &Plazza::KitchenManager::at(int pos)
{
    int index = 0;

    for (auto &n: _kitchens)
        if (index++ == pos)
            return n;
}

void Plazza::KitchenManager::deleteKitchenFromFd(int fd)
{
    for (std::unordered_map<int, int>::iterator it = _kitchens.begin(); it != _kitchens.end(); ++it)
        if ((*it).first == fd) {
            _kitchens.erase(it);
            return;
        }
}

void Plazza::KitchenManager::updateMaxPizzasFromFd(int fd, int state)
{
    std::unordered_map<int, int>::iterator it = _kitchens.find(fd);
    if (it != _kitchens.end())
        _kitchens[fd] += state;
}