/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Server
*/

#include "Server.hpp"

Plazza::Server::Server(const int &multiplier, const int &cooks, const int &cooldown): _timeMultiplier(multiplier), _cooksPerKitchen(cooks), _ingredientsCoolDown(cooldown)
{
    initSocket();
    _reception = new Plazza::Reception();
}

Plazza::Server::~Server()
{
    delete _reception;
}

int Plazza::Server::initSocket()
{
    _socketId = socket(PF_INET, SOCK_STREAM, 0);
    if (_socketId == -1)
        return (84);

    bzero((char *) &_settings, sizeof(_settings));
    _settings.sin_family = AF_INET;
    _settings.sin_port = 0;
    _settings.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (bind(_socketId, (struct sockaddr *)&_settings, sizeof(_settings)) == -1)
        return (84);

    socklen_t len = sizeof(_settings);
    if (getsockname(_socketId, (struct sockaddr *)&_settings, &len) == -1)
        return (84);
    if (listen(_socketId, 1) == -1)
        return  (84);
    _listeningPort = ntohs(_settings.sin_port);
    FD_ZERO(&_activeFds);
    FD_SET(_socketId, &_activeFds);
    return (0);
}

void Plazza::Server::createKitchen()
{
    int size = sizeof(_settings);
    Plazza::Kitchen newOne = _kitchenManager.giveMeKitchen(_timeMultiplier, _cooksPerKitchen, _ingredientsCoolDown);

    if (fork() == 0) {
        int socketId = socket(PF_INET, SOCK_STREAM, 0);
        //_settings.sin_family = AF_INET;
        //_settings.sin_port = htonl(_listeningPort);
        //_settings.sin_addr.s_addr = inet_addr("127.0.0.1");
        while (connect(socketId, (struct sockaddr *)&_settings, sizeof(_settings)) == -1);
        newOne.startProcess(socketId);
        exit(0);
    }
    int fd = accept(_socketId, (struct sockaddr *)&_settings, (socklen_t *)&size);
    FD_SET(fd, &_activeFds);
    _kitchenManager.addKitchen(fd, newOne);
}

void Plazza::Server::OneOrder(Plazza::Order &order)
{
    std::vector<Plazza::Pizza> pizzas = order.getPizzas();

    for (size_t index = 0; index < _kitchenManager.size(); index += 1) {
        try {
            Plazza::Kitchen kitchen = _kitchenManager.at(index);
            int maxPizzas = kitchen.howManyPizzasCanITake();
            for (int i = 0; i < maxPizzas; i += 1) {
                if (pizzas.empty())
                    return;
                dprintf(kitchen.getFd(), "%d %d\n", (int)pizzas[0].getType(), (int)pizzas[0].getSize());
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
    for (auto &n: orders)
        OneOrder(n);
}

void Plazza::Server::readFromKitchen(int fd)
{
    FILE *fp = fdopen(fd, "r");
    size_t len = 0;
    char *buffer = NULL;
    if (getline(&buffer, &len, fp) == -1)
        return;
    printf("recu: %s, depuis la kitchen avec le fd: %d\n", buffer, fd);
    fclose(fp);
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

    FD_SET(0, &_activeFds);
    while (1) {
        _readFds = _activeFds;
        value = select(FD_SETSIZE, &_readFds, NULL, NULL, NULL);
        if (value < 0)
            continue;
        for (int i = 0; i < FD_SETSIZE; i += 1)
            if (FD_ISSET(i, &_readFds))
                acceptOrRead(i);
    }
    close(_socketId);
}