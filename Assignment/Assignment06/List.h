#pragma once
#include <iostream>
using namespace std;

template <class T>

class List {
    private:
        T *items;
        int size;
        int itemCount;
    
    public:
        List();
        ~List();
        T getItem(int index);
        void addItem(T itm);
        void insertItem(int index, T itm);
        T removeAt(int index);
        T removeItem(T itm);
        void concat(List &list);
        void print();
        int getItemCount();
};

template <class T>
List<T>::List() {
    itemCount = 0;
    size = 5;
    items = new T[size];
}

template <class T>
List<T>::~List() {
    delete[] items;
}

template <class T>
T List<T>::getItem(int index) {
    if (index < itemCount) {
        return items[index];
    } else {
        throw "error";
    }
}

template <class T>
void List<T>::addItem(T itm) {
    if (itemCount < size) {
        items[itemCount] = itm;
        itemCount++;
    } else {
        T *newItems = new T[size*2];

        for (int i = 0; i < itemCount; i++) {
            newItems[i] = items[i];
        }

        newItems[itemCount] = itm;
        itemCount++;
        size = size * 2;

        delete[] items;
        items = newItems;
    }
}

template <class T>
void List<T>::insertItem(int index, T itm) {
    if (itemCount >= size) {
        T *newItems = new T[size*2];

        for (int i = 0; i < itemCount; i++) {
            newItems[i] = items[i];
        }

        size = size * 2;

        delete[] items;
        items = newItems;
    }

    itemCount++;

    for (int i = itemCount; i > index; i--) {
        items[i] = items[i - 1];
    }

    items[index] = itm;
}

template <class T>
T List<T>::removeAt(int index) {
    T k = items[index];

    for (int i = index; i < itemCount - 1; i++) {
        items[i] = items[i + 1];
    }

    itemCount--;

    return k;
}

template <class T>
T List<T>::removeItem(T itm) {
    int index = -1;

    for (int i = 0; i < itemCount; i++) {
        if (items[i] == itm) {
            index = i;
            break;
        }
    }

    T k = items[index];

    for (int i = index; i < itemCount - 1; i++) {
        items[i] = items[i + 1];
    }

    itemCount--;

    return k;

}

template <class T>
void List<T>::concat(List &list) {
    for (int i = 0; i < list.itemCount; i++) {
        addItem(list.getItem(i));
    }
}

template <class T>
void List<T>::print() {
    for (int i = 0; i < itemCount; i++) {
        cout << getItem(i) << " ";
    }
    cout << "\n";
}

template <class T>
int List<T>::getItemCount() {
    return itemCount;
}