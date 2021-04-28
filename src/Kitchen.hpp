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
#include "Socket.hpp"
#include "PizzaFactory.hpp"
#include "SafeQueue.hpp"

namespace Plazza {
    class Kitchen {
        public:
            Kitchen() = default;
            Kitchen(const float &, const int &, const int &);
            ~Kitchen();

            void dump() const;
            int howManyPizzasCanITake() const;
            int howManyPizzasAreCooking() const;
            void takeOrder(std::string buffer);
            void startProcess(Socket &);
            int getFd() const;
            void setFd(int newFd);

        private:
            int _cooksNumber;
            int _IngredientsCoolDown;
            float _timeMultiplier;
            int _fd;
            std::vector<Cook> _cooks;
            mutable ISafeQueue *_queue;
            PizzaFactory _factory;
    };
}

#endif /* !KITCHEN_HPP_ */