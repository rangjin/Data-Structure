#include "Calculator.h"
#include <cmath>

Calculator::Calculator() {
    errCode = 0;
    postfix = String((char*)" ", 1);
}

String Calculator::makePostFix() {
    Stack<String> stack;
    String space ((char*)" ", 1);
    String str((char*)"", 0);
    String t, s;

    for (int i = 0; i < tokens.getItemCount(); i++) {
        t = tokens.getItem(i);
        switch (check(t)) {
            case 0:
                stack.Push(t);
                break;
            case 1:
                while (true) {
                    s = stack.Top();
                    if (check(s) == 0) {
                        stack.Pop();
                        break;
                    } else {
                        stack.Pop();
                        str = str.Concat(s);
                        str = str.Concat(space);
                    }
                }
                break;
            case 2:
            case 3:
                while (true) {
                    if (stack.IsEmpty()) {
                        break;
                    }
                    s = stack.Top();
                    if (check(s) == 0) {
                        break;
                    } else if (check(s) >= check(t)) {
                        s = stack.Top();
                        stack.Pop();
                        str = str.Concat(s);
                        str = str.Concat(space);
                    } else {
                        break;
                    }
                }
                stack.Push(t);
                break;
            case 4:
                str = str.Concat(t);
                str = str.Concat(space);
                break;
        }
    }

    while (!stack.IsEmpty()) {
        s = stack.Top();
        stack.Pop();
        str = str.Concat(s);
        str = str.Concat(space);
    }
    
    str.deleteLastBuffer();

    return str;
}

int Calculator::evaluation() {
    Stack<int> stack;
    int s, e;
    for (int i = 0; i < postfix.Length(); i++) {
        char b = postfix.getBuffer(i);
        if (b >= 48 && b <= 57) {
            s = i;
            e = i;
            i++;
            while (postfix.getBuffer(i) != ' ') {
                e++;
                i++;
            }
            e++;
            char ch[e - s + 1];
            for (int i = s; i < e; i++) {
                ch[i - s] = postfix.getBuffer(i);
            }

            stack.Push(atoi(ch));
        } else if (b == ' ') {
            ;
        } else {
            int n = stack.Top();
            stack.Pop();
            int m = stack.Top();
            stack.Pop();
            switch (b) {
                case '+':
                    stack.Push(m + n);
                    break;
                case '-':
                    stack.Push(m - n);
                    break;
                case '*':
                    stack.Push(m * n);
                    break;
                case '/':
                    stack.Push(m / n);
                    break;
            }
        }
    }
    
    int ans = stack.Top();

    return ans;
}

int Calculator::getErrorCode() {
    return errCode;
}

int Calculator::setExpression(const char* expr) {
    errCode = makeTokens(expr);
    if (errCode == 1) {
        return errCode;
    } else {
        postfix = makePostFix();
        value = evaluation();
        return errCode;
    }
}

String Calculator::getPostFix() {
    return postfix;
}

int Calculator::getValue() {
    if (errCode == 0) {
        return value;
    } else {
        throw "Error!";
    }
}

void Calculator::putTokens(const char* expr, int s, int e) {
    e++;
    char arr[e - s + 1];
    for (int i = s; i < e; i++) {
        arr[i - s] = expr[i];
    }
    String str((char *)arr, e - s);

    tokens.addItem(str);
}

int Calculator::makeTokens(const char* expr) {
    int i = 0;
    int s = 0;
    int e = 0;
    int cnt = 0;
    while (true) {
        if (categorize(expr[i]) == 'n') {
            s = i;
            e = i;
            i++;
            while (true) {
                if (categorize(expr[i]) == 't') {
                    putTokens(expr, s, e);
                    if (cnt == 0) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else if (categorize(expr[i]) == 's') {
                    i++;
                    while (true) {
                        if (categorize(expr[i]) == 's') {
                            ;
                        } else if (categorize(expr[i]) == 'n' || categorize(expr[i]) == 'o' || categorize(expr[i]) == 'r') {
                            return 1;
                        } else if (categorize(expr[i]) == 'c' || categorize(expr[i]) == 'e') {
                            putTokens(expr, s, e);
                            break;
                        } else if (categorize(expr[i]) == 't') {
                            putTokens(expr, s, e);
                            return 0;
                        }
                        i++;
                    }
                    i = e;
                    break;
                } else if (categorize(expr[i]) == 'n') {
                    e++;
                } else if (categorize(expr[i]) == 'e' || categorize(expr[i]) == 'c') {
                    putTokens(expr, s, e);
                    i = e;
                    break;
                } else if (categorize(expr[i]) == 'o' || categorize(expr[i]) == 'r') {
                    return 1;
                }
                i++;
            }
        } else if (categorize(expr[i]) == 'e') {
            s = i;
            e = i;
            i++;
            while (true) {
                if (categorize(expr[i]) == 'n' || categorize(expr[i]) == 'o') {
                    putTokens(expr, s, e);
                    i = e;
                    break;
                } else if (categorize(expr[i]) == 'r' || categorize(expr[i]) == 'e' || categorize(expr[i]) == 'c' || categorize(expr[i]) == 't') {
                    return 1;
                }
                i++;
            }
        } else if (categorize(expr[i]) == 'o') {
            cnt++;
            s = i;
            e = i;
            i++;
            while (true) {
                if (categorize(expr[i]) == 'n' || categorize(expr[i]) == 'o') {
                    putTokens(expr, s, e);
                    i = e;
                    break;
                } else if (categorize(expr[i]) == 'e' || categorize(expr[i]) == 'c' || categorize(expr[i]) == 't' || categorize(expr[i]) == 'r') {
                    return 1;
                }
                i++;
            }
        } else if (categorize(expr[i]) == 'c') {
            cnt--;
            if (cnt < 0) {
                return 1;
            }
            s = i;
            e = i;
            i++;
            while (true) {
                if (categorize(expr[i]) == 't') {
                    putTokens(expr, s, e);
                    if (cnt == 0) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else if (categorize(expr[i]) == 'e' || categorize(expr[i]) == 'c') {
                    putTokens(expr, s, e);
                    i = e;
                    break;
                } else if (categorize(expr[i]) == 'n' || categorize(expr[i]) == 'o' || categorize(expr[i]) == 'r') {
                    return 1;
                }
                i++;
            }
        }
        i++;
    }
}

char Calculator::categorize(char c) {
    if (c == 40) {
        return 'o';
    } else if (c == 41) {
        return 'c';
    } else if (c >= 48 && c <= 57) {
        return 'n';
    } else if (c == 32) {
        return 's';
    } else if (c == '\0') {
        return 't';
    } else if (c == 42 || c == 43 || c == 45 || c == 47) {
        return 'e';
    } else {
        return 'r';
    }
}

int Calculator::check(String a) {
    String open((char*)"(", 1);
    String close((char*)")", 1);
    String plus((char*)"+", 1);
    String minus((char*)"-", 1);
    String time((char*)"*", 1);
    String divide((char*)"/", 1);

    if (a == open) {
        return 0;
    } else if (a == close) {
        return 1;
    } else if (a == plus || a == minus) {
        return 2;
    } else if (a == time || a == divide) {
        return 3;
    } else {
        return 4;
    }
}