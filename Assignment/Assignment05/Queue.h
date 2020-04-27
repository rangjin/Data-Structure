#pragma once
#include <iostream>

template <class T>

class Queue {
    private:
        T *queue;
        int front, rear, capacity;

    public:
        Queue(int queueCapacity = 10);
        bool IsEmpty();
        T& Front();
        T& Rear();
        void Push(const T& x);
        void Pop();
};