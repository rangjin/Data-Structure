#include "Rectangle.h"

// 생성자 1
Rectangle::Rectangle() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

// 생성자 2
Rectangle::Rectangle(int m, int n, int w, int h) {
    x = m;
    y = n;
    width = w;
    height = h;
}

// 소멸자
Rectangle::~Rectangle() {

}

Rectangle Rectangle::operator+(Rectangle &r) {
    Rectangle rect;

    int arr_x[4] = {x, x + width, r.x, r.x + r.width};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr_x[i] > arr_x[j]) {
                int temp = arr_x[i];
                arr_x[i] = arr_x[j];
                arr_x[j] = temp;
            }
        }
    }

    int arr_y[4] = {y, y + height, r.y, r.y + r.height};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr_y[i] > arr_y[j]) {
                int temp = arr_y[i];
                arr_y[i] = arr_y[j];
                arr_y[j] = temp;
            }
        }
    }

    rect.x = arr_x[0];
    rect.y = arr_y[0];
    rect.width = arr_x[3] - arr_x[0];
    rect.height = arr_y[3] - arr_y[0];

    return rect;
}

Rectangle Rectangle::operator/(Rectangle &r) {
    Rectangle rect;

    if ((x > r.x + r.width || r.x > x + width) || (y > r.y + r.height || r.y > y + height)) {
        rect.x = 0;
        rect.y = 0;
        rect.width = 0;
        rect.height = 0;

        return rect;
    } else {
        int arr_x[4] = {x, x + width, r.x, r.x + r.width};
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (arr_x[i] > arr_x[j]) {
                    int temp = arr_x[i];
                    arr_x[i] = arr_x[j];
                    arr_x[j] = temp;
                }
            }
        }

        int arr_y[4] = {y, y + height, r.y, r.y + r.height};
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (arr_y[i] > arr_y[j]) {
                    int temp = arr_y[i];
                    arr_y[i] = arr_y[j];
                    arr_y[j] = temp;
                }
            }
        }

        rect.x = arr_x[1];
        rect.y = arr_y[1];
        rect.width = arr_x[2] - arr_x[1];
        rect.height = arr_y[2] - arr_y[1];

        return rect;
    }
}

// == 연산자 오버로딩
bool Rectangle::operator==(Rectangle &r) {
    if (x == r.x && y == r.y && width == r.width && height == r.height) {
        return true;
    } else {
        return false;
    }
}

// read 함수
void Rectangle::read() {
    cout << "Starting Coordinates : ";
    cin >> x >> y;
    cout << "Width : ";
    cin >> width;
    cout << "Height : ";
    cin >> height;
}

// print 함수
void Rectangle::print() {
    cout << "Starting Coordinates : (" << x << ", " << y << "),\nWidth : " << width << ",\nHeight : " << height << "," << endl;
}

// getArea 함수
void Rectangle::getArea() {
    cout << "Area : " << width * height << endl;
}