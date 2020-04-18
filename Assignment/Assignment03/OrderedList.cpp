#include "OrderedList.h"

OrderedList::OrderedList() {
    itemCount = 0;
    size = 5;
    items = new int[size];
}

OrderedList::~OrderedList() {
    delete[] items;
}

int OrderedList::getItem(int index) {
    if (index < itemCount) {
        return items[index];
    } else {
        return -99999;
    }
}

void OrderedList::addItem(int itm) {
    if (itemCount >= size) {
        int *newItems = new int[size*2];

        for (int i = 0; i < itemCount; i++) {
            newItems[i] = items[i];
        }

        size = size * 2;

        delete[] items;
        items = newItems;
    }
    
    int index = -1;

    for (int i = 0; i < itemCount; i++) {
        if (items[i] > itm) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        items[itemCount] = itm;
    } else {
        for (int i = itemCount; i > index; i--) {
            items[i] = items[i - 1];
        }
    
        items[index] = itm;
    }

    itemCount++;
}

int OrderedList::removeAt(int index) {
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

int OrderedList::removeItem(int itm) {
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

void OrderedList::concat(OrderedList &olist) {
    for (int i = 0; i < olist.itemCount; i++) {
        addItem(olist.getItem(i));
    }
}

void OrderedList::print() {
    for (int i = 0; i < itemCount; i++) {
        cout << getItem(i) << " ";
    }
    cout << "\n";
}