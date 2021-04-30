/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include "../../include/include.hpp"
#include "Cook.hpp"
#include "../Server/Socket.hpp"
#include "../Pizzas/PizzaFactory.hpp"
#include "../Thread/ThreadPool.hpp"
#include "../Thread/ScopedLock.hpp"

namespace Plazza {
    class Kitchen {
        public:
            Kitchen() = default;
            //Kitchen(const Kitchen &)=;
            Kitchen(const float &, const int &, const int &);
            ~Kitchen();

            void dump() const;
            int howManyPizzasCanITake() const;
            int howManyPizzasAreCooking() const;
            void takeOrder(std::string);
            void parseQuestion(Socket &socket, FILE *fp);
            void startProcess(Socket &);
            int getFd() const;
            void setFd(int newFd);
            bool operator==(const Kitchen& r);

            void selfKill();

        private:
            int _cooksNumber;
            int _IngredientsCoolDown;
            float _timeMultiplier;
            int _fd;
            working_item_t _item;
            ThreadPool _cooks;
    };
}

#endif /* !KITCHEN_HPP_ */