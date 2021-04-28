/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include "../include/include.hpp"
#include "Cook.hpp"
#include "SafeQueue.hpp"
#include "Socket.hpp"

namespace Plazza {
    class Kitchen {
        public:
            Kitchen() = default;
            Kitchen(const int &, const int &, const int &);
            ~Kitchen();

            void dump() const;
            int howManyPizzasCanITake() const;
            int howManyPizzasAreCooking() const;
            void addPizzaToQueue(Plazza::Pizza &);
            void takeOrder(std::string buffer);
            void startProcess(Socket &);
            int getFd() const;
            void setFd(int newFd);

        private:
            int _cooksNumber;
            int _IngredientsCoolDown;
            int _timeMultiplier;
            int _fd;
            std::vector<Plazza::Cook> _cooks;
            mutable ISafeQueue *_queue;
    };
}

#endif /* !KITCHEN_HPP_ */