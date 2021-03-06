/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#include "Cook.hpp"

Plazza::Cook::Cook(void (*finish)(void *, Plazza::APizza), Plazza::Kitchen *kitchen): _status(Plazza::Cook::WAITING), _finish(finish), _kitchen(kitchen)
{
}

void Plazza::Cook::startCooking(std::shared_ptr<Plazza::working_item_t> item)
{
    _item = item;
    _status = Plazza::Cook::COOKING;
}

void Plazza::Cook::run()
{
    int time = 0;

    //std::cout << "Waiting" << std::endl;
    while (_status == Plazza::Cook::WAITING);
    if (_status == Plazza::Cook::DEAD)
        return;
    _item->fridge->selectIngredients(_item->pizza);
    time = _item->pizza.getBakedTime() * 1000;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    _finish(_kitchen, _item->pizza);
    _status = Plazza::Cook::WAITING;
    run();
}

Plazza::Cook::STATUS Plazza::Cook::getStatus() const
{
    return _status;
}

void Plazza::Cook::autoDestruct()
{
    _status = Plazza::Cook::DEAD;
}