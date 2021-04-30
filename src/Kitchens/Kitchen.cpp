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
}

Plazza::Kitchen::~Kitchen()
{
    //delete _queue;
}

int Plazza::Kitchen::howManyPizzasAreCooking() const
{
    std::vector<Plazza::Thread::STATUS> status = _cooks.getThreadsStatus();

    return std::count(status.begin(), status.end(), Plazza::Thread::STATUS::RUNNING);
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

void Plazza::Kitchen::takeOrder(Socket &socket, FILE *fp)
{
    //std::shared_ptr<Plazza::IMutex> mutex = std::make_shared<Plazza::AMutex>();
    //ScopedLock lock(mutex);

    try {
        std::string sbuffer = socket._getline(fp);
        Plazza::APizza pizza = Plazza::PizzaFactory::unpack(sbuffer, _timeMultiplier);
        _cooks.addPizza(pizza);
        _cooks.run();
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }
}

void Plazza::Kitchen::setFd(int newFd)
{
    _fd = newFd;
}

void Plazza::Kitchen::parseQuestion(Socket &socket, FILE *fp)
{
    std::shared_ptr<Plazza::IMutex> mutex = std::make_shared<Plazza::AMutex>();
    ScopedLock lock(mutex);
    
    try {
        std::string sbuffer = socket._getline(fp);
        sbuffer.erase(--sbuffer.end());
        if (sbuffer == "dump")
            dump();
        else if (sbuffer == "howManyPizzasCanITake")
            dprintf(_fd, "%d\n", howManyPizzasCanITake());
    } catch (const std::exception &e) {
        std::cerr << e.what();
    }
}

void Plazza::Kitchen::startProcess(Socket &socket)
{
    int fd = socket.getSocketId();
    FILE *fp = socket._fdopen(fd, "rw");
    int protocol = 0;

    socket.setActiveFd(fd);
    _fd = fd;
    while (1) {
        if (!read(fd, &protocol, 4))
            continue;
        switch (protocol) {
            case 1: parseQuestion(socket, fp);
                break;
            case 2: takeOrder(socket, fp);
                break;
            default: break;
        }
    }
    fclose(fp);
}