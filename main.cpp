#include <iostream>
#include "./include/trees/BSTree.hpp"
#include "./include/trees/AVLTree.hpp"

using namespace ADS;

int main(void) {
    
    BSTree<int> bst;
    bst.insertNode<BSTree<int>>(12);
    bst.insertNode<BSTree<int>>(19);
    bst.insertNode<BSTree<int>>(29);
    
    bst.erase<BSTree<int>>(19);
    bst.printElements();


    AVLTree<int> avl;


    return 0;
}