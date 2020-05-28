#include <iostream>
#include <string.h>

using namespace std;

class Bag {
    protected:
        int* items;
        int size;
        int top;
    
    public:
        Bag();
        ~Bag();
        void push(int item);
        virtual int pop();
        virtual int peek();
};

Bag::Bag() {
    size = 5;
    items = new int[size];
    top = 0;
}

Bag::~Bag() {
    delete[] items;
}

void Bag::push(int item) {
    if (top < size) {
        items[top++] = item;
    } else {
        size *= 2;
        int* newitems = new int[size];
        // 메모리 복사
        memcpy(newitems, items, sizeof(int) * top); 
        newitems[top++] = item;
        delete[] items;
        items = newitems;
    }
}

int Bag::pop() {
    if (top > 0) {
        int pos = top / 2;
        int value = items[pos];
        for (int i = pos; i < top - 1; i++) {
            items[i] = items[i + 1];
        }
        top--;
        return value;
    } else {
        throw "bag is empty";
    }
}

int Bag::peek() {
    if (top > 0) {
        return items[top / 2];
    } else {
        throw "bag is empty";
    }
}

class Stack : public Bag {
    public:
        int pop();
        int peek();
};

int Stack::pop() {
    if (top > 0) {
        int pos = top - 1;
        int value = items[pos];
        for (int i = pos; i < top - 1; i++) {
            items[i] = items[i + 1];
        }
        top--;
        return value;
    } else {
        throw "stack is empty";
    }
}

int Stack::peek() {
    if (top > 0) {
        return items[top - 1];
    } else {
        throw "stack is empty";
    }
}

int main() {
    Bag b;
    Stack s;

    // 예외처리
    try {
        cout << b.pop() << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }

    try {
        cout << s.pop() << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }

    b.push(2);
    b.push(3);
    b.push(4);

    s.push(2);
    s.push(3);
    s.push(4);

    cout << b.pop() << endl;
    cout << s.pop() << endl;
}