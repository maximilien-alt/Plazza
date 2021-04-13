/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-maximilien.drules
** File description:
** ISafeQueue
*/

#ifndef ISAFEQUEUE_HPP_
#define ISAFEQUEUE_HPP_

namespace Plazza {
    class ISafeQueue {
        public:
            virtual ~ISafeQueue() = default;
            virtual void push(int value) = 0;
            virtual bool tryPop(int &value) = 0;
    };
}

#endif /* !ISAFEQUEUE_HPP_ */