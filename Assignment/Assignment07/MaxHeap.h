#pragma once
#include <iostream>

using namespace std;

template <class T>
class MaxHeap {
    private: 
        T *heap;
        int heapSize;
        int capacity;

    public:
        MaxHeap(int theCapacity = 10) {
            if (theCapacity < 1) throw "Capacity must be >= 1";
            capacity = theCapacity;
            heapSize = 0;
            heap = new T[capacity + 1];
        }

        bool IsEmpty() const {
            return heapSize == 0;
        }

        const T& Top() {
            return heap[1];
        }

        void Push(const T& e) {
            if (heapSize == capacity) {
                ChangeSize1D(heap, capacity, 2 * capacity);
                capacity *= 2;
            }
            int currentNode = ++heapSize;
            while (currentNode != 1 && heap[currentNode / 2] < e) {
                heap[currentNode] = heap[currentNode / 2];
                currentNode /= 2;
            }
            heap[currentNode] = e;
        }

        void Pop() {
            if (IsEmpty()) throw "Heap is empty. Cannot delete.";
            heap[1].~T();
            T lastE = heap[heapSize--];

            int currentNode = 1;
            int child = 2;
            while (child <= heapSize) {
                if (child < heapSize && heap[child] < heap[child + 1]) {
                    child++;
                }

                if (lastE >= heap[child]) {
                    break;
                }

                heap[currentNode] = heap[child];
                currentNode = child;
                child *= 2;
            }
            heap[currentNode] = lastE;
        }

        void ChangeSize1D(T *&a, const int oldSize, const int newSize) {
            if (newSize < 0) throw "New length must be >= 0.";

            T *temp = new T[newSize];
            int number = min(oldSize, newSize);
            copy(a, a + number, temp);
            delete[] a;
            a = temp;
        }
};