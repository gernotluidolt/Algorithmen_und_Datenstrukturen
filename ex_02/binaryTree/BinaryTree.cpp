#include "BinaryTree.h"

Node::Node(int val) {
    data = val;
    left = right = nullptr;
}

BinaryTree::BinaryTree() {
    std::cout << "Binary Tree created." << std::endl;
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    std::cout << "BinaryTree destroyed." << std::endl;
}

Node* BinaryTree::insert(Node* node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    if (val < node->data) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }
    return node;
}

Node* BinaryTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* BinaryTree::remove(Node* node, int val) {
    if (node == nullptr) return node;
    if (val < node->data) {
        node->left = remove(node->left, val);
    } else if (val > node->data) {
        node->right = remove(node->right, val);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

void BinaryTree::preOrder(Node* node, std::string &result) {
    if (node == nullptr) return;
    result += std::to_string(node->data) + " ";
    preOrder(node->left, result);
    preOrder(node->right, result);
}

void BinaryTree::inOrder(Node* node, std::string &result) {
    if (node == nullptr) return;
    inOrder(node->left, result);
    result += std::to_string(node->data) + " ";
    inOrder(node->right, result);
}

void BinaryTree::postOrder(Node* node, std::string &result) {
    if (node == nullptr) return;
    postOrder(node->left, result);
    postOrder(node->right, result);
    result += std::to_string(node->data) + " ";
}

int BinaryTree::size(Node* node) {
    if (node == nullptr) return 0;
    return 1 + size(node->left) + size(node->right);
}

void BinaryTree::insert(int val) {
    std::cout << "Inserting " << val << std::endl;
    root = insert(root, val);
}

void BinaryTree::remove(int val) {
    std::cout << "Removing " << val << std::endl;
    root = remove(root, val);
}

std::string BinaryTree::preOrder() {
    std::string result;
    preOrder(root, result);
    return result;
}

std::string BinaryTree::inOrder() {
    std::string result;
    inOrder(root, result);
    return result;
}

std::string BinaryTree::postOrder() {
    std::string result;
    postOrder(root, result);
    return result;
}

int BinaryTree::size() {
    return size(root);
}
