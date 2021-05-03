/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#include "Cook.hpp"

Plazza::Cook::Cook(void (*pizzaIsCook)(void *, Plazza::APizza), Plazza::Kitchen *kitchen): _status(Plazza::Cook::WAITING), _pizzaIsCook(pizzaIsCook), _kitchen(kitchen)
{
}

void Plazza::Cook::startCooking(std::shared_ptr<Plazza::working_item_t> item)
{
    _item = item;
    _status = Plazza::Cook::COOKING;
}

void Plazza::Cook::run()
{
    while (_status == Plazza::Cook::WAITING);
    if (_status == Plazza::Cook::DEAD)
        return;
    _item->fridge->selectIngredients(_item->pizza);
    std::this_thread::sleep_for(std::chrono::seconds((int)_item->pizza.getBakedTime()));
    //dprintf(_item->kitchenFd, "%d %d\n", _item->pizza.getOrderId(), _item->pizza.getPizzaId());
    _status = Plazza::Cook::WAITING;
    //_pizzaIsCook(_kitchen, _item->pizza);
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