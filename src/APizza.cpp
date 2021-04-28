/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** APizza
*/

#include "APizza.hpp"

Plazza::APizza::APizza(const Plazza::PizzaSize &size, const int &orderId, const int &pizzaId, const float &bakedTime, const Plazza::Ingredients &first, const Plazza::Ingredients &second, const Plazza::Ingredients &third, const Plazza::Ingredients &fourth, const Plazza::Ingredients &fifth):
    _size(size), _orderId(orderId), _pizzaId(pizzaId), _bakedTime(bakedTime)
{
    _ingredients.push_back(first);
    _ingredients.push_back(second);
    _ingredients.push_back(third);
    if (fourth != Plazza::Ingredients::Nothing)
        _ingredients.push_back(fourth);
    if (fifth != Plazza::Ingredients::Nothing)
        _ingredients.push_back(fifth);
}

Plazza::APizza::~APizza()
{
}

std::vector<Plazza::Ingredients> Plazza::APizza::getIngredients() const
{
    return _ingredients;
}

Plazza::PizzaSize Plazza::APizza::getSize() const
{
    return _size;
}

int Plazza::APizza::getOrderId() const
{
    return _orderId;
}

int Plazza::APizza::getPizzaId() const
{
    return _pizzaId;
}

float Plazza::APizza::getBakedTime() const
{
    return _bakedTime;
}

bool Plazza::APizza::isCooked() const
{
    return _isCooked;
}

void Plazza::APizza::setCookingStatus(bool isCooked)
{
    _isCooked = isCooked;
}

Plazza::PizzaSize& operator<<(Plazza::PizzaSize &lhs, const std::string &rhs)
{
    if (rhs == "S")
        lhs = Plazza::PizzaSize::S;
    else if (rhs == "M")
        lhs = Plazza::PizzaSize::M;
    else if (rhs == "L")
        lhs = Plazza::PizzaSize::L;
    else if (rhs == "XL")
        lhs = Plazza::PizzaSize::XL;
    else if (rhs == "XXL")
        lhs = Plazza::PizzaSize::XXL;
    return lhs;
}

std::string& operator<<(std::string &lhs, Plazza::PizzaSize &rhs)
{
    if (rhs == Plazza::PizzaSize::S)
        lhs = "S";
    else if (rhs == Plazza::PizzaSize::M)
        lhs = "M";
    else if (rhs == Plazza::PizzaSize::L)
        lhs = "L";
    else if (rhs == Plazza::PizzaSize::XL)
        lhs = "XL";
    else if (rhs == Plazza::PizzaSize::XXL)
        lhs = "XXL";
    return lhs;
}