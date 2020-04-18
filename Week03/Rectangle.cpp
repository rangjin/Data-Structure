#include "Rectangle.h"

Rectangle::Rectangle() {
    width = 0;
    height = 0;
}

Rectangle::Rectangle(int w, int h) {
    width = w;
    height = h;
}

Rectangle::~Rectangle() {
    // 객체가 사라질 때
}

Rectangle Rectangle::operator+(Rectangle &r) { // 연산자 오버로딩
    Rectangle rect;
    rect.width = width + r.width;
    rect.height = height + r.height;

    return rect;
}

void Rectangle::read() {
    cout << "INPUT WIDTH : ";
    cin >> width;
    cout << "INPUT HEIGHT : ";
    cin >> height;
}

void Rectangle::print() {
    cout << "WITDH : " << width << ", HEIGHT : " << height << endl;
}

void Rectangle::printArea() {
    cout << "AREA : " << width * height << endl;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}