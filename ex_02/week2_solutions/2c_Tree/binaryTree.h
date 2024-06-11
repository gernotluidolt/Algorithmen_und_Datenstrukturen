#include "binaryTreeNode.h"
#include <string>
#include <sstream>

#pragma once


class BinaryTree {
    public:
        BinaryTreeNode* rootNode;

        BinaryTree(int rootNodeKey);

        BinaryTreeNode* search(int value);
        BinaryTreeNode* insert(int key);
        BinaryTreeNode* deleteItem(int key);
        BinaryTreeNode* findMin(BinaryTreeNode* node);
        BinaryTreeNode* findMax(BinaryTreeNode* node);
        std::string printPreorder(BinaryTreeNode* node);
        std::string printPreorder();

};




// std::string printPreorder(BinaryTreeNode* node);
// /*  --  Your TODO   --  */
// std::string printPostorder(BinaryTreeNode* node);
// std::string printInorder(BinaryTreeNode* node);