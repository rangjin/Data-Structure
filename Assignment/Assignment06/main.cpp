#include <iostream>
#include <string.h>
#include "Calculator.cpp"
using namespace std;

int main(void) {
    while (true) {
        Calculator c;
        char expr[1000];

        cout << "< Input formula (if you want to get out, input 'e') >" << endl;
        cin.getline(expr, 1000);
        
        if (expr[0] == 'e') {
            break;
        } else {
            c.setExpression(expr);

            cout << "errCode is " << c.getErrorCode() << endl;

            try {
                int k = c.getValue();
                String str;
                str = c.getPostFix();
                cout << "postfix notation is '";
                str.print();

                cout << "'" << endl << "answer is " << k << endl;
            } catch (char const* c) {
                cout << c << " Wrong formula!" << endl;
            }
            cout << endl;
        }
    }
}
