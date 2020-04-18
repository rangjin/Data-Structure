#include <iostream>
using namespace std;

class OrderedArray {
    private:
        int *data;
        int dataCount;
        int size;
    
    public:
        OrderedArray();
        ~OrderedArray();
        int getData(int index);
        void addData(int value);
        void insertData(int index, int value);
        void removeData(int index);
};

OrderedArray::OrderedArray() {
    dataCount = 0;
    size = 10;
    data = new int[size]; // malloc
}

OrderedArray::~OrderedArray() {
    delete[] data; // free
}

void OrderedArray::addData(int value) {
    if (dataCount < 10) {
        int pos;
        for (pos = 0; pos < dataCount; pos++) {
            if (data[pos] > value) {
                break;
            }
        }
        if (pos == dataCount) {
            data[dataCount] = value;
            dataCount++;
        } else {
            // insertData();
        }
    } else {
        int *newData = new int[size*2];
        for (int i = 0; i < dataCount; i++) {
            newData[i] = data[i];
        }
        newData[dataCount] = value;
        dataCount++;
        delete[] data;
        data = newData;
        size = size * 2;
    }
}

int OrderedArray::getData(int index) {
    if (index < dataCount) {
        return data[index];
    } else {
        return -99999;
    }
}