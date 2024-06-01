#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val);
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, int val);
    Node* findMin(Node* node);
    Node* remove(Node* node, int val);
    void preOrder(Node* node, std::string &result);
    void inOrder(Node* node, std::string &result);
    void postOrder(Node* node, std::string &result);
    int size(Node* node);

public:
    BinaryTree();
    ~BinaryTree();
    void insert(int val);
    void remove(int val);
    std::string preOrder();
    std::string inOrder();
    std::string postOrder();
    int size();
};

#endif // BINARYTREE_H
