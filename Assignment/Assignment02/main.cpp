#include "Rectangle.cpp"
#include "Rectangle.h"

using namespace std;

// << 연산자 오버로딩
ostream &operator<<(ostream &os, Rectangle &r) {
    os << "Starting Coordinates : (" << r.x << ", " << r.y << "),\nWidth : " << r.width << ",\nHeight : " << r.height << ",";
    return os;
}

int main(void) {
    Rectangle rect1(0, 0, 50, 50);
    Rectangle rect2;

    cout << "<rect1 Information>" << endl;
    rect1.print();
    rect1.getArea();

    cout << "\n<Input rect2 Information>" << endl;
    rect2.read();

    cout << "\n<rect2 Information>" << endl;
    rect2.print();
    rect2.getArea();

    Rectangle result;

    // + 연산자 오버로딩
    result = rect1 + rect2;
    cout << "\n<+ Operator Overoading Test Result Information>\n" << result << endl;
    result.getArea();

    // / 연산자 오버로딩
    result = rect1 / rect2;
    cout << "\n</ Operator Overoading Test Result Information>" << endl;
    if (result.width == 0 && result.height == 0) {
        cout << "Intersection doesn't exist." << endl;
    } else {
        cout << result << endl;
        result.getArea();
    }

    // == 연산자 오버로딩
    cout << "\n<== Operator Overoading Test>" << endl;
    bool b;
    b = rect1 == rect2;
    if (b) {
        cout << "rect1 and rect2 are consistent." << endl;
    } else {
        cout << "rect1 and rect2 are inconsistent." << endl;
    }

    return 0;
}