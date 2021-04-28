/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Plazza::Kitchen::Kitchen(const float &time, const int &cooks, const int &cooldown): _cooksNumber(cooks), _IngredientsCoolDown(cooldown), _timeMultiplier(time), _fd(0), _queue(new SafeQueue)
{
    std::cout << "Creating "<< _cooksNumber << " cooks" << std::endl;
    for (int index = 0; index < _cooksNumber; index += 1) {
        _cooks.push_back(Plazza::Cook());
    }
}

Plazza::Kitchen::~Kitchen()
{
    delete _queue;
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

int Plazza::Kitchen::getFd() const
{
    return _fd;
}

void split(std::string toParse, std::vector<std::string> &vector, std::string delimiter)
{
    size_t pos = 0;
    std::string token;

    while ((pos = toParse.find(delimiter)) != std::string::npos) {
        token = toParse.substr(0, pos);
        vector.push_back(token);
        toParse.erase(0, pos + delimiter.length());
    }
    if (toParse.empty())
        return;
    vector.push_back(toParse);
}

void Plazza::Kitchen::takeOrder(std::string buffer)
{
    std::vector<std::string> vector;
    Plazza::PizzaSize size;

    split(buffer, vector, " ");
    size << vector[1];
    std::shared_ptr<Plazza::APizza> pizza = _factory.giveMeAPizza(vector[0], size, std::stoi(vector[2]), std::stoi(vector[3]), _timeMultiplier);

    _queue->push(pizza);
    _queue->getConditionVariable().notify_all();
}

void Plazza::Kitchen::setFd(int newFd)
{
    _fd = newFd;
}

void Plazza::Kitchen::startProcess(Socket &socket)
{
    int fd = socket.getSocketId();
    FILE *fp = socket._fdopen(fd, "rw");

    socket.setActiveFd(fd);
    _fd = fd;
    while (1) {
        if (socket._select() < 0)
            continue;
        std::string sbuffer = socket._getline(fp);
        sbuffer.erase(--sbuffer.end());
        if (sbuffer == "dump")
            dump();
        else if (sbuffer == "howManyPizzasCanITake")
            dprintf(_fd, "%d\n", howManyPizzasCanITake());
        else
            takeOrder(sbuffer);
    }
    fclose(fp);
}