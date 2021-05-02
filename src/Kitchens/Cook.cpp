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
    std::lock_guard<std::mutex> lock(_mutex);

    _item = item;
    _status = Plazza::Cook::COOKING;
    _cond_var.notify_one();
}

void Plazza::Cook::run()
{
    std::unique_lock<std::mutex> lock(_mutex);

    _cond_var.wait(lock, [this]() {
        return (_status == Plazza::Cook::COOKING);
    });
    if (_status == Plazza::Cook::DEAD)
        return;
    _item->fridge->selectIngredients(_item->pizza);
    std::this_thread::sleep_for(std::chrono::seconds((int)_item->pizza.getBakedTime()));
    _status = Plazza::Cook::WAITING;
    _pizzaIsCook(_kitchen, _item->pizza);
    run();
}

Plazza::Cook::STATUS Plazza::Cook::getStatus() const
{
    return _status;
}

void Plazza::Cook::autoDestruct()
{
    std::lock_guard<std::mutex> lock(_mutex);

    _status = Plazza::Cook::DEAD;
    _cond_var.notify_one();
}