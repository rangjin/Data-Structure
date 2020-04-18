#include "List.h"

List::List() {
    itemCount = 0;
    size = 5;
    items = new int[size];
}

List::~List() {
    delete[] items;
}

int List::getItem(int index) {
    if (index < itemCount) {
        return items[index];
    } else {
        return -99999;
    }
}

void List::addItem(int itm) {
    if (itemCount < size) {
        items[itemCount] = itm;
        itemCount++;
    } else {
        int *newItems = new int[size*2];

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

void List::insertItem(int index, int itm) {
    if (itemCount >= size) {
        int *newItems = new int[size*2];

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

int List::removeAt(int index) {
    if (index > itemCount) {
        return -99999;
    } else {
        int k = items[index];

        for (int i = index; i < itemCount - 1; i++) {
            items[i] = items[i + 1];
        }

        itemCount--;

        return k;
    }
}

int List::removeItem(int itm) {
    int index = -1;

    for (int i = 0; i < itemCount; i++) {
        if (items[i] == itm) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return -99999;
    } else {
        int k = items[index];

        for (int i = index; i < itemCount - 1; i++) {
            items[i] = items[i + 1];
        }

        itemCount--;

        return k;
    }
}

void List::concat(List &list) {
    for (int i = 0; i < list.itemCount; i++) {
        addItem(list.getItem(i));
    }
}

void List::print() {
    for (int i = 0; i < itemCount; i++) {
        cout << getItem(i) << " ";
    }
    cout << "\n";
}