#pragma once
#include <iostream>

template <class T>

class Stack {
    private:
        T *stack;
        int top;
        int capacity;

    public:
        Stack(int stackCapacity = 10);
        bool IsEmpty() const;
        T& Top() const;
        void Push (const T& item);
        void Pop();
        void ChangeSize1D(T *&a, const int oldSize, const int newSize);
};