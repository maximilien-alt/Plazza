/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Fridge
*/

#include "Fridge.hpp"

Plazza::Fridge::Fridge()
{
    _content.insert(std::make_pair(Plazza::Ingredients::Doe, 5));
    _content.insert(std::make_pair(Plazza::Ingredients::Tomato, 5));
    _content.insert(std::make_pair(Plazza::Ingredients::Gruyere, 5));
    _content.insert(std::make_pair(Plazza::Ingredients::Ham, 5));
    _content.insert(std::make_pair(Plazza::Ingredients::Mushrooms, 5));
    _content.insert(std::make_pair(Plazza::Ingredients::Steak, 5));
    _content.insert(std::make_pair(Plazza::Ingredients::EggPlant, 5));
    _content.insert(std::make_pair(Plazza::Ingredients::Goat_Cheese, 5));
    _content.insert(std::make_pair(Plazza::Ingredients::Chief_Love, 5));
}

Plazza::Fridge::~Fridge()
{
}

std::string Plazza::Fridge::packIngredient(Plazza::Ingredients ing)
{
    switch (ing) {
        case Doe: return ("Doe");
        case Tomato: return ("Tomato");
        case Gruyere: return ("Gruyere");
        case Ham: return ("Ham");
        case Mushrooms: return ("Mushrooms");
        case Steak: return ("Steak");
        case EggPlant: return ("EggPlant");
        case Goat_Cheese: return ("Goat_Cheese");
        case Chief_Love: return ("Chief_Love");
        default: break;
    }
    return "Nothing";
}

bool Plazza::Fridge::canCook(Plazza::APizza pizza)
{
    std::vector<Plazza::Ingredients> need = pizza.getIngredients();

    for (auto &n: need) {
        if (_content[n] == 0)
            return false;
    }
    return true;
}

void Plazza::Fridge::showContent() const
{
    int index = 0;

    std::cout << "Fridge: ";
    for (auto &n: _content) {
        if (index++)
            std::cout << ", ";
        std::cout << n.second << "x " << Plazza::Fridge::packIngredient(n.first);
    }
    std::cout << std::endl;
}

void Plazza::Fridge::selectIngredients(APizza pizza)
{
    for (auto &n: pizza.getIngredients())
        (*_content.find(n)).second -= 1;
}

void Plazza::Fridge::refillStock()
{
    for (auto &n: _content)
        n.second += (n.second == 5) ? 0 : 1;
}

std::unordered_map<Plazza::Ingredients, int> &Plazza::Fridge::getContent()
{
    return _content;
}