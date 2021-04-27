/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Reception
*/

#include "Reception.hpp"

Plazza::Reception::Reception(const int &multiplier, const int &cooks, const int &cooldown): _timeMultiplier(multiplier), _cooksPerKitchen(cooks), _IngredientsCoolDown(cooldown), _line("")
{
}

Plazza::Reception::~Reception()
{
}

void splitLineIntoVector(std::string toParse, std::vector<std::string> &vector, std::string delimiter)
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

void Plazza::Reception::displayStatus()
{
    std::cout << "We have actually " << _currentOrders.size() << " orders waiting!" << std::endl;
    for (size_t index = 0; index < _kitchens.size(); index += 1) {
        std::cout << "  Kitchen number " << index + 1 << ":" << std::endl;
        _kitchens[index].dump();
    }
}

void Plazza::Reception::OneOrder(Plazza::Order &order)
{
    std::vector<Plazza::Pizza> pizzas;

    if (_kitchens.empty()) {
        Plazza::Kitchen kitchen(_cooksPerKitchen, _IngredientsCoolDown, _timeMultiplier);
        _kitchens.push_back(kitchen);
    }
    for (auto &kitch: _kitchens) {
        kitch.takeOrder(order);
        if (order.getPizzas().empty())
            break;
    }
    pizzas = order.getPizzas();
    if (!pizzas.empty()) {
        int kitchenToCreate = pizzas.size() / (2 * _cooksPerKitchen);
        kitchenToCreate = (!kitchenToCreate) ? 1 : kitchenToCreate;
        for (int index = 0; index < kitchenToCreate; index += 1) {
            Plazza::Kitchen kitchen(_cooksPerKitchen, _IngredientsCoolDown, _timeMultiplier);
            kitchen.takeOrder(order);
            _kitchens.push_back(kitchen);
        }
    }
}

void Plazza::Reception::HandleOrders()
{
    for (auto &n: _orders)
        OneOrder(n);
}

void Plazza::Reception::loopOrders()
{
    do {
        if (_line != "") {
            splitLineIntoVector(_line, _currentOrders, ";");
            for (auto &n: _currentOrders) {
                try {
                    if (n != "status") {
                        Plazza::Order order(n);
                        _orders.push_back(order);
                    } else
                        displayStatus();
                } catch (const std::exception &e) {
                    throw Error(e.what());
                }
            }
        }
        HandleOrders();
        _orders.clear();
        _currentOrders.clear();
    } while(!_currentOrders.empty() || std::getline(std::cin, _line));
}