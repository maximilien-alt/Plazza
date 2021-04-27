/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** main
*/

#include "../include/include.hpp"
#include "Reception.hpp"
#include "Server.hpp"

bool is_digit(const char value)
{
    return std::isdigit(value);
}

int main(int ac, char *av[])
{
    if (ac != 4)
        return (84);
    auto isnum = [](const std::string& value){return std::all_of(value.begin(), value.end(), is_digit);};
    std::string tab[3];
    for (int index = 1; index < ac; index += 1) {
        tab[index - 1] = std::string(av[index]);
        if (!isnum(tab[index - 1]))
            return (84);
    }
    try {
        Plazza::Server server(std::stoi(tab[0]), std::stoi(tab[1]), std::stoi(tab[2]));
        server.initSocket();
        server.loop();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}