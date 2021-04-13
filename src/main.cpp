/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** main
*/

#include "../include/include.hpp"
#include "ScopedLock.hpp"
#include "Thread.hpp"

std::shared_ptr<Plazza::IMutex> mutex = std::make_shared<Plazza::AMutex>();

void *incrementCounter(void *number)
{
    Plazza::ScopedLock lock(mutex);
    int n = 10;
    int *num = (int *)number;
    printf("start incrementing counter: %d\n", *num);
    for (int i = 0; i < n; i += 1)
        (*num) += 1;
    printf("end incrementing counter: %d\n", *num);
    return (nullptr);
}

int main(int __attribute__((unused))ac, char *av[])
{
    int numberThreads = std::stoi(std::string(av[1]));
    int value = 0;

    for (int index = 0; index < numberThreads; index += 1)
    {
        std::shared_ptr<Plazza::Thread> thread = std::make_shared<Plazza::Thread>(incrementCounter, &value);
        thread->run();
    }
    printf("%d\n", value);
    return (0);
}