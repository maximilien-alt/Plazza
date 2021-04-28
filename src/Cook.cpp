/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#include "Cook.hpp"

Plazza::Cook::Cook(): _isCooking(0)
{
}

bool Plazza::Cook::isCooking() const
{
    return _isCooking;
}