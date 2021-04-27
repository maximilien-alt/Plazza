/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Order
*/

#include "Order.hpp"

static const std::regex regOrder("^(\\s*)([a-zA-Z]+)(\\s*)(S|M|L|XL|XXL)(\\s*)x([1-9][0-9]*)(\\s*)$");

Plazza::Order::Order(const std::string &order)
{
    std::smatch baseMatch;

    if (!std::regex_match(order, baseMatch, regOrder))
        throw Error("[Order Constructor]: Order Line don't match with regex! ('" + order + "')");

    _size = std::stoi(baseMatch[6]);
    try {
        Plazza::Pizza pizza(baseMatch[2], baseMatch[4]);
        for (size_t index = 0; index < _size; index += 1)
            _pizzas.push_back(pizza);
    } catch (const std::exception &e) {
        throw Error(e.what());
    }
    std::cout << _size << " Pizzas have been created!" << std::endl << "----" << std::endl;
    for (auto &n: _pizzas)
        std::cout << n;
    std::cout << "----" << std::endl;
}

Plazza::Order::~Order()
{
    if (!_pizzas.empty())
        _pizzas.clear();
}

std::vector<Plazza::Pizza> &Plazza::Order::getPizzas()
{
    return _pizzas;
}

size_t Plazza::Order::getSize() const
{
    return _size;
}