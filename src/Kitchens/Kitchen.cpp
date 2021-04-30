/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Plazza::Kitchen::Kitchen(const float &time, const int &cooks, const int &cooldown, const int &id): _cooksNumber(cooks), _IngredientsCoolDown(cooldown), _timeMultiplier(time), _fd(0), _id(id), _cooks(cooks) 
{
    std::cout << "New kitchen created with " << _cooksNumber << " cooks!" << std::endl;
    _item.fridge = new Plazza::Fridge();
    _item.kitchenFd = 0;
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

    std::cout << "  Kitchen number " << _id << ":" << std::endl;
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
    write(_fd, &index, 4);
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
    _item.kitchenFd = _fd;
}

void Plazza::Kitchen::selfKill()
{
    std::cout << "For some reasons, I decided to kill myself" << std::endl;
    dprintf(_fd, "kill\n");
    exit(0);
}

void Plazza::Kitchen::parseQuestions(std::string sbuffer)
{
    if (sbuffer == "dump")
        dump();
    if (sbuffer == "ping") {
        std::cout << "Just get pinged from server! Better have to watch the log.txt file ;)" << std::endl;
        if (_cooks.getQueueSize() > 0)
            _cooks.run();
        _isActive = true;
    }
}

std::vector<std::string> Plazza::Kitchen::fromIds(std::string str)
{
    std::vector<std::string> vector;
    size_t pos = 0;
    std::string token;

    while ((pos = str.find(' ')) != std::string::npos)
    {
        token = str.substr(0, pos);
        vector.push_back(token);
        str.erase(0, pos + 1);
    }
    if (!str.empty())
        vector.push_back(str);
    return vector;
}

void Plazza::Kitchen::startProcess(Socket &socket)
{
    int fd = socket.getSocketId();
    FILE *fp = socket._fdopen(fd, "rw");
    int protocol = 0;

    socket.setActiveFd(fd);
    _fd = fd;
    _item.kitchenFd = _fd;
    while (1) {
        //handleClocks();
        if (socket._select() < 0 || !read(_fd, &protocol, 4))
            continue;
        try {
            std::string sbuffer = socket._getline(fp);
            sbuffer.erase(--sbuffer.end());
            switch (protocol) {
                case 1: parseQuestions(sbuffer);
                    break;
                case 2: takeOrder(sbuffer);
                    break;
                default: break;
            }
        } catch (const std::exception &e) {
            //std::cerr << e.what();
            selfKill();
        }
    }
}

void Plazza::Kitchen::handleClocks()
{
    if (_refillClock.getElapsedTime() > _IngredientsCoolDown) {
        _item.fridge->refillStock();
        _refillClock.reset();
        std::cout << "Refill Stock!" << std::endl;
    }
    if (_activityClock.getElapsedTime() > 5) {
        std::cout << "Time to check this kitchen activity" << std::endl;
        if (!_isActive && !_cooks.areTheyWorking())
            return selfKill();
        _isActive = false;
        _activityClock.reset();
    }
}