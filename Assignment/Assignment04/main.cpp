#include <iostream>
#include "String.cpp"

int main(void) {
    cout << "<print function test>" << endl;
    
    String a((char *)"hello", 5);
    String b((char *)"world", 5);

    cout << "String a is \"";
    a.print();
    cout << "\"." << endl;

    cout << "String b is \"";
    b.print();
    cout << "\"." << endl;

    cout << "\n<Concat function test>" << endl;

    String c;
    c = a.Concat(b);                                                                // Concat 사용

    cout << "String c is \"";
    c.print();
    cout << "\"." << endl;
    
    cout << "\n<operator== function test>" << endl;
    
    if (a == b) {                                                                   // operator == 사용
        cout << "String a is same with b." << endl;
    } else {
        cout << "String a isn't same with b." << endl;
    }
    
    String d((char *)"hello", 5);
    
    cout << "String d is \"";
    d.print();
    cout << "\"." << endl;
    
    if (a == d) {                                                                   // operator == 사용 2
        cout << "String a is same with d." << endl;
    } else {
        cout << "String a isn't same with d." << endl;
    }

    cout << "\n<operator! function test>" << endl;
    
    String e((char *)"", 0);
    
    cout << "String e is \"";
    e.print();
    cout << "\"." << endl;
    
    if (!a) {                                                                       // operator ! 사용
        cout << "String a is blan.k" << endl;
    } else {
        cout << "String a isn't blank." << endl;
    }
    
    if (!e) {                                                                       // operator ! 사용 2
        cout << "String e is blank." << endl;
    } else {
        cout << "String e isn't blank." << endl;
    }

    cout << "\n<Length function test>" << endl;     
    
    cout << "String a's length is " << a.Length() << "." << endl;                   // Length 사용
    cout << "String b's length is " << b.Length() << "." << endl;                   // Length 사용 2

    cout << "\n<Substr function test>" << endl;
    
    cout << "String f is from the ith to jth digits of String a." << endl;
    
    int i, j;
    
    cout << "Input i(0 ~ 5) : ";
    cin >> i;
    
    cout << "Input j(0 ~ 5) : ";
    cin >> j;
    
    String f;
    f = a.Substr(i, j);                                                             // Substr 사용
    
    cout << "String f is \"";
    f.print();
    cout << "\".\n";

    cout << "\n<Find function test>" << endl;
    
    String g((char *)"el", 2);
    String h((char *)"abc", 3);
    
    cout << "String g is \"";
    g.print();
    cout << "\"." << endl;
    
    cout << "String h is \"";
    h.print();
    cout << "\"." << endl;
    
    if (a.Find(g) != -1) {                                                          // Find 사용
        cout << "String g is started from " << a.Find(g);
        cout << "th(st, nd) digits in String a." << endl;
    } else {
        cout << "String g isn't in String a." << endl;
    }
    
    if (a.Find(h) != -1) {                                                          // Find 사용 2
        cout << "String h is started from " << a.Find(h);
        cout << "th(st, nd) digits in String a." << endl;
    } else {
        cout << "String h isn't in String a." << endl;
    }

    return 0;
}