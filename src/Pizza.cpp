/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Pizza
*/

#include "Pizza.hpp"

Plazza::Pizza::Pizza(const PizzaType &type, const PizzaSize &size): _type(type), _size(size)
{
}

Plazza::Pizza::Pizza(const std::string &type, const std::string &size): _type(Plazza::PizzaType::None), _size(Plazza::PizzaSize::Null)
{
    if (type == "regina")
        _type = Regina;
    if (type == "margarita")
        _type = Margarita;
    if (type == "americana")
        _type = Americana;
    if (type == "fantasia")
        _type = Fantasia;
    if (_type == Plazza::PizzaType::None)
        throw Error("[Pizza Constructor]: Wrong type! ('" + type + "')");
    if (size == "S")
        _size = S;
    if (size == "M")
        _size = M;
    if (size == "L")
        _size = L;
    if (size == "XL")
        _size = XL;
    if (size == "XXL")
        _size = XXL;
    if (_size == Plazza::PizzaSize::Null)
        throw Error("[Pizza Constructor]: Wrong size! ('" + size + "')");
}

Plazza::Pizza::~Pizza()
{
}

Plazza::PizzaType Plazza::Pizza::getType() const
{
    return _type;
}

Plazza::PizzaSize Plazza::Pizza::getSize() const
{
    return _size;
}

std::ostream &operator<<(std::ostream &s, const Plazza::Pizza &rhs)
{
    std::string type("None");
    std::string size("Null");

    switch (rhs.getType()) {
        case Plazza::Regina: type = "regina";
            break;
        case Plazza::Margarita: type = "margarita";
            break;
        case Plazza::Americana: type = "americana";
            break;
        case Plazza::Fantasia: type = "fantasia";
            break;
        default: break;
    }
    switch (rhs.getSize()) {
        case Plazza::S: size = "S";
            break;
        case Plazza::M: size = "M";
            break;
        case Plazza::L: size = "L";
            break;
        case Plazza::XL: size = "XL";
            break;
        case Plazza::XXL: size = "XXL";
            break;
        default: break;
    }
    s << "Pizza '" << type << "' of size '" << size << "'!" << std::endl;
    return (s);
}