/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-tekspice-lucas.dudot
** File description:
** Errors
*/

#include "Error.hpp"

Plazza::Error::Error(std::string const &message, std::string const &component) noexcept: _message(message), _component(component)
{
}

const char *Plazza::Error::what() const noexcept
{
    return (_message.data());
}

std::string const &Plazza::Error::getComponent() const
{
    return (_component);
}