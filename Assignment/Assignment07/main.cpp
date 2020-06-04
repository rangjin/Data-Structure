#include "Chain.h"
#include "Tree.h"
#include "MaxHeap.h"
#include "BST.h"

using namespace std;

int main(void) {
    cout << "<< Linked List Test >>" << endl << endl;
    Chain<int> c1, c2;
    c1.Print();

    for (int i = 0; i < 5; i++) {
        cout << "Insert " << i << " to c1." << endl;
        c1.InsertBlock(i);
    }
    cout <<"c1: ";
    c1.Print();

    cout << endl;

    for (int i = 5; i < 10; i++) {
        cout << "Insert " << i << " to c2." << endl;
        c2.InsertBlock(i);
    }

    cout <<"c2: ";
    c2.Print();

    cout << endl << "Concat c2 to c1." << endl;
    c1.Concatenate(c2);
    cout << "c1: ";
    c1.Print();

    cout << endl << "Reverse c1." << endl;
    c1.Reverse();
    cout << "c1: ";
    c1.Print();
    cout << endl;

    cout << "<< Tree Test >>" << endl << endl;

    Tree<int> t1;

    int arr[11] = {5, 8, 9, 3, 0, 6, 1, 2, 7, 4, '\0'};
    
    cout << "arr : ";

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Insert " << arr[i] << " in t." << endl;
        t1.Insert(arr[i]);
    }

    cout << endl << "Inorder Print" << endl;
    t1.Inorder();
    cout << endl << endl << "Preorder Print" << endl;
    t1.Preorder();
    cout << endl << endl << "Postorder Print" << endl;
    t1.Postorder();

    cout << endl << endl << "Create t2." << endl << endl;;
    Tree<int> t2;

    if (t1 == t2) {
        cout << "t2 is same with t1." << endl;
    } else {
        cout << "t2 isn't same with t1." << endl;
    }

    cout << endl << "Create t3 to copy t1." << endl;
    Tree<int> t3(t1);
    
    cout << endl << "t1 to Inorder print" << endl;
    t1.Inorder();
    cout << endl << endl << "t3 to Inorder print" << endl;
    t3.Inorder();

    cout << endl << endl;

    if (t1 == t3) {
        cout << "t3 is same with t1." << endl;
    } else {
        cout << "t3 isn't same with t1." << endl;
    }

    cout << endl << "<< MaxHeap Test >>" << endl << endl << endl;

    MaxHeap<int> mh;

    if (mh.IsEmpty()) {
        cout << "mh is empty" << endl;
    } else {
        cout << "no" << endl;
    }

    cout << endl << "arr : ";

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < 10; i++ ){
        cout << "Push " << arr[i] << " to mh" << endl;
        mh.Push(arr[i]);
    }

    cout << endl;

    if (mh.IsEmpty()) {
        cout << "mh is empty." << endl;
    } else {
        cout << "mh is not empty." << endl;
    }

    cout << endl << "mh's max is " << mh.Top() << endl;

    cout << endl << "Pop max from mh." << endl;
    mh.Pop();

    cout << endl << "mh's max is " << mh.Top() << endl << endl;

    cout << "<< BST Test >>" << endl << endl << endl;

    BST<int, int> bst, big, small;
    pair<int, int> *k;

    if (bst.IsEmpty()) {
        cout << "bst is empty" << endl << endl;
    } else {
        cout << "bst isn't empty" << endl << endl;
    }

    for (int i = 0; i < 10; i++) {
        cout << "Insert " << arr[i] << " to bst." << endl;
        bst.Insert(pair<int, int>(arr[i], arr[i]));
    }
    cout << endl;

    if (bst.IsEmpty()) {
        cout << "bst is empty" << endl << endl;
    } else {
        cout << "bst isn't empty" << endl << endl;
    }

    cout << "Inorder Print bst" << endl;
    bst.Inorder();

    cout << endl << endl <<  "Delete " << arr[5] << " from bst." << endl << endl;

    cout << "Inorder Print bst" << endl;
    bst.Inorder();

    cout << endl << endl << "Split bst to " << arr[5] << endl << endl;
    bst.Split(arr[5], small, k, big);

    cout << "Inorder Print small" << endl;
    small.Inorder();
    cout << endl << endl << "Inorder Print big" << endl;
    big.Inorder();
    cout << endl << endl << "mid is " << k -> first << endl;

    return 0;
}