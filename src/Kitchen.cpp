/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Plazza::Kitchen::Kitchen(const int &cooks, const int &cooldown, const int &time): _cooksNumber(cooks), _IngredientsCoolDown(cooldown), _timeMultiplier(time)
{
    _queue = new SafeQueue();
    for (int index = 0; index < _cooksNumber; index += 1) {
        bool isCooking = true;
        _cooks.push_back(Plazza::Cook(*_queue, _timeMultiplier, &isCooking));
    }
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
}

void Plazza::Kitchen::takeOrder(Plazza::Order &order)
{
    std::vector<Plazza::Pizza> &pizzas = order.getPizzas();
    int _maxPizzasNumber = 2 * _cooksNumber;
    int _currentPizzasNumber = howManyPizzasAreCooking() + \
    _queue->getSize();

    std::cout << "MAXPIZZA: " << _maxPizzasNumber << "NULBER: " << _currentPizzasNumber << std::endl;
    for (std::vector<Plazza::Pizza>::iterator it = pizzas.begin(); it != pizzas.end(); ++it) {
        if (_currentPizzasNumber == _maxPizzasNumber)
            return;
        std::cout << _currentPizzasNumber << std::endl;
        _queue->push(*it);
        _queue->getConditionVariable().notify_all();
        pizzas.erase(it);
        --it;
        _currentPizzasNumber += 1;
    }
}