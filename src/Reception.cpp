/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Reception
*/

#include "Reception.hpp"

Plazza::Reception::Reception()
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

std::vector<Plazza::Order> Plazza::Reception::getOrders(bool &status)
{
    std::vector<Plazza::Order> vector;

    if (!getline(std::cin, _line))
        throw Error("[Reception]: Fail GetLine!");
    _currentOrders.clear();
    splitLineIntoVector(_line, _currentOrders, ";");
    for (auto &n: _currentOrders) {
        try {
            if (n != "status")
                vector.push_back(Plazza::Order(n));
            else
                status = true;
        } catch (const std::exception &e) {
            continue;
        }
    }
    return (vector);
}