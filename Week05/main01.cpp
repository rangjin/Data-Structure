#include <iostream>

using namespace std;

template <typename T>

T add(T a, T b) {
    return a + b;
}

int main(void) {
    cout << add<int>(3.2, 5) << endl;
    cout << add<double>(3.2, 5) << endl;

    return 0;
}