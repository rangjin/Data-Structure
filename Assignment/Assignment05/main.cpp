#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

int main(void) {
    cout << "<Stack Test>" << endl;
    Stack<int> s;
    int state = 1;
    while (state) {
        int k;
        cout << "Select(1: IsEmpty, 2, Top, 3: Push, 4: Pop, 5: Test end) : ";
        cin >> k;
        switch (k) {
            case 1:
                if (s.IsEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack isn't empty." << endl;
                }
                break;
            case 2:
                try {
                    cout << "Stack's top is " << s.Top() << endl;
                } catch (const char* s) {
                    cout << s << endl;
                }
                break;
            case 3:
                int m;
                cout << "What number do you want to push? ";
                cin >> m;
                s.Push(m);
                break;
            case 4:
                try {
                    s.Pop();
                    cout << "Pop command is executed." << endl;
                } catch (const char* s) {
                    cout << s << endl;
                }
                break;
            case 5:
                state = 0;
                break;
            default:
                cout << "Input number 1 ~ 5" << endl;
                break;
        }
    }

    cout << "\n\n\n<Queue Test>" << endl;
    Queue<int> q;
    state = 1;
    while (state) {
        int k;
        cout << "Select(1: IsEmpty, 2, Front, 3: Rear, 4: Push, 5: Pop, 6: Test end) : ";
        cin >> k;
        switch (k) {
            case 1:
                if (q.IsEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue isn't empty." << endl;
                }
                break;
            case 2:
                try {
                    cout << "Queue's front is " << q.Front() << endl;
                } catch (const char* s) {
                    cout << s << endl;
                }
                break;
            case 3:
                try {
                    cout << "Queue's rear is " << q.Rear() << endl;
                } catch (const char* s) {
                    cout << s << endl;
                }
                break;
            case 4:
                int m;
                cout << "What number do you want to push? ";
                cin >> m;
                q.Push(m);
                break;
            case 5:
                try {
                    q.Pop();
                    cout << "Pop command is executed." << endl;
                } catch (const char* s) {
                    cout << s << endl;
                }
                break;
            case 6:
                state = 0;
                break;
            default:
                cout << "Input number 1 ~ 6" << endl;
                break;
        }
    }
}