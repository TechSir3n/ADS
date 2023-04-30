#include <iostream>
#include "./include/trees/BSTree.hpp"

int main(void) {
    
    BSTree<int> bst;
    bst.insertNode(12);
    bst.insertNode(19);
    bst.insertNode(29);
    bst.insertNode(60);
    bst.erase(19);
    bst.printElements();

    std::cout <<"Count: " << bst.countNodes()<<'\n';

    return 0;
}