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

void Plazza::APizza::setIngredients(std::vector<Ingredients> ingredients)
{
    _ingredients = ingredients;
}

void Plazza::APizza::setOrderId(int id)
{
    _orderId = id;
}

void Plazza::APizza::setPizzaId(int id)
{
    _pizzaId = id;
}

void Plazza::APizza::setBakedTime(float time)
{
    _bakedTime = time;
}

void Plazza::APizza::setSize(PizzaSize size)
{
    _size = size;
}

void Plazza::APizza::setType(PizzaType type)
{
    _type = type;
}

Plazza::PizzaType Plazza::APizza::getType() const
{
    return _type;
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

Plazza::PizzaType& operator<<(Plazza::PizzaType &lhs, const std::string &rhs)
{
    if (rhs == "margarita")
        lhs = Plazza::PizzaType::margarita;
    else if (rhs == "regina")
        lhs = Plazza::PizzaType::regina;
    else if (rhs == "americana")
        lhs = Plazza::PizzaType::americana;
    else if (rhs == "fantasia")
        lhs = Plazza::PizzaType::fantasia;
    return lhs;
}

std::string& operator<<(std::string &lhs, Plazza::PizzaType &rhs)
{
    if (rhs == Plazza::PizzaType::margarita)
        lhs = "margarita";
    else if (rhs == Plazza::PizzaType::regina)
        lhs = "regina";
    else if (rhs == Plazza::PizzaType::americana)
        lhs = "americana";
    else if (rhs == Plazza::PizzaType::fantasia)
        lhs = "fantasia";
    return lhs;
}

std::ostream &operator<<(std::ostream &s, const Plazza::APizza &rhs)
{
    std::string type;
    Plazza::PizzaType ptype = rhs.getType();
    std::string size;
    Plazza::PizzaSize psize = rhs.getSize();
    type << ptype;
    size << psize;
    s << "Pizza Number " << rhs.getPizzaId() << ": " << type << " " << size << std::endl;
    return s;
}