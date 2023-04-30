#include <iostream>
#include "./include/trees/BSTree.hpp"

int main(void) {
    
    BSTree<int> bst;
    bst.insertNode<BSTree<int>>(12);
    bst.insertNode<BSTree<int>>(19);
    bst.insertNode<BSTree<int>>(29);
    
    bst.erase<BSTree<int>>(19);
    bst.printElements();

    return 0;
}