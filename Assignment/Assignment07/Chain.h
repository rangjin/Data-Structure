#pragma once
#include <iostream>

using namespace std;

template <class T> class Chain;
template <class T>
class ChainNode {
    friend class Chain<T>;
    public:
        ChainNode(const T& e) {
            data = e;
            link = nullptr;
        }

    private:
        T data;
        ChainNode<T> *link;
};

template <class T>
class Chain {
    public:
        Chain() {
            first = 0;
        }

        void InsertBlock(const T& e) {
            if (first) {
                last -> link = new ChainNode<T>(e);
                last = last -> link;
            } else {
                first = last = new ChainNode<T>(e);
            }
        }

        void Concatenate(Chain<T>& b) {
            if (first) {
                last -> link = b.first;
                last = b.last;
            } else {
                first = b.first;
                last = b.last;
            }
            b.first = b.last = 0;
        }

        void Reverse() {
            ChainNode<T> *current = first, *previous = 0;
            while (current) {
                ChainNode<T> *r = previous;
                previous = current;
                current = current -> link;
                previous -> link = r;
            }
            first = previous;
        }

        void Print() {
            ChainNode<int> *n = first;

            if (n == 0) {
                return;
            }

            while (true) {
                int k = n -> data;
                cout << k;
                n = n -> link;

                if (n == nullptr) {
                    break;
                } else {
                    cout << " -> ";
                }
            }
            cout << endl;
        }

    private: 
        ChainNode<T> *first;
        ChainNode<T> *last;
};