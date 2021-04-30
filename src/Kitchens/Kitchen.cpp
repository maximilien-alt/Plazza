/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Plazza::Kitchen::Kitchen(const float &time, const int &cooks, const int &cooldown): _cooksNumber(cooks), _IngredientsCoolDown(cooldown), _timeMultiplier(time), _fd(0), _cooks(cooks)
{
    std::cout << "New kitchen created with " << _cooksNumber << " cooks!" << std::endl;
    _item.fridge = new Plazza::Fridge();
}

Plazza::Kitchen::~Kitchen()
{
    //delete _queue;
    //delete _item.fridge;
}

int Plazza::Kitchen::howManyPizzasAreCooking() const
{
    std::vector<Plazza::Thread::STATUS> status = _cooks.getThreadsStatus();

    return std::count(status.begin(), status.end(), Plazza::Thread::STATUS::RUNNING);
}

bool Plazza::Kitchen::operator==(const Kitchen& r)
{
    return _fd == r.getFd();
}

int Plazza::Kitchen::howManyPizzasCanITake() const
{
    return (2 * _cooksNumber - _cooks.getQueueSize() - howManyPizzasAreCooking());
}

void Plazza::Kitchen::dump() const
{
    std::shared_ptr<Plazza::IMutex> mutex = std::make_shared<Plazza::AMutex>();
    ScopedLock lock(mutex);
    int index = 1;

    std::cout << "We have " << _cooksNumber << " cooks here!" << std::endl;
    std::vector<Plazza::Thread::STATUS> status = _cooks.getThreadsStatus();
    for (auto &n: status) {
        if (n == Plazza::Thread::STATUS::RUNNING)
            std::cout << "Cook number " << index++ << " is cooking!" << std::endl;
        else
            std::cout << "Cook number " << index++ << " is waiting!" << std::endl;
    }
    std::cout << "We also have " << _cooks.getQueueSize() << " pizzas waiting to be cooked in the queue!" << std::endl;
    _item.fridge->showContent();
}

int Plazza::Kitchen::getFd() const
{
    return _fd;
}

void Plazza::Kitchen::takeOrder(std::string sbuffer)
{
    std::shared_ptr<Plazza::IMutex> mutex = std::make_shared<Plazza::AMutex>();
    ScopedLock lock(mutex);

    Plazza::APizza pizza = Plazza::PizzaFactory::unpack(sbuffer, _timeMultiplier);
    _item.pizza = pizza;
    _cooks.addItem(_item);
    _cooks.run();
}

void Plazza::Kitchen::setFd(int newFd)
{
    _fd = newFd;
}

void Plazza::Kitchen::selfKill()
{
    dprintf(_fd, "kill\n");
    exit(0);
}

void Plazza::Kitchen::startProcess(Socket &socket)
{
    int fd = socket.getSocketId();
    FILE *fp = socket._fdopen(fd, "rw");

    socket.setActiveFd(fd);
    _fd = fd;
    while (1) {
        try {
            std::string sbuffer = socket._getline(fp);
            sbuffer.erase(--sbuffer.end());
            if (sbuffer == "dump")
                dump();
            else if (sbuffer == "howManyPizzasCanITake")
                dprintf(_fd, "%d\n", howManyPizzasCanITake());
            else takeOrder(sbuffer);
        } catch (const std::exception &e) {
            std::cerr << e.what();
            selfKill();
        }
    }
    //fclose(fp);
}