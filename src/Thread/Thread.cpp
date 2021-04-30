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

void Plazza::Thread::run(std::shared_ptr<Plazza::APizza> pizza)
{
    if (_status != Plazza::Thread::NOTRUNNING)
        return;
    _pizza = pizza.get();
    std::cout << "Should cook this pizza: " << *_pizza << std::endl;
    _status = Plazza::Thread::RUNNING;
    pthread_create(&_thread, nullptr, &Plazza::Thread::execute, this);
}

void *Plazza::Thread::execute(void *arg)
{
    Plazza::Thread *_this = static_cast<Plazza::Thread *>(arg);

    std::this_thread::sleep_for(std::chrono::seconds((int)_this->_pizza->getBakedTime()));
    _this->_status = Plazza::Thread::NOTRUNNING;
    return nullptr;
}

Plazza::Thread::STATUS Plazza::Thread::getStatus() const
{
    return (_status);
}