/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Plazza::Kitchen::Kitchen(const int &time, const int &cooks, const int &cooldown): _cooksNumber(cooks), _IngredientsCoolDown(cooldown), _timeMultiplier(time), _fd(0), _queue(new SafeQueue())
{
    for (int index = 0; index < _cooksNumber; index += 1)
        _cooks.push_back(Plazza::Cook());
}

Plazza::Kitchen::~Kitchen()
{
}

int Plazza::Kitchen::howManyPizzasAreCooking() const
{
    int number = 0;

    for (auto &n: _cooks)
        number += (n.isCooking()) ? 1 : 0;
    return number;
}

int Plazza::Kitchen::howManyPizzasCanITake() const
{
    return (2 * _cooksNumber - _queue->getSize() - howManyPizzasAreCooking());
}

void Plazza::Kitchen::dump() const
{
    std::cout << "We have " << _cooksNumber << " cooks here!" << std::endl;
    for (int index = 0; index < _cooksNumber; index += 1) {
        if (_cooks[index].isCooking())
            std::cout << "Cook number " << index + 1 << " is cooking!" << std::endl;
        else
            std::cout << "Cook number " << index + 1 << " is waiting!" << std::endl;
    }
    std::cout << "We also have " << _queue->getSize() << " pizzas waiting to be cooked in the queue!" << std::endl;
}

void Plazza::Kitchen::addPizzaToQueue(Plazza::Pizza &toAdd)
{
    _queue->push(toAdd);
    _queue->getConditionVariable().notify_all();
}

int Plazza::Kitchen::getFd() const
{
    return _fd;
}

void Plazza::Kitchen::takeOrder(std::string buffer)
{
    int spaceIndex = buffer.find(' ');
    Plazza::PizzaType type = (Plazza::PizzaType)std::stoi(buffer.substr(0, spaceIndex));
    Plazza::PizzaSize size = (Plazza::PizzaSize)std::stoi(buffer.substr(spaceIndex + 1, buffer.size() - spaceIndex - 1));
    Plazza::Pizza toCook(type, size);

    for (auto &c: _cooks)
        if (!c.isCooking()) {
            c.cook(toCook);
            return;
        }
    _queue->push(toCook);
    _queue->getConditionVariable().notify_all();
}

void Plazza::Kitchen::setFd(int newFd)
{
    _fd = newFd;
}

void Plazza::Kitchen::startProcess(int fd)
{
    FILE *fp = fdopen(fd, "rw");
    char *buffer = NULL;
    size_t size = 0;
    fd_set activeFds;
    FD_ZERO(&activeFds);
    FD_SET(fd, &activeFds);

    _fd = fd;
    while (1) {
        if (select(FD_SETSIZE, &activeFds, NULL, NULL, NULL) < 0)
            continue;
        getline(&buffer, &size, fp);
        std::string sbuffer(buffer);
        sbuffer.erase(--sbuffer.end());
        if (sbuffer == "dump")
            dump();
        else
            takeOrder(sbuffer);
    }
    fclose(fp);
}