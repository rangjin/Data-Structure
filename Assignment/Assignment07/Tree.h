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

        void Insert(T n) {
            Insert(root, n);
        }

        void Insert(TreeNode<T> *&currentNode, T n) {
            if (currentNode == NULL) {
                currentNode = new TreeNode<T>(n);
            } else if (n > currentNode -> data) {
                Insert(currentNode -> rightChild, n);
            } else if (n < currentNode -> data) {
                Insert(currentNode -> leftChild, n);
            }
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