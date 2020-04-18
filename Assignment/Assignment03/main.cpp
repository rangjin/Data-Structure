#include "List.h"
#include "List.cpp"
#include "OrderedList.h"
#include "OrderedList.cpp"

#include <stdlib.h>

using namespace std;

int main(void) {
    cout << "<< Test List >>" << endl;
    
    List a, b;

    for (int i = 0; i < 20; i++) {
        a.addItem(rand() % 100 + 1);
        b.addItem(rand() % 100 + 1);
    }

    cout << "\n< list a >" << endl;
    a.print();

    cout << "\n< list b >" << endl;
    b.print();

    cout << "\n< getItem function test >";
    while (true) {
        cout << "\nInput index(-99999 : End Test) : ";
        int index;
        cin >> index;

        if (index == -99999) {
            break;
        } else {
            if (a.getItem(index) == -99999 || index < 0) {
                cout << "That index doesn't exist" << endl;
            } else {
                cout << "a[" << index << "] is " << a.getItem(index) << endl;
            }
        }
    }

    cout << "\n< addItem function test >";
    while (true) {
        cout << "\nInput item(-99999 : End Test) : ";
        int itm;
        cin >> itm;

        if (itm == -99999) {
            break;
        } else {
            a.addItem(itm);
            cout << itm << " is added. "<< endl;
            a.print();
        }
    }

    cout << "\n< insertItem function test >";
    while (true) {
        cout << "\nInput index(-99999 : End Test) : ";
        int index;
        cin >> index;

        if (index == -99999) {
            break;
        } else {
            if (index < 0 || index > a.itemCount) {
                cout << "That index doesn't exist." << endl;
            } else {
                cout << "Input item: ";
                int item;
                cin >> item;

                a.insertItem(index, item);
                cout << item << " is inserted in a[" << index << "]" << endl;
                a.print();
            }
        }
    }

    cout << "\n< removeAt function test >";
    while (true) {
        cout << "\nInput index(-99999 : End Test) : ";
        int index;
        cin >> index;

        if (index == -99999) {
            break;
        } else {
            if (a.getItem(index) == -99999 || index < 0) {
                cout << "That index doesn't exist" << endl;
            } else {
                a.removeAt(index);
                cout << "a[" << index << "] is removed" << endl;
                a.print();
            }
        }
    }

    cout << "\n< removeItem function test >";
    while (true) {
        cout << "\nInput item(-99999 : End Test) : ";
        int itm;
        cin >> itm;

        if (itm == -99999) {
            break;
        } else {
            int k = a.removeItem(itm);

            if (k == -99999) {
                cout << "That item doesn't exist" << endl;
            } else {
                cout << k << " is removed" << endl;
                a.print();
            }
        }
    }

    cout << "\n< concat function test >\n";
    a.concat(b);
    a.print();

    cout << "\n\n\n<< Test OrderedList >>" << endl;
    
    OrderedList c, d;

    for (int i = 0; i < 20; i++) {
        c.addItem(rand() % 100 + 1);
        d.addItem(rand() % 100 + 1);
    }

    cout << "\n< Orderedlist c >" << endl;
    c.print();

    cout << "\n< Orderedlist d >" << endl;
    d.print();

    cout << "\n< getItem function test >";
    while (true) {
        cout << "\nInput index(-99999 : End Test) : ";
        int index;
        cin >> index;

        if (index == -99999) {
            break;
        } else {
            if (c.getItem(index) == -99999 || index < 0) {
                cout << "That index doesn't exist" << endl;
            } else {
                cout << "c[" << index << "] is " << c.getItem(index) << endl;
            }
        }
    }

    cout << "\n< addItem function test >";
    while (true) {
        cout << "\nInput item(-99999 : End Test) : ";
        int itm;
        cin >> itm;

        if (itm == -99999) {
            break;
        } else {
            c.addItem(itm);
            cout << itm << " is added. "<< endl;
            c.print();
        }
    }

    cout << "\n< removeAt function test >";
    while (true) {
        cout << "\nInput index(-99999 : End Test) : ";
        int index;
        cin >> index;

        if (index == -99999) {
            break;
        } else {
            if (c.getItem(index) == -99999 || index < 0) {
                cout << "That index doesn't exist" << endl;
            } else {
                c.removeAt(index);
                cout << "c[" << index << "] is removed" << endl;
                c.print();
            }
        }
    }

    cout << "\n< removeItem function test >";
    while (true) {
        cout << "\nInput item(-99999 : End Test) : ";
        int itm;
        cin >> itm;

        if (itm == -99999) {
            break;
        } else {
            int k = c.removeItem(itm);
            
            if (k == -99999) {
                cout << "That item doesn't exist" << endl;
            } else {
                cout << k << " is removed" << endl;
                c.print();
            }
        }
    }

    cout << "\n< concat function test >\n";
    c.concat(d);
    c.print();
}