#include <iostream>
#include "./include/trees/BSTree.hpp"

int main(void) {
    BSTree<int> bst;
    bst.insertNode(12);
    bst.insertNode(19);
    bst.erase(19);
    bst.printElements();

    return 0;
}