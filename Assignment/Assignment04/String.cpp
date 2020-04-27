#include "String.h"
#include <stdio.h>

String::String() : String(10) {
}


String::String(String &s) : String(s.length + 1) {
    for (int i = 0; i < s.length; i++) {
        buffer[i] = s.buffer[i];
    }
    buffer[s.length] = '\0';
    length = s.length;
}


String::~String() {
    delete[] buffer;
}

String::String(int m) {
    size = m;
    buffer = new char[m];
    length = 0;
}

String::String(char* init, int m) : String(m + 1) {
    for (int i = 0; i < m; i++) {
        buffer[i] = init[i];
    }
    buffer[m] = '\0';
    length = m;
}

String String::Concat(String t) {
    String result(length + t.length + 1);

    for (int i = 0; i < length; i++) {
        result.buffer[i] = buffer[i];
    }

    for (int i = 0; i < t.length; i++) {
        result.buffer[length + i] = t.buffer[i];
    }

    result.buffer[length + t.length] = '\0';
    result.length = length + t.length;

    return result;
}

String& String::operator=(const String& s) {
    delete[] buffer;
    buffer = new char[s.length + 1];
    for (int i = 0; i < s.length; i++) {
        buffer[i] = s.buffer[i];
    }
    buffer[s.length] = '\0';
    length = s.length;
    size = s.length + 1;

    return *this;
}

bool String::operator==(String t) {
    if (length == t.length) {
        for (int i = 0; i < length; i++) {
            if (buffer[i] != t.buffer[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool String::operator!() {
    if (length == 0) {
        if (buffer[0] == '\0') {
            return true;
        }
    }
    return false;
}

int String::Length() {
    return length;
}

String String::Substr(int i, int j) {
    String result(j - i + 2);

    for (int k = 0; k < j - i + 1; k++) {
        result.buffer[k] = buffer[k + i];
    }

    result.buffer[j - i + 1] = '\0';
    result.length = j - i + 1;

    return result;
}

int String::Find(String pat)  {
    for (int i = 0; i <= Length() - pat.Length(); i++) {
        int j;
        for (j = 0; j < pat.Length() && buffer[i + j] == pat.buffer[j]; j++);
        if (j == pat.Length()) {
            return i;
        }
    }
    return -1;
}

void String::print() {
    for (int i = 0; i < length; i++) {
        cout << buffer[i];
    }
}