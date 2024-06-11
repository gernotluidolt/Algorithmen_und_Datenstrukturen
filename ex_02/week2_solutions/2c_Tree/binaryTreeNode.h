#pragma once

class BinaryTreeNode {
    public:
        int key;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        
        BinaryTreeNode(int key);
       
        BinaryTreeNode* insert(int key);
        BinaryTreeNode* deleteItem(int key);
};