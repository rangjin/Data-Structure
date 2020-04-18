// 시간 측정

#include <iostream>
#include <time.h>

int main(void) {
    int start, end;
    int i, j;

    // 시작시간
    start = time(NULL);

    // 시간측정을 위한 코드
    for (i = 0; i < 10000; i++)
        for(j = 0; j < 10000; j++)

    // 종료시간
    end = time(NULL);
    
    std::cout << "Time: " << end - start << " sec";

    return 0;
}
