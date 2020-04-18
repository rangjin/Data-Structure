// [과제1] 시간측정코드 조사 및 작성
// 나노초 단위로 시간 측정

#include <iostream>
#include <chrono>

using namespace std;

int main(void) {
    // 시작시간
    auto start = chrono::high_resolution_clock::now();

    // 시간측정을 위한 코드
    int k = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            k++;
        }
    }

    // 종료시간
    auto end = chrono::high_resolution_clock::now();

    // 경과 시간 출력
    cout << "Time: " << (end - start).count() << " nano sec" << endl;

    return 0;
}