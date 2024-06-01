#include <string>
#include <iostream>
#include "BinaryTree.h"

#define STEP std::cout << "STEP " << i++ << std::endl;
int i = 1;

int main() {
    STEP // 1. Create a Binary Tree
    BinaryTree christmasTree;

    STEP // 2. Print out all the elements of the binaryTree and its size
    std::cout << "Pre-order traversal (initial): " << christmasTree.preOrder() << "\n";
    std::cout << "Number of elements: " << christmasTree.size() << "\n";

    STEP // 3. Add elements 7, 5, 3, 15, 13, 17, 12, 14, 16, 19 in exactly that sequence
    christmasTree.insert(7);
    christmasTree.insert(5);
    christmasTree.insert(3);
    christmasTree.insert(15);
    christmasTree.insert(13);
    christmasTree.insert(17);
    christmasTree.insert(12);
    christmasTree.insert(14);
    christmasTree.insert(16);
    christmasTree.insert(19);

    STEP // 4. Print out the elements of the binaryTree in pre-order sequence
    std::cout << "Pre-order traversal after insertion: " << christmasTree.preOrder() << "\n";
    std::cout << "Number of elements: " << christmasTree.size() << "\n";

    STEP // 5. Remove element 7
    christmasTree.remove(7);
    STEP // 6. Print out the elements of the binaryTree in pre-order sequence
    std::cout << "Pre-order traversal after removing 7 (a leaf): " << christmasTree.preOrder() << "\n";
    std::cout << "Number of elements: " << christmasTree.size() << "\n";

    STEP // 7. Remove element 17
    christmasTree.remove(17);
    STEP // 8. Print out the elements of the binaryTree in pre-order sequence
    std::cout << "Pre-order traversal after removing 17 (a node with one child): " << christmasTree.preOrder() << "\n";
    std::cout << "Number of elements: " << christmasTree.size() << "\n";

    STEP // 9. Remove element 15
    christmasTree.remove(15);
    STEP // 10. Print out the elements of the binaryTree in pre-order sequence
    std::cout << "Pre-order traversal after removing 15 (a node with two children): " << christmasTree.preOrder() << "\n";
    std::cout << "Number of elements: " << christmasTree.size() << "\n";

    STEP // 11. Print out the elements of the binaryTree in post-order sequence
    std::cout << "Post-order traversal: " << christmasTree.postOrder() << "\n";
    std::cout << "Number of elements: " << christmasTree.size() << "\n";

    STEP // 12. Print out the elements of the binaryTree in in-order sequence
    std::cout << "In-order traversal: " << christmasTree.inOrder() << "\n";
    std::cout << "Number of elements: " << christmasTree.size() << "\n";

    return 0;
}
