/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Reception
*/

#include "Reception.hpp"

Plazza::Reception::Reception(const float time): _timeMultiplier(time), _ids(1)
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
    static std::ifstream order(".order.txt");

    getline(order, _line);
    if (order.eof())
        return vector;
    _currentOrders.clear();
    splitLineIntoVector(_line, _currentOrders, ";");
    for (auto &n: _currentOrders) {
        try {
            if (n != "status")
                vector.push_back(Plazza::Order(n, _ids++, _timeMultiplier));
            else
                status = true;
        } catch (const std::exception &e) {
            _ids -= 1;
            continue;
        }
    }
    return (vector);
}