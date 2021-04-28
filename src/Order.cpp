/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Order
*/

#include "Order.hpp"

static const std::regex regOrder("^(\\s*)([a-zA-Z]+)(\\s*)(S|M|L|XL|XXL)(\\s*)x([1-9][0-9]*)(\\s*)$");

Plazza::Order::Order(const std::string &order, int id, float time): _id(id), _time(time)
{
    std::smatch baseMatch;

    if (!std::regex_match(order, baseMatch, regOrder))
        throw Error("[Order Constructor]: Order Line don't match with regex! ('" + order + "')");

    _size = std::stoi(baseMatch[6]);
    try {
        std::cout << "---" << std::endl << "Ordering Pizzas into " << _id << "th order!" << std::endl;
        Plazza::PizzaSize size(Plazza::PizzaSize::Null);
        for (size_t index = 0; index < _size; index += 1) {
            std::cout << "Creating Pizza number " << index << " which is a " << baseMatch[2] << "of size " << baseMatch[4] << std::endl;
            size << baseMatch[4];
            std::shared_ptr<Plazza::APizza> pizza = _factory.giveMeAPizza(baseMatch[2], size, _id, (int)index, _time);
            _pizzas.insert(std::make_pair(index, pizza));
        }
        std::cout << "---" << std::endl;
    } catch (const std::exception &e) {
        throw Error(e.what());
    }
}

Plazza::Order::~Order()
{
    if (!_pizzas.empty())
        _pizzas.clear();
}

int Plazza::Order::getOrderId() const
{
    return _id;
}

std::unordered_map<int, std::shared_ptr<Plazza::APizza>> &Plazza::Order::getPizzas()
{
    return _pizzas;
}

size_t Plazza::Order::getSize() const
{
    return _size;
}