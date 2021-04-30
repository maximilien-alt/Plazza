/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Server
*/

#include "Server.hpp"

Plazza::Server::Server(const int &multiplier, const int &cooks, const int &cooldown): _timeMultiplier(multiplier), _cooksPerKitchen(cooks), _ingredientsCoolDown(cooldown)
{
    try {
        _socket.createServerSocket();
    } catch (const std::exception &e) {
        throw Error(e.what());
    }
    _reception = new Plazza::Reception(_timeMultiplier);
}

Plazza::Server::~Server()
{
    delete _reception;
}

void Plazza::Server::createKitchen()
{
    Plazza::Kitchen newOne = _kitchenManager.giveMeKitchen(_timeMultiplier, _cooksPerKitchen, _ingredientsCoolDown);

    if (fork() == 0) {
        Plazza::Socket kitchenSocket;
        kitchenSocket._connect(_socket.getListenginPort());
        newOne.startProcess(kitchenSocket);
        exit(0);
    }
    int fd = _socket._accept();
    _socket.setActiveFd(fd);
    _kitchenManager.addKitchen(fd, newOne, 2 * _cooksPerKitchen);
}

Plazza::APizza *getPizzaFromPosition(std::unordered_map<int, std::shared_ptr<Plazza::APizza>> pizzas, int position)
{
    int index = 0;

    for (auto &n: pizzas) {
        if (index == position)
            return n.second.get();
        index += 1;
    }
    return nullptr;
}

void Plazza::Server::OneOrder(Plazza::Order order)
{
    std::unordered_map<int, std::shared_ptr<Plazza::APizza>> &pizzas = order.getPizzas();

    for (size_t index = 0; index < _kitchenManager.size(); index += 1) {
        try {
            std::pair<std::shared_ptr<Plazza::Kitchen>, int> pair = _kitchenManager.at(index);
            int kitchenFd = pair.first->getFd();
            for (int i = 0; i < pair.second; i += 1) {
                if (pizzas.empty())
                    return;
                Plazza::APizza *currentPizza = getPizzaFromPosition(pizzas, 0);
                dprintf(kitchenFd, "%s\n", PizzaFactory::pack(*currentPizza).c_str());
                pizzas.erase(pizzas.begin());
            }
        } catch (const std::exception &e) {
            std::cerr << e.what();
            return;
        }
    }
    if (!pizzas.empty()) {
        int kitchenToCreate = pizzas.size() / (2 * _cooksPerKitchen);
        kitchenToCreate = (!kitchenToCreate) ? 1 : kitchenToCreate;
        for (int index = 0; index < kitchenToCreate; index += 1)
            createKitchen();
        return (OneOrder(order));
    }
}

void Plazza::Server::parseOrders(std::vector<Plazza::Order> orders)
{
    for (auto &n: orders) {
        _storage.insert(std::make_pair(n.getOrderId(), n));
        OneOrder(n);
    }
}

std::string Plazza::Server::readFromKitchen(int fd)
{
    try {
        FILE *fp = _socket._fdopen(fd, "r");
        std::string buffer = _socket._getline(fp);
        if (buffer == "kill")
            _kitchenManager.deleteKitchenFromFd(fd);
        return buffer;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return std::string("");
    }
}

void Plazza::Server::acceptOrRead(int i)
{
    bool status = false;

    if (i == 0) {
        try {
            std::vector<Plazza::Order> orders = _reception->getOrders(status);
            parseOrders(orders);
            if (status)
                _kitchenManager.dump();
            orders.clear();
        } catch (const std::exception &e) {
            //getline failed, end of all process
            exit(0);
        }
    } else
        readFromKitchen(i);
}

void Plazza::Server::loop()
{
    int value = 0;

    _socket.setActiveFd(0);
    while (1) {
        value = _socket._select();
        if (value < 0)
            continue;
        for (int i = 0; i < _socket.getFdsSize(); i += 1)
            if (_socket.isFdSet(i))
                acceptOrRead(i);
    }
}