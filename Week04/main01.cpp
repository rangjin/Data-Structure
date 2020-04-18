#include <iostream>
using namespace std;

class Array {
    private:
        int *data;
        int dataCount;
        int size;
    
    public:
        Array();
        ~Array();
        int getData(int index);
        void addData(int value);
        void insertData(int index, int value);
        void removeData(int index);
};

Array::Array() {
    dataCount = 0;
    size = 10;
    data = new int[size]; // malloc
}

Array::~Array() {
    delete[] data; // free
}

void Array::addData(int value) {
    if (dataCount < 10) {
        data[dataCount] = value;
        dataCount++;
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

int Array::getData(int index) {
    if (index < dataCount) {
        return data[index];
    } else {
        return -99999;
    }
}