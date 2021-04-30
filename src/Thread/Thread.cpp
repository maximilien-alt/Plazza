/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Thread
*/

#include "Thread.hpp"

Plazza::Thread::Thread(): _status(NOTRUNNING)
{

}

Plazza::Thread::~Thread()
{
    if (_status == Plazza::Thread::RUNNING)
        pthread_join(_thread, nullptr);
    _status = Plazza::Thread::DEAD;
};

void Plazza::Thread::join()
{
    if (_status == Plazza::Thread::RUNNING)
        pthread_join(_thread, nullptr);
    _status = Plazza::Thread::DEAD;
}

void Plazza::Thread::kill()
{
    if (_status != Plazza::Thread::DEAD)
        pthread_exit(nullptr);
    _status = Plazza::Thread::DEAD;
}

void Plazza::Thread::run(std::shared_ptr<Plazza::working_item_t> item)
{
    if (_status != Plazza::Thread::NOTRUNNING)
        return;
    _item = item;
    _status = Plazza::Thread::RUNNING;
    pthread_create(&_thread, nullptr, &Plazza::Thread::execute, this);
}

void *Plazza::Thread::execute(void *arg)
{
    Plazza::Thread *_this = static_cast<Plazza::Thread *>(arg);

    _this->_item->fridge->selectIngredients(_this->_item->pizza);
    std::this_thread::sleep_for(std::chrono::seconds((int)_this->_item->pizza.getBakedTime()));
    dprintf(_this->_item->kitchenFd, "%d %d\n", _this->_item->pizza.getOrderId(), _this->_item->pizza.getPizzaId());
    _this->_status = Plazza::Thread::NOTRUNNING;
    return nullptr;
}

Plazza::Thread::STATUS Plazza::Thread::getStatus() const
{
    return (_status);
}