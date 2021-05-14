/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Server
*/

#include "Server.hpp"

Plazza::Server::Server(const int &multiplier, const int &cooks, const int &cooldown, int ordersfd): _timeMultiplier(multiplier), _cooksPerKitchen(cooks), _ingredientsCoolDown(cooldown), log("log.txt")
{
    if (cooldown < 1)
        throw Error("Ingredients cooldown is in milliseconds: try at least bigger than 1000");
    try {
        _socket.createServerSocket();
    } catch (const std::exception &e) {
        throw Error(e.what());
    }
    _reception = new Plazza::Reception(_timeMultiplier);
    _ordersfd = dup(ordersfd);
}

Plazza::Server::~Server()
{
    log.close();
    delete _reception;
}

void Plazza::Server::createKitchen()
{
    static int id = 1;

    if (fork() == 0) {
        Plazza::Kitchen newOne = _kitchenManager.giveMeKitchen(_timeMultiplier, _cooksPerKitchen, _ingredientsCoolDown, id);
        Plazza::Socket kitchenSocket;
        kitchenSocket._connect();
        std::thread timeThread(&Plazza::Kitchen::handleClocks, &newOne);
        timeThread.detach();
        newOne.startProcess(kitchenSocket);
        exit(0);
    }
    int fd = _socket._accept();
    _socket.setActiveFd(fd);
    _kitchenManager.addKitchen(fd, 2 * _cooksPerKitchen);
    id += 1;
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
    int protocol = 2;
    int response = 0;

    for (size_t index = 0; index < _kitchenManager.size(); index += 1) {
        try {
            std::pair<const int, int> &pair = _kitchenManager.at(index);
            int kitchenFd = pair.first;
            int maxPizzas = pair.second;
            for (int i = 0; i < maxPizzas; i += 1) {
                if (pizzas.empty())
                    return;
                Plazza::APizza *currentPizza = getPizzaFromPosition(pizzas, 0);
                write(kitchenFd, &protocol, 4);
                dprintf(kitchenFd, "%s\n", PizzaFactory::pack(*currentPizza).c_str());
                read(kitchenFd, &response, 4);
                pizzas.erase(pizzas.begin());
                pair.second -= 1;
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

void Plazza::Server::writeOrderToLog(Plazza::Order order)
{
    log << "-> Order Number " << order.getOrderId() << " (containing " << order.getSize() << " pizzas):" << std::endl;
    std::unordered_map<int, std::shared_ptr<Plazza::APizza>> pizzas = order.getPizzas();

    for (auto &n: pizzas)
        log << *n.second.get();
}

void Plazza::Server::updateCookedPizzaStatus(int fd, int orderId)
{
    std::unordered_map<int, Plazza::Order>::iterator it = _storage.find(orderId);
    if (it != _storage.end()) {
        if ((*it).second.pizzaIsCooked()) {
            writeOrderToLog((*it).second);
            _storage.erase(it);
            std::cout << "Order Clear: Better have to watch the log.txt file ;)" << std::endl;
        }
        _kitchenManager.updateMaxPizzasFromFd(fd, 1);
    }
}

void Plazza::Server::readFromKitchen(int fd)
{
    int number = 0;

    if (!read(fd, &number, 4))
        return;
    int protocol = number / 1000;
    switch (protocol) {
        case 2:
            _socket.clearFd(fd);
            _kitchenManager.endOne(fd);
            _kitchenManager.deleteKitchenFromFd(fd);
            close(fd);
            break;
        case 1: updateCookedPizzaStatus(fd, number % 1000);
            break;
        default: break;
    }
}

void Plazza::Server::acceptOrRead(int i)
{
    bool status = false;

    if (i == _ordersfd) {
        try {
            std::vector<Plazza::Order> orders = _reception->getOrders(status);
            parseOrders(orders);
            if (status)
                _kitchenManager.dump();
            status = false;
            orders.clear();
        } catch (const std::exception &e) {
            _kitchenManager.endAll();
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
        std::cout << _socket.getFdsSize() << std::endl;
        for (int i = 0; i < _socket.getFdsSize(); i += 1)
            if (_socket.isFdSet(i))
                acceptOrRead(i);
    }
}