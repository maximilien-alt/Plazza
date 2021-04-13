/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** main
*/

#include "../include/include.hpp"
#include "Producer.hpp"
#include "Consumer.hpp"
#include "SafeQueue.hpp"

int main(int __attribute__((unused))ac, char *av[])
{
    int number = std::stoi(std::string(av[1]));
    std::unordered_map<std::shared_ptr<Plazza::Producer>, std::shared_ptr<Plazza::Consumer>> _map;
    Plazza::ISafeQueue *queue = new Plazza::SafeQueue();

    srand(time(NULL));
    for (int index = 0; index < number; index += 1)
    {
        _map[std::make_shared<Plazza::Producer>(*queue, index)] = std::make_shared<Plazza::Consumer>(*queue, index);
    }
    return (0);
}