#pragma once
#include <iostream>
#include "Tree.h"

using namespace std;

template <class K, class E>
class BST {
    private:
        TreeNode<pair<K, E>> *root;

    public:
        BST () {
            root = 0;
        }

        bool IsEmpty() const {
            return root == NULL;
        }

        pair<K, E>* Get(const K& k) {
            TreeNode <pair <K, E>> *currentNode = root;

            while (currentNode) {
                if (k < currentNode -> data.first) {
                    currentNode = currentNode -> leftChild;
                } else if (k > currentNode -> data.first) {
                    currentNode = currentNode -> rightChild;
                } else {
                    return &currentNode -> data;
                }
            }

            return 0;
        }

        pair <K, E>* RankGet(int r) {
            TreeNode <pair<K, E>> *currentNode = root;
            while (currentNode) {
                if (r < currentNode -> leftSize) {
                    currentNode = currentNode -> leftChild;
                } else if (r > currentNode -> leftChild) {
                    r -= currentNode -> leftChild;
                    currentNode = currentNode -> rightChild;
                } else {
                    return &currentNode -> data;
                }
            }
            return 0;
        }

        void Insert(const pair<K, E> & thePair) {
            TreeNode<pair<K, E>> *p = root, *pp = 0;
            while (p) {
                pp = p;
                if (thePair.first < p -> data.first) {
                    p = p -> leftChild;
                } else if (thePair.first > p -> data.first) {
                    p = p -> rightChild;
                } else {
                    p -> data.second = thePair.second;
                    return;
                }
            }

            p = new TreeNode<pair<K, E>> (thePair);
            if (root) {
                if (thePair.first < pp -> data.first) {
                    pp -> leftChild = p;
                } else {
                    pp -> rightChild = p;
                }
            } else {
                root = p;
            }
        }

        void Delete(const K& k) {
            root = Delete(root, k);
        }

        TreeNode<pair<K, E>>* Delete(TreeNode<pair<K, E>> *node, const K& k) {
            if (node == NULL) {
                return NULL;
            } else if (k > node -> data.first) {
                node -> rightChild = Delete(node -> rightChild, k);
            } else if (k < node -> data.first) {
                node -> leftChild = Delete(node -> leftChild, k);
            } else {
                if (node -> leftChild == NULL && node -> rightChild == NULL) {
                    node = NULL;
                    return node;
                } else if (node -> leftChild == NULL) {
                    node = node -> rightChild;
                    return node;
                } else if (node -> rightChild == NULL) {
                    node = node -> leftChild;
                    return node;
                } else {
                    TreeNode<pair<K, E>> *remove;
                    remove = node -> rightChild;
                    while (remove -> leftChild != NULL) {
                        remove = remove -> leftChild;
                    }

                    int minVal1 = remove -> data.first;
                    int minVal2 = remove -> data.second;
                    node = Delete(node, minVal1);
                    node -> data.first = minVal1;
                    node -> data.second = minVal2;
                    return node;
                }
            }
        }

        void Split(const K& k, BST<K, E>& small, pair<K, E>*& mid, BST<K, E>& big) {
            if (!root) {
                small.root = big.root = 0;
                return;
            }

            TreeNode <pair<K, E>> *sHead = new TreeNode<pair<K, E>>, *s = sHead, *bHead = new TreeNode<pair<K, E>>, *b = bHead, *currentNode = root;

            while (currentNode) {
                if (k < currentNode -> data.first) {
                    b -> leftChild = currentNode;
                    b = currentNode;
                    currentNode = currentNode -> leftChild;
                } else if (k > currentNode -> data.first) {
                    s -> rightChild = currentNode;
                    s = currentNode;
                    currentNode = currentNode -> rightChild;
                } else {
                    s -> rightChild = currentNode -> leftChild;
                    b -> leftChild = currentNode -> rightChild;
                    small.root = sHead -> rightChild;
                    delete sHead;
                    big.root = bHead -> leftChild;
                    delete bHead;
                    mid = new pair<K, E>(currentNode -> data.first, currentNode -> data.second);
                    delete currentNode;
                    return;
                }

                s -> rightChild = b -> leftChild = 0;
                small.root = sHead -> rightChild;
                delete sHead;
                big.root = bHead -> leftChild;
                delete bHead;
                mid = 0;
                return;
            }
        }

        void Inorder() {
            Inorder(root);
        }

        void Inorder(TreeNode<pair<K, E>> *currentNode) {
            if (currentNode) {
                Inorder(currentNode -> leftChild);
                Visit(currentNode);
                Inorder(currentNode -> rightChild);
            }
        }

        void Visit(TreeNode<pair<K, E>> *currentNode) {
            cout << currentNode -> data.first << " " << currentNode -> data.second << endl;
        }
};