#pragma once
#include <iostream>

using namespace std;

template <class T> class Tree;
template <class T>
class TreeNode
{
    friend class Tree<T>;
    public:
        T data;
        TreeNode<T> *leftChild;
        TreeNode<T> *rightChild;
        int leftSize = 1;

        TreeNode() {
            
        }

        TreeNode(T n) {
            data = n;
            leftChild = NULL;
            rightChild = NULL;
        }

        TreeNode(T n, TreeNode<T> *left, TreeNode<T> *right) {
            data = n;
            leftChild = left;
            rightChild = right;
        }
};

template <class T>
class Tree {
    private:
        TreeNode<T> *root;

    public:
        Tree() {
            root = NULL;
        }

        Tree(const Tree<T> &s) {
            root = Copy(s.root);
        }

        TreeNode<T>* Copy(TreeNode<T> *origNode) {
            if (!origNode) {
                return 0;
            }
            return new TreeNode<T>(origNode -> data, Copy(origNode -> leftChild), Copy(origNode -> rightChild));
        }

        int Height(TreeNode<T>* currentNode) {
            int h = 0;
            if (currentNode != NULL) {
                int left = Height(currentNode -> leftChild);
                int right = Height(currentNode -> rightChild);
                int maxHeight = max(left, right);
                h = maxHeight + 1;
            }
            return h;
        } 
        
        int Diff(TreeNode<T>* currentNode) {
            int left = Height(currentNode -> leftChild);
            int right = Height(currentNode -> rightChild);
            int f = left - right;
            return f;
        }

        TreeNode<T>* RR(TreeNode<T>* parent) {
            TreeNode<T>* temp;
            temp = parent->rightChild;
            parent -> rightChild = temp -> leftChild;
            temp -> leftChild = parent;
            return temp;
        }

        TreeNode<T>* LL(TreeNode<T>* parent) {
            TreeNode<T>* temp;
            temp = parent->leftChild;
            parent -> leftChild = temp -> rightChild;
            temp -> rightChild = parent;
            return temp;
        }

        TreeNode<T>* LR(TreeNode<T>* parent) {
            TreeNode<T>* temp;
            temp = parent->leftChild;
            parent -> leftChild = RR(temp);
            return LL(parent);
        }

        TreeNode<T>* RL(TreeNode<T>* parent) {
           TreeNode<T>* temp;
            temp = parent->rightChild;
            parent -> rightChild = LL(temp);
            return RR(parent);
        }

        TreeNode<T>* Balance(TreeNode<T>* currentNode) {
            int f = Diff(currentNode);
            if (f > 1) {
                if(Diff(currentNode -> leftChild) > 0) {
                    currentNode = LL(currentNode);
                } else {
                    currentNode = LR(currentNode);
                }
            } else if (f < -1) {
                if (Diff(currentNode -> rightChild) > 0) {
                    currentNode = RL(currentNode);
                } else {
                    currentNode = RR(currentNode);
                }
            }
            return currentNode;
        }

        void Insert(T n) {
            root = Insert(root, n);
        }
        
        TreeNode<T>* Insert(TreeNode<T> *&currentNode, T n) {
            if (currentNode == NULL) {
                currentNode = new TreeNode<T>(n);
                currentNode -> data = n;
                currentNode -> leftChild = NULL;
                currentNode -> rightChild = NULL;
            } else if (n > currentNode -> data) {
                Insert(currentNode -> rightChild, n);
                currentNode = Balance(currentNode);
            } else if (n < currentNode -> data) {
                Insert(currentNode -> leftChild, n);
                currentNode = Balance(currentNode);
            }
            return currentNode;
        }

        void Inorder() {
            Inorder(root);
        }

        void Inorder(TreeNode<T> *currentNode) {
            if (currentNode) {
                Inorder(currentNode -> leftChild);
                Visit(currentNode);
                Inorder(currentNode -> rightChild);
            }
        }

        void Preorder() {
            Preorder(root);
        }

        void Preorder(TreeNode<T> *currentNode) {
            if (currentNode){
                Visit(currentNode);
                Preorder(currentNode -> leftChild);
                Preorder(currentNode -> rightChild);
            }
        }

        void Postorder() {
            Postorder(root);
        }

        void Postorder(TreeNode<T> *currentNode) {
            if (currentNode) {
                Postorder(currentNode -> leftChild);
                Postorder(currentNode -> rightChild);
                Visit(currentNode);
            }
        }

        void Visit(TreeNode<T> *currentNode) {
            cout << currentNode -> data << " ";
        }

        bool operator==(const Tree& t) const {
            return Equal(root, t.root);
        }

        bool Equal(TreeNode<T> *a, TreeNode<T> *b) const {
            if ((!a) && (!b)) {
                return true;
            }
            return (a && b && (a -> data == b -> data) && Equal(a -> leftChild, b -> leftChild) && Equal(a -> rightChild, b -> rightChild));
        }
};