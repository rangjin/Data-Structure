#pragma once
#include <iostream>
#include "String.cpp"
#include "List.h"
#include "Stack.h"
using namespace std;

class Calculator {
    private:
        List<String> tokens;
        int errCode;
        int value;
        String postfix;

        String makePostFix();                           // 후위표기식 생성
        int evaluation();                               // 변환된 후위표기식을 계산
    
    public:
        Calculator();
        int getErrorCode();                             // errCode 반환
        int setExpression(const char* expr);            // 후위표기식으로 변환, 계산
        String getPostFix();                            // 후위표시식 반환
        int getValue();                                 // 계산된 value를 반환
        int makeTokens(const char* expr);               // 입력받은 식을 토큰마다 자름
        void putTokens(const char* expr, int s, int e); // 자른 토큰을 리스트에 저장
        char categorize(char c);                        // 피연산자, 연산자, 괄호, 공백 등을 구분함
        int check(String a);
};