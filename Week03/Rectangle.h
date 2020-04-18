#pragma once
#include <iostream>
using namespace std;

class Rectangle {
    private:
        int width;
        int height;

        // 친구 지정
        friend ostream &operator<<(ostream &os, Rectangle &r);
    
    public:
        Rectangle(); // 생성자
        Rectangle(int w, int h);
        ~Rectangle(); // 소멸자

        Rectangle operator+(Rectangle &r);
        int getWidth();
        int getHeight();

        void read();
        void print();
        void printArea();
};