#pragma once
#include <iostream>
using namespace std;

class List {
    private:
        int *items;
        int size;
    
    public:
        int itemCount;

        List();
        ~List();
        int getItem(int index);
        void addItem(int itm);
        void insertItem(int index, int itm);
        int removeAt(int index);
        int removeItem(int itm);
        void concat(List &list);
        void print();
};