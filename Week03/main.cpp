#include <iostream>
#include "Rectangle.cpp"
#include "Rectangle.h"

using namespace std;

ostream &operator<<(ostream &os, Rectangle &r) {
    // private는 접근이 불가능하므로 public 함수를 만들어 이를 통해 접근함
    // 혹은 friend 지정
    os << "WIDTH : " << r.width << ", HEIGHT : " << r.height << endl;

    return os;
}

int main(void) {
    Rectangle rect;
    Rectangle rectMini(5, 3);

    rect.read();

    rect = rect + rectMini;

    rect.printArea();

    cout << rect;

    return 0;
}