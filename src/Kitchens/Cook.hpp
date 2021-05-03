/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "../../include/include.hpp"
#include "../Thread/SafeQueue.hpp"
#include "../Thread/ScopedLock.hpp"
#include "../Thread/IMutex.hpp"

namespace Plazza {
    class Kitchen;
    class Cook {
        public:
            enum STATUS
            {
                WAITING,
                COOKING,
                DEAD
            };

            Cook();
            ~Cook() = default;

            STATUS getStatus() const;
            void startCooking(std::shared_ptr<working_item_t>);
            void run();
            void autoDestruct();

        private:
            std::shared_ptr<working_item_t> _item;
            STATUS _status;
    };
}

#endif /* !COOK_HPP_ */