#pragma once
#include <iostream>
using namespace std;

class Rectangle {
    public:
        int x;
        int y;
        int width;
        int height;

        friend ostream &operator<<(ostream &os, Rectangle &r);
    
    public:
        // 생성자 1
        Rectangle();
        // 생성자 2
        Rectangle(int m, int n, int w, int h);
        // 소멸자
        ~Rectangle();

        Rectangle operator+(Rectangle &r);
        Rectangle operator/(Rectangle &r);
        bool operator==(Rectangle &r);

        void read();
        void print();
        void getArea();
};